#ifndef CONFIGURATION_HH
#define CONFIGURATION_HH

#include <vector>
#include <string>


struct CuboidConfig {
    std::string Name;
    std::string Shift;
    std::string Scale;
    std::string RotXYZ_deg;
    std::string Trans_m;
    std::string RGB;
};




class Configuration {
    std::vector<std::string> _PluginsLibs;
    std::vector<CuboidConfig> _Cuboids;
    
public:

    void AddPluginLib(const std::string& lib_name) {
        _PluginsLibs.push_back(lib_name);
    }

    const std::vector<std::string>& GetPluginLibs() const {
        return _PluginsLibs;
    }
    
    void AddCuboid(const CuboidConfig& cuboid) {
        _Cuboids.push_back(cuboid);
    }
    
    const std::vector<CuboidConfig>& GetCuboids() const {
        return _Cuboids;
    }
};

#endif
