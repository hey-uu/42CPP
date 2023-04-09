#include "Weapon.hpp"

Weapon::Weapon(std::string const type) : _type(type) {
  std::clog << "[ Weapon ] String constructor called  : ( " << type << " )\n";
}

Weapon::~Weapon(void) {
  std::clog << "[ Weapon ] Default destructor called  : ( " << _type << " )\n";
}

const std::string& Weapon::getType(void) const {
  return (_type);
}

void Weapon::setType(std::string const& newType) {
  _type = newType;
}

std::ostream& operator<<(std::ostream& os, Weapon const& weapon) {
  os << weapon.getType();
  return (os);
}
 