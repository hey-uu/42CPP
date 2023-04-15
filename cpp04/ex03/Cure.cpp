#include "Cure.hpp"
#include "ICharacter.hpp"
#include "debug_msg.hpp"
#include <iostream>

Cure::Cure(void) : AMateria("cure") {
  debug::printCure();
  debug::debugMsg(debug::kDefaultConstructor);
}

Cure::Cure(Cure const &other) : AMateria(other._type) {
  debug::printCure();
  debug::debugMsg(debug::kCopyConstructor);
}

Cure &Cure::operator=(Cure const &other) {
  debug::printCure();
  debug::debugMsg(debug::kAssignOperator);
  if (this != &other)
    _type = other._type;
  return (*this);
}

Cure::~Cure(void) {
  debug::printCure();
  debug::debugMsg(debug::kDestructor);
}

AMateria *Cure::clone() const { return (new Cure); }

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
