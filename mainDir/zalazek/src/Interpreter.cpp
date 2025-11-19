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
                std::string ObjName;
                
                // Tylko dla Pause nie ma nazwy obiektu
                if (CmdName != "Pause") {
                    cmd_stream >> ObjName;
                }
                
                if (pCmd->ReadParams(cmd_stream)) {
                    std::cout << "Wykonywanie polecenia: ";
                    pCmd->PrintCmd();
                    std::cout << std::endl;
                    
                    // Przekaż nazwę obiektu do ExecCmd
                    pCmd->ExecCmd(_scene, ObjName.c_str(), _channel);
                    
                } else {
                    std::cerr << "Blad wczytywania parametrow dla polecenia: " << CmdName << std::endl;
                    std::string line; 
                    getline(cmd_stream, line);
                }
                delete pCmd;
            }
        } else {
            std::cout << "Pominieto nieznane polecenie: " << CmdName << std::endl;
            std::string line; 
            getline(cmd_stream, line);
        }
    }
    std::cout << "--- Koniec interpretacji ---" << std::endl;
}