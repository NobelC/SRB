cmake_minimum_required(VERSION 3.25)
project(SRB CXX VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)


set(SIMDJSON_JUST_LIBRARY ON CACHE INTERNAL "")
set(SIMDJSON_DEVELOPER_MODE OFF CACHE INTERNAL "")

fetchcontent_declare(
  simdjson
  GIT_REPOSITORY https://github.com/simdjson/simdjson.git
  GIT_TAG v3.11.0
  GIT_SHALLOW TRUE
)

fetchcontent_makeavailable(simdjson)


add_executable(SRB 
    src/main.cpp 
    src/configuration/create-configuration-dir.cpp
    src/configuration/create-configuration-file.cpp
    src/configuration/create-default-configuration.cpp
    src/utilities/get_trash_dir.cpp 
)
find_package(nlohmann_json REQUIRED)
target_include_directories(SRB PRIVATE include)
target_link_libraries(SRB PRIVATE simdjson nlohmann_json::nlohmann_json)
target_compile_options(SRB PRIVATE -Wall -Wextra -Wpedantic)

