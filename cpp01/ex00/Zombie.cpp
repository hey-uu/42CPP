#include "Zombie.hpp"

Zombie::Zombie(void) {
  std::clog << "[ DEBUG ] Default constructor called\n";
}

Zombie::Zombie(std::string name) : name(name) {
  std::clog << "[ DEBUG ] " << name << ": String constructor called\n";
}

Zombie::~Zombie(void) {
  std::clog << "[ DEBUG ] " << name << ": Destructor called\n";
}

void Zombie::announce(void) {
  std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
