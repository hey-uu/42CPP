#include "debug_msg.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iomanip>
#include <iostream>

AMateria::AMateria(void) : _type("") {
  debug::printAMateria();
  debug::debugMsg(debug::kDefaultConstructor);
}

AMateria::AMateria(std::string const &type) : _type(type) {
  debug::printAMateria();
  debug::debugMsg(debug::kStringConstructor);
}

AMateria::AMateria(AMateria const &other) : _type(other._type) {
  debug::printAMateria();
  debug::debugMsg(debug::kCopyConstructor);
}

AMateria &AMateria::operator=(AMateria const &other) {
  debug::printAMateria();
  debug::debugMsg(debug::kAssignOperator);
  if (this != &other)
    _type = other._type;
  return (*this);
}

AMateria::~AMateria(void) {
  debug::printAMateria();
  debug::debugMsg(debug::kDestructor);
}

std::string const &AMateria::getType() const { return (_type); }

void AMateria::use(ICharacter &target) {
  debug::printAMateria();
  std::cout << "* uses something to " << target.getName() << std::endl;
}
