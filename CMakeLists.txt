cmake_minimum_required(VERSION 3.14)
project(srb CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

fetchcontent_declare(
  simdjson
  GIT_REPOSITORY https://github.com/simdjson/simdjson.git
  GIT_TAG v3.10.1
  GIT_SHALLOW TRUE
)

set(SIMDJSON_JUST_LIBRARY ON CACHE INTERNAL "")
fetchcontent_makeavailable(simdjson)

add_executable(SRB src/main.cpp)
target_link_libraries(SRB PRIVATE simdjson::simdjson)


