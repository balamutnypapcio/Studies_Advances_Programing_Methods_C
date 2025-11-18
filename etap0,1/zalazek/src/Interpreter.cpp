#include "Interpreter.hh"

Interpreter::Interpreter(std::map<std::string, LibInterface*>& plugins, ComChannel& channel, Scene& scene)
    : _Plugins(plugins), _channel(channel), _scene(scene)
{}

void Interpreter::Exec(std::istream& cmd_stream) {
    std::cout << "--- Rozpoczynam interpretacje polecen ---" << std::endl;
    std::string CmdName;

    while (cmd_stream >> CmdName) {
        auto it = _Plugins.find(CmdName);
        if (it != _Plugins.end() && it->second->IsValid()) {
            AbstractInterp4Command* pCmd = it->second->CreateCmd();
            if (pCmd) {
                if (pCmd->ReadParams(cmd_stream)) {
                    std::cout << "Wykonywanie polecenia: ";
                    pCmd->PrintCmd();
                    std::cout << std::endl;
                    
                    pCmd->ExecCmd(_scene, "DUMMY_NAME", _channel);
                } else {
                    std::cerr << "Blad wczytywania parametrow dla polecenia: " << CmdName << std::endl;
                    std::string line; 
                    getline(cmd_stream, line); // Pomiń resztę błędnej linii
                }
                delete pCmd;
            }
        } else {
            std::cout << "Pominieto nieznane polecenie: " << CmdName << std::endl;
            std::string line; 
            getline(cmd_stream, line); // Pomiń resztę linii
        }
    }
    
    std::cout << "--- Koniec interpretacji ---" << std::endl;
}
