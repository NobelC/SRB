#pragma once 
#include <nlohmann/json_fwd.hpp>
#include <string>

namespace srb_configuration{
  std::string create_configuration_dir();
  std::string create_configuration_file();
  nlohmann::json create_default_configuration();
}
