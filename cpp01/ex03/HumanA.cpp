#include "HumanA.hpp"

HumanA::HumanA(std::string const& name, Weapon& weapon)
    : _name(name), _weapon(weapon) {
  std::cerr << "[ HumanA ] Complex constructor called : " << *this << "\n";
}

HumanA::~HumanA(void) {
  std::cerr << "[ HumanA ] Default destructor called  : " << *this << "\n";
}

void HumanA::attack(void) const {
  std::cout << _name << " attacks with their " << _weapon << "\n";
}

void HumanA::setWeapon(Weapon const& weapon) {
  _weapon = weapon;
}

std::string const& HumanA::getName(void) const {
  return (_name);
}

Weapon const& HumanA::getWeapon(void) const {
  return (_weapon);
}

std::ostream& operator<<(std::ostream& os, HumanA const& human) {
  os << "( " << human.getName() << ", " << human.getWeapon() << " )";
  return (os);
}
