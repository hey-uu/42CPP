#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iomanip>
#include <iostream>
#include "debug_msg.hpp"

ICharacter::ICharacter(void) : _name("") {
  debug::printICharacter();
  debug::debugMsg(debug::kDefaultConstructor);
}

ICharacter::ICharacter(std::string const &name) : _name(name) {
  debug::printICharacter();
  debug::debugMsg(debug::kStringConstructor);
}

ICharacter::ICharacter(ICharacter const &other) : _name(other._name) {
  debug::printICharacter();
  debug::debugMsg(debug::kCopyConstructor);
}

ICharacter &ICharacter::operator=(ICharacter const &other) {
  debug::printICharacter();
  debug::debugMsg(debug::kAssignOperator);
  _name = other._name;
  return (*this);
}

ICharacter::~ICharacter(void) {
  debug::printICharacter();
  debug::debugMsg(debug::kDestructor);
}

void ICharacter::showName(void) const {
  std::cout << std::setw(10) << std::left << "( " + _name + " ) ";
}