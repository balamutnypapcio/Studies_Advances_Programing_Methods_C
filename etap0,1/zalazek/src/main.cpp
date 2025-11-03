#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include "LibInterface.hh"
#include "preprocessor.hh"

using namespace std;

int main()
{
    // --- Krok 1: Przetwarzanie pliku przez preprocesor ---
    string processed_content = PreprocessFile("polecenia.txt");
    if (processed_content.empty()) {
        cout << "Plik polecen jest pusty lub wystapil blad preprocesora." << endl;
        return 1;
    }
    stringstream CmdStream(processed_content);

    cout << "--- Plik po przetworzeniu przez preprocesor ---" << endl;
    cout << processed_content << endl;
    cout << "---------------------------------------------\n" << endl;

    // --- Krok 2: Mapa wtyczek (z surowymi wskaźnikami dla bezpieczeństwa) ---
    map<string, LibInterface*> Plugins;
    Plugins["Move"]   = new LibInterface("libs/libInterp4Move.so");
    Plugins["Rotate"] = new LibInterface("libs/libInterp4Rotate.so");
    Plugins["Set"]    = new LibInterface("libs/libInterp4Set.so");
    Plugins["Pause"]  = new LibInterface("libs/libInterp4Pause.so");

    
    // --- Krok 3: Główna pętla interpretera ---
    cout << "--- Rozpoczynam interpretacje polecen ---" << endl;
    string CmdName;

    while (CmdStream >> CmdName) {
        
        auto it = Plugins.find(CmdName); // Wyszukaj polecenie w mapie

        if (it != Plugins.end() && it->second->IsValid()) {
            // Znaleziono wtyczkę i jest ona poprawna
            AbstractInterp4Command* pCmd = it->second->CreateCmd();
            if (pCmd) {
                if (pCmd->ReadParams(CmdStream)) {
                    cout << "Wczytano polecenie: ";
                    pCmd->PrintCmd();
                    cout << endl;
                } else {
                    cout << "Błąd wczytywania parametrów dla polecenia: " << CmdName << endl;
                    delete pCmd;    // Ważne: zwolnij pamięć nawet w razie błędu
                    break;       // Przerwij pętlę, bo strumień jest uszkodzony
                }
                delete pCmd; // Zwolnij pamięć po obiekcie polecenia
            }
        } else {
            // Nie znaleziono wtyczki w mapie, lub była niepoprawnie załadowana
            cout << "Pominięto nieznane/niepoprawne polecenie: " << CmdName << endl;
            // "Zjedz" resztę linii, aby zsynchronizować strumień.
            // getline czyta do znaku nowej linii, którego w stringstream nie ma,
            // więc przeczyta wszystko do końca. W tej pętli to zachowanie jest akurat pożądane.
            string dummy;
            getline(CmdStream, dummy);
        }
    }
    
    cout << "--- Koniec interpretacji ---" << endl;

    // --- Krok 4: Ręczne i bezpieczne zwolnienie zasobów ---
    for (auto& pair : Plugins) {
        delete pair.second; // To wywoła destruktor ~LibInterface(), który zrobi dlclose()
    }

    return 0;
}