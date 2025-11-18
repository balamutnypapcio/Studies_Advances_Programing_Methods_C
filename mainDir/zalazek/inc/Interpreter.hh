#ifndef INTERPRETER_HH
#define INTERPRETER_HH

#include <string>
#include <map>
#include <iostream>
#include "LibInterface.hh"
#include "ComChannel.hh"
#include "AbstractScene.hh"
#include "Scene.hh"

class Interpreter {
private:
    std::map<std::string, LibInterface*>& _Plugins;
    ComChannel& _channel;
    Scene& _scene; // Nawet jeśli to atrapa, przekazujemy ją dalej

public:
    // Konstruktor przyjmuje "narzędzia", których będzie używać
    Interpreter(std::map<std::string, LibInterface*>& plugins, ComChannel& channel, Scene& scene);

    // Główna metoda wykonawcza
    void Exec(std::istream& cmd_stream);
};

#endif