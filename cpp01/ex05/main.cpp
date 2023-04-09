#include "Harl.hpp"

int main(void) {
  std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR",
                          "THIS IS STRANGE"};
  Harl harl;

  for (int i = 0; i < 5; i++) {
    std::cout << "INPUT : " << levels[i] << "\n";
    harl.complain(levels[i]);
  }
  return (0);
}