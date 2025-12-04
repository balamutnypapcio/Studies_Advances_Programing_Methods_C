#include "Interpreter.hh"
#include <vector>
#include <thread>

Interpreter::Interpreter(std::map<std::string, LibInterface*>& plugins, ComChannel& channel, Scene& scene)
    : _Plugins(plugins), _channel(channel), _scene(scene)
{}

void Interpreter::Exec(std::istream& cmd_stream) {
    std::string Keyword;
    while (cmd_stream >> Keyword) {
        if (Keyword == "Begin_Parallel_Actions") {
            std::cout << "--- Rozpoczynam nowy blok polecen rownoleglych ---" << std::endl;
            std::vector<AbstractInterp4Command*> commands;
            std::vector<std::string> objNames;

            while ((cmd_stream >> Keyword) && (Keyword != "End_Parallel_Actions")) {
                auto it = _Plugins.find(Keyword);
                if (it != _Plugins.end()) {
                    AbstractInterp4Command* pCmd = it->second->CreateCmd();
                    std::string ObjName;
                    if (Keyword != "Pause") {
                        cmd_stream >> ObjName;
                    }
                    if (pCmd->ReadParams(cmd_stream)) {
                        commands.push_back(pCmd);
                        objNames.push_back(ObjName);
                    } else {
                        std::cerr << "Blad wczytywania parametrow dla: " << Keyword << std::endl;
                        delete pCmd;
                    }
                }
            }

            std::vector<std::thread> threads;
            for (size_t i = 0; i < commands.size(); ++i) {
                std::cout << "  Uruchamiam watek dla polecenia: " << commands[i]->GetCmdName() << std::endl;
                threads.emplace_back(
                    [this, pCmd = commands[i], objName = objNames[i]]() {
                        pCmd->ExecCmd(this->_scene, objName.c_str(), this->_channel);
                        delete pCmd;
                    }
                );
            }
            
            std::cout << "  Czekam na zakonczenie wszystkich watkow..." << std::endl;
            for (std::thread& thr : threads) {
                if (thr.joinable()) thr.join();
            }
            std::cout << "--- Blok polecen rownoleglych zakonczony ---\n" << std::endl;

        } else {
             std::cerr << "Blad skladni: Oczekiwano 'Begin_Parallel_Actions', a znaleziono '" << Keyword << "'" << std::endl;
             return;
        }
    }
}