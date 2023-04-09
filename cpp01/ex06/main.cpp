#include "Harl.hpp"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "[ ERROR ] Arguments must be './<program_name> <log_level>'\n";
    return (1);
  }
  Harl harl;
  harl.filterComplains(argv[1]);
  return (0);
}
