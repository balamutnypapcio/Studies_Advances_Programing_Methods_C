#include "AbstractComChannel.hh"

// Definicja wirtualnego destruktora.
// Mimo że jest pusty, jego obecność w pliku .cpp
// jest sygnałem dla kompilatora, aby wygenerował tutaj vtable.
AbstractComChannel::~AbstractComChannel() {}

// Dajemy pustą implementację dla UseGuard, aby uniknąć błędów
// w przyszłości, jeśli ktoś spróbuje ją wywołać na wskaźniku do klasy bazowej.
std::mutex& AbstractComChannel::UseGuard() {
    // Ta implementacja nigdy nie powinna być wywołana.
    // Zwracamy statyczny mutex, aby spełnić wymagania sygnatury.
    static std::mutex dummy_mutex;
    return dummy_mutex;
}