#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <unistd.h>

#include "Configuration.hh"
#include "LibInterface.hh"
#include "preprocessor.hh"
#include "ComChannel.hh"
#include "Port.hh"
#include "Interpreter.hh"
#include "Scene.hh"


using namespace std;






int main() 
{
    // === FAZA 1: INICJALIZACJA ===
    // Wczytujemy całą konfigurację z pliku XML do obiektu 'config'.
    // Ten obiekt będzie naszym źródłem informacji o wtyczkach i obiektach.
    Configuration config;
    cout << "--- Faza 1: Wczytywanie konfiguracji z config/config.xml ---" << endl;
    if (!config.LoadFromFile("config/config.xml")) {
        cerr << "!!! Blad krytyczny: Nie udalo sie wczytac pliku konfiguracyjnego." << endl;
        return 1;
    }

    // Tworzymy obiekt kanału komunikacyjnego i łączymy się z serwerem graficznym.
    ComChannel channel;
    if (!channel.Connect("127.0.0.1", PORT)) {
        return 1;
    }


    // === FAZA 2: BUDOWA SCENY ===
    // Na podstawie danych wczytanych z XML, budujemy początkowy stan sceny na serwerze.
    cout << "\n--- Faza 2: Wysylanie poczatkowej konfiguracji sceny do serwera ---" << endl;
    channel.Send("Clear\n"); // Zawsze czyścimy scenę na starcie na wypadek poprzednich uruchomień.

    // --- UZUPEŁNIONA PĘTLA DLA OBIEKTÓW ---
    const vector<CuboidConfig>& cuboids = config.GetCuboids();
    for (const CuboidConfig& cuboid_data : cuboids) {
        stringstream cmd_stream;
        // Budujemy polecenie AddObj zgodnie z formatem wymaganym przez serwer
        cmd_stream << "AddObj Name=" << cuboid_data.Name
                << " Shift={" << cuboid_data.Shift << "}"
                << " Scale={" << cuboid_data.Scale << "}"
                << " RotXYZ_deg={" << cuboid_data.RotXYZ_deg << "}"
                << " Trans_m={" << cuboid_data.Trans_m << "}"
                << " RGB={" << cuboid_data.RGB << "}\n";
                
        cout << "  Wysylanie: " << cmd_stream.str();
        channel.Send(cmd_stream.str());
    }
    usleep(200000); // Dajemy serwerowi chwilę na narysowanie wszystkiego


    // === FAZA 3: ŁADOWANIE NARZĘDZI (WTYCZEK) ===
    // Dynamicznie ładujemy wszystkie wtyczki zdefiniowane w XML.
    map<string, LibInterface*> Plugins;
    cout << "\n--- Faza 3: Ladowanie wtyczek ---" << endl;

    //Nazwy wtyczek bedą trzymane w wektorze lib_names
    const vector<string>& lib_names = config.GetPluginLibs();
    for (const string& lib_name : lib_names) {
        string full_path = "libs/" + lib_name;
        LibInterface* pLib = new LibInterface(full_path.c_str());
        if (pLib->IsValid()) {
            Plugins[pLib->GetCmdName()] = pLib;
            cout << "  Zaladowano wtyczke dla polecenia: " << pLib->GetCmdName() << endl;
        } else {
            // Jeśli wtyczki nie udało się załadować, zwalniamy pamięć i kontynuujemy.
            delete pLib;
        }
    }


    // === FAZA 4: PRZYGOTOWANIE DANYCH WEJŚCIOWYCH ===
    // Przetwarzamy plik z poleceniami za pomocą preprocesora C.
    cout << "\n--- Faza 4: Przetwarzanie pliku polecenia.txt ---" << endl;
    string processed_content = PreprocessFile("polecenia.txt");
    if (processed_content.empty()) {
        cerr << "!!! Blad: Plik polecen jest pusty lub wystapil blad preprocesora." << endl;
        // Sprzątanie przed wyjściem
        for (auto& pair : Plugins) delete pair.second;
        channel.Disconnect();
        return 1;
    }
    stringstream CmdStream(processed_content);
    

    // === FAZA 5: URUCHOMIENIE GŁÓWNEJ LOGIKI ===
    // Tworzymy obiekt interpretera i przekazujemy mu wszystkie potrzebne narzędzia.
    cout << "\n--- Faza 5: Uruchomienie interpretera polecen ---" << endl;
    Scene scene; // Tworzymy atrapę sceny
    Interpreter interpreter(Plugins, channel, scene);
    interpreter.Exec(CmdStream); // Uruchamiamy główną pętlę


    // === FAZA 6: SPRZĄTANIE ===
    // Po zakończeniu pracy, zwalniamy wszystkie zaalokowane zasoby.
    cout << "\n--- Faza 6: Zwalnianie zasobow ---" << endl;
    for (auto& pair : Plugins) {
        delete pair.second; // Wywołuje destruktor LibInterface, który robi dlclose()
    }
    channel.Disconnect(); // Wywołuje destruktor ComChannel, który wysyła "Close" i zamyka gniazdo

    cout << "\nProgram zakonczyl dzialanie." << endl;
    return 0;
}