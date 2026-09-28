#include <cstdint>
#include <iostream>
#include "simdjson.h"
#include "SRB/create-configuration-SRB.hpp"

int main (int argc, char *argv[]) {
  const auto& file = srb_configuration::create_configuration_file();
  return 0;
}
