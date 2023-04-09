#include "Zombie.hpp"

Zombie::Zombie(void) {
  std::clog << "[ DEBUG ] Default constructor called\n";
}

Zombie::Zombie(std::string name) : _name(name) {
  std::clog << "[ DEBUG ] " << _name << "String constructor called\n";
}

Zombie::~Zombie(void) {
  std::clog << "[ DEBUG ] " << _name << ": Destructor called\n";
}

void Zombie::announce(void) const {
  std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string const& name) {
  _name = name;
  std::clog << "[ DEBUG ] " << name << ": Member function setName called\n";
}