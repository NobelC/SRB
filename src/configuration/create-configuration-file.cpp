#include "SRB/create-configuration-SRB.hpp"
#include <filesystem>
#include <fstream>
#include <nlohmann/json.hpp>

namespace srb_configuration{
  std::string create_configuration_file(){
    std::string configuration_file = create_configuration_dir();
    configuration_file.append("configuration.json");
    std::filesystem::path path = configuration_file;
    if(!std::filesystem::exists(path)){
      std::ofstream file(configuration_file);
      if (file.is_open()){
        nlohmann::json content = create_default_configuration();
        file << content.dump(2);
      }
    }
    return configuration_file;
  }
}
