#include "preprocessor.hh"
#include <iostream>
#include <sstream>
#include <memory>
#include <cstdio>

std::string PreprocessFile(const std::string& filename) {
    std::string command = "cpp -E -P " + filename; // -P usuwa dodatkowe informacje z preprocesora
    std::stringstream output_stream;

    // Użycie popen do uruchomienia preprocesora
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(command.c_str(), "r"), pclose);

    if (!pipe) {
        std::cerr << "!!! Błąd: Nie udało się uruchomić preprocesora dla pliku: " << filename << std::endl;
        return ""; // Zwróć pusty string w razie błędu
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), pipe.get()) != nullptr) {
        output_stream << buffer;
    }

    return output_stream.str();
}