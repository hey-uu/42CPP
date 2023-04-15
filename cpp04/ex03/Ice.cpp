#include "Ice.hpp"
#include "ICharacter.hpp"
#include "debug_msg.hpp"
#include <iostream>

Ice::Ice(void) : AMateria("ice") {
  debug::printIce();
  debug::debugMsg(debug::kDefaultConstructor);
}

Ice::Ice(Ice const &other) : AMateria(other._type) {
  debug::printIce();
  debug::debugMsg(debug::kCopyConstructor);
}

Ice &Ice::operator=(Ice const &other) {
  debug::printIce();
  debug::debugMsg(debug::kAssignOperator);
  if (this != &other)
    _type = other._type;
  return (*this);
}

Ice::~Ice(void) {
  debug::printIce();
  debug::debugMsg(debug::kDestructor);
}

AMateria *Ice::clone() const { return (new Ice(*this)); }

void Ice::use(ICharacter &target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}
