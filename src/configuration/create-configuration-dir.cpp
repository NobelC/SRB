#include "SRB/create-configuration-SRB.hpp"
#include<cstdlib>
#include <filesystem>

namespace srb_configuration {
  std::string create_configuration_dir(){
    std::string home_path_dir = getenv("HOME");
    if(!home_path_dir.ends_with('/')){
      home_path_dir.append("/");
    }
    home_path_dir.append(".config/SRB/");
    std::filesystem::path path = home_path_dir;

    if(!std::filesystem::exists(path)){
      std::filesystem::create_directory(home_path_dir);
    }

    return home_path_dir;
  }
}
