#include <iostream>
#include "LibInterface.hh"

LibInterface::LibInterface(const char* sLibFileName) {

    _LibHandler = dlopen(sLibFileName, RTLD_LAZY);


    if (!_LibHandler) {
        std::cerr << "!!! Brak biblioteki: " << sLibFileName << std::endl;
        std::cerr << "    " << dlerror() << std::endl;
        _pCreateCmd = nullptr;
        return;
    }


    void* pFunGetName = dlsym(_LibHandler, "GetCmdName");
    if (!pFunGetName) {
        std::cerr << "!!! Nie znaleziono funkcji GetCmdName w " << sLibFileName << std::endl;
        _pCreateCmd = nullptr;
        dlclose(_LibHandler);
        _LibHandler = nullptr;
        return;
    }
    const char* (*pGetCmdName)() = reinterpret_cast<const char* (*)()>(pFunGetName);
    _CmdName = pGetCmdName();


    void* pFun = dlsym(_LibHandler, "CreateCmd");
    if (!pFun) {
        std::cerr << "!!! Nie znaleziono funkcji CreateCmd w " << sLibFileName << std::endl;
        _pCreateCmd = nullptr;
        return;
    }
    _pCreateCmd = reinterpret_cast<AbstractInterp4Command* (*)(void)>(pFun);
}

LibInterface::~LibInterface() {
    if (_LibHandler) {
        dlclose(_LibHandler);
    }
}

AbstractInterp4Command* LibInterface::CreateCmd() const {
    if (IsValid()) {
        return _pCreateCmd();
    }
    return nullptr;
}