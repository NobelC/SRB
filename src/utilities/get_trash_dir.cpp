#include "SRB/utilities/get_trash_dir.hpp"
#include <cstdlib>
#include <filesystem>

namespace srb::utilities {
  std::filesystem::path get_linux_trash_path(){
    const char* xgd_data_home = std::getenv("XDG_DATA_HOME");
    std::filesystem::path trash_path;
    if(xgd_data_home && *xgd_data_home != '\0'){
      trash_path = std::filesystem::path(xgd_data_home) / "Trash";
    }
    else{
      const char* home = std::getenv("HOME");
      trash_path = std::filesystem::path(home) / ".local/share/Trash";
    }
    return trash_path;
  }
}
