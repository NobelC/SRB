#include "SRB/create-configuration-SRB.hpp"
#include "SRB/utilities/get_trash_dir.hpp"
#include <nlohmann/json.hpp>
#include <filesystem>

namespace srb_configuration {
  nlohmann::json create_default_configuration(){
    std::filesystem::path default_path = srb::utilities::get_linux_trash_path();
    nlohmann::json default_configuration; 
    return default_configuration[default_path.string()]["clear"] = "all";
  }
}
