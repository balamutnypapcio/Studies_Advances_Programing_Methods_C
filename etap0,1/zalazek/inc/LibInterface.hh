#ifndef LIBINTERFACE_HH
#define LIBINTERFACE_HH

#include <string>
#include <dlfcn.h>
#include "AbstractInterp4Command.hh"

class LibInterface {
    void*       _LibHandler;   // Uchwyt do biblioteki (z dlopen)
    AbstractInterp4Command* (*_pCreateCmd)(void); // Wskaźnik na funkcję CreateCmd

public:
    // Konstruktor
    LibInterface(const char* sLibFileName);

    // Destruktor zwalniający bibliotekę
    ~LibInterface();

    // Metoda do tworzenia instancji polecenia
    AbstractInterp4Command* CreateCmd() const;
    
    // Sprawdza, czy wtyczka została poprawnie załadowana
    bool IsValid() const { return _pCreateCmd != nullptr; }
};

#endif