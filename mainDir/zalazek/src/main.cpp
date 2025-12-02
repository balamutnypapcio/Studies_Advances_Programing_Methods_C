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


#include <libgen.h> // Potrzebne do dirname()
#include <linux/limits.h> // Potrzebne do PATH_MAX

using namespace std;



//Ta funkcja zwraca pełną ścieżkę do katalogu, w którym znajduje się plik wykonywalny
string getExecutableDir() {
    char result[PATH_MAX];
    ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
    if (count != -1) {
        return dirname(result);
    }
    return "."; // Zwróć bieżący katalog w razie błędu
}


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
    cout << "\n--- Faza 2: Wysylanie poczatkowej konfiguracji sceny do serwera ---" << endl;
    channel.Send("Clear\n");

    const std::vector<CuboidConfig>& cuboids = config.GetCuboids();
    for (const CuboidConfig& cuboid_data : cuboids) {
        stringstream cmd_stream;
        cmd_stream << "AddObj Name=" << cuboid_data.Name;

        auto format_vector = [](const std::string& input) {
            std::stringstream ss(input);
            double v1, v2, v3;
            ss >> v1 >> v2 >> v3;
            std::stringstream out;
            out << "(" << v1 << "," << v2 << "," << v3 << ")";
            return out.str();
        };

        // Sprawdzamy, czy atrybuty nie są puste, zanim je dodamy
        if (!cuboid_data.Shift.empty()) cmd_stream << " Shift=" << format_vector(cuboid_data.Shift);
        if (!cuboid_data.Scale.empty()) cmd_stream << " Scale=" << format_vector(cuboid_data.Scale);
        if (!cuboid_data.RotXYZ_deg.empty()) cmd_stream << " RotXYZ_deg=" << format_vector(cuboid_data.RotXYZ_deg);
        if (!cuboid_data.Trans_m.empty()) cmd_stream << " Trans_m=" << format_vector(cuboid_data.Trans_m);
        if (!cuboid_data.RGB.empty()) cmd_stream << " RGB=" << format_vector(cuboid_data.RGB);
        
        cmd_stream << "\n";
        // --- KONIEC NOWEJ LOGIKI ---
        
        cout << "  Wysylanie: " << cmd_stream.str();
        channel.Send(cmd_stream.str());
    }
    usleep(1000); // Dajemy serwerowi chwilę na narysowanie wszystkiego

    // --- FAZA 2b: Tworzenie lokalnej reprezentacji sceny ---
    Scene scene;
    cout << "\n--- Faza 2b: Tworzenie lokalnej reprezentacji sceny ---" << endl;
    for (const auto& cuboid_data : cuboids) {
        auto pObj = std::make_shared<MobileObj>(cuboid_data.Name);
        scene.AddMobileObj(pObj);
        cout << "  Stworzono lokalny obiekt: " << cuboid_data.Name << endl;
    }    

    // === FAZA 3: ŁADOWANIE NARZĘDZI (WTYCZEK) ===
    // Dynamicznie ładujemy wszystkie wtyczki zdefiniowane w XML.
    map<string, LibInterface*> Plugins;
    cout << "\n--- Faza 3: Ladowanie wtyczek ---" << endl;

// --- KLUCZOWA ZMIANA JEST TUTAJ ---
    string exec_dir = getExecutableDir(); // Pobierz ścieżkę do programu, np. "/home/jakub/.../zalazek/build"
    //cout << "  Katalog wykonywalny: " << exec_dir << endl;
    
    const vector<string>& lib_names = config.GetPluginLibs();
    for (const string& lib_name : lib_names) {
        // Budujemy PEŁNĄ, BEZWZGLĘDNĄ ścieżkę do wtyczki
        string full_path = exec_dir + "/libs/" + lib_name;
        cout << "  Proba ladowania: " << full_path << endl;
        
        LibInterface* pLib = new LibInterface(full_path.c_str());

        if (pLib->IsValid()) {
            Plugins[pLib->GetCmdName()] = pLib;
            cout << "  Zaladowano wtyczke dla polecenia: " << pLib->GetCmdName() << endl;
        } else {
            delete pLib;
        }
    }


    // === FAZA 4: PRZYGOTOWANIE DANYCH WEJŚCIOWYCH ===
    // Przetwarzamy plik z poleceniami za pomocą preprocesora C.
    cout << "\n--- Faza 4: Przetwarzanie pliku polecenia.txt ---" << endl;
    string processed_content = PreprocessFile("polecenia_etap_3.txt");
    if (processed_content.empty()) {
        cerr << "!!! Blad: Plik polecen jest pusty lub wystapil blad preprocesora." << endl;
        // Sprzątanie przed wyjściem
        for (auto& pair : Plugins) delete pair.second;
        channel.Disconnect();
        return 1;
    }
    std::cout << "=== PRZETWORZONY PLIK ===" << std::endl;
    std::cout << processed_content << std::endl;
    std::cout << "=========================" << std::endl;
    stringstream CmdStream(processed_content);
    

    // === FAZA 5: URUCHOMIENIE GŁÓWNEJ LOGIKI ===
    // Tworzymy obiekt interpretera i przekazujemy mu wszystkie potrzebne narzędzia.
    cout << "\n--- Faza 5: Uruchomienie interpretera polecen ---" << endl;
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