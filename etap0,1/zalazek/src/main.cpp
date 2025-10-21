#include <iostream>
#include <sstream>
#include "LibInterface.hh"
#include "preprocessor.hh"

using namespace std;

int main()
{
    // --- Krok 1: Przetwarzanie pliku przez preprocesor ---
    string processed_content = PreprocessFile("polecenia.txt");
    stringstream CmdStream(processed_content); // Tworzymy strumień ze stringa

    cout << "--- Plik po przetworzeniu przez preprocesor ---" << endl;
    cout << processed_content << endl;
    cout << "---------------------------------------------\n" << endl;


    // --- Krok 2: Przygotowanie interfejsów do wtyczek ---
    LibInterface MoveInterface("libs/libInterp4Move.so");
    LibInterface RotateInterface("libs/libInterp4Rotate.so");
    // W przyszłości tutaj będą też interfejsy dla Set i Pause

    
    // --- Krok 3: Główna pętla interpretera ---
    cout << "--- Rozpoczynam interpretacje polecen ---" << endl;
    string CmdName;
    AbstractInterp4Command* pCmd = nullptr;

    while (CmdStream >> CmdName) { // Czytaj słowo po słowie, dopóki są słowa
        
        if (CmdName == "Move") {
            pCmd = MoveInterface.CreateCmd();
        } else if (CmdName == "Rotate") {
            pCmd = RotateInterface.CreateCmd();
        } else {
            // Obsługa nieznanych poleceń
            cout << "Nieznane polecenie: " << CmdName << endl;
            // Wczytaj resztę linii, żeby przeskoczyć parametry
            string dummy;
            getline(CmdStream, dummy); 
            continue; // Przejdź do następnej iteracji pętli
        }

        if (pCmd) {
            if (pCmd->ReadParams(CmdStream)) {
                cout << "Wczytano polecenie: ";
                pCmd->PrintCmd();
                cout << endl;
            } else {
                cout << "Błąd wczytywania parametrów dla polecenia: " << CmdName << endl;
            }
            delete pCmd; // Zwolnij pamięć po obiekcie polecenia
        }
    }
    cout << "--- Koniec interpretacji ---" << endl;
    
    return 0;
}