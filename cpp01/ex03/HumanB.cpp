#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {
  std::cerr << "[ HumanB ] String constructor called  : " << *this << "\n";
}

HumanB::~HumanB(void) {
  std::cerr << "[ HumanB ] Default destructor called  : " << *this << "\n";
}

void HumanB::attack(void) const {
  std::cout << _name << " attacks with their " << *_weapon << "\n";
}

void HumanB::setWeapon(Weapon& weapon) {
  _weapon = &weapon;
}

std::string const& HumanB::getName(void) const {
  return (_name);
}

bool HumanB::hasWeapon(void) const {
  return ((_weapon != NULL));
}

Weapon const& HumanB::getWeapon(void) const {
  return (*_weapon);
}

std::ostream& operator<<(std::ostream& os, HumanB const& human) {
  if (human.hasWeapon())
    os << "( " << human.getName() << ", " << human.getWeapon() << " )";
  else
    os << "( " << human.getName() << ", )";
  return (os);
}
