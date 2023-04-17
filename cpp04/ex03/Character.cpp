#include "Character.hpp"
#include "AMateria.hpp"
#include "debug_msg.hpp"
#include <iomanip>
#include <iostream>

Character::Character(void) : ICharacter() {
  debug::printCharacter();
  debug::debugMsg(debug::kDefaultConstructor);
  for (int idx = 0; idx < _kCap; idx++)
    _invent[idx] = NULL;
}

Character::Character(std::string const &name) : ICharacter(name) {
  debug::printCharacter();
  debug::debugMsg(debug::kStringConstructor);
  for (int idx = 0; idx < _kCap; idx++)
    _invent[idx] = NULL;
}

Character::Character(Character const &other) : ICharacter(other) {
  debug::printCharacter();
  debug::debugMsg(debug::kCopyConstructor);
  for (int idx = 0; idx < _kCap; idx++) {
    _invent[idx] = (!other._invent[idx]) ? NULL : other._invent[idx]->clone();
  }
}

Character &Character::operator=(Character const &other) {
  debug::printCharacter();
  debug::debugMsg(debug::kAssignOperator);
  if (this == &other)
    return (*this);
  for (int idx = 0; idx < _kCap; idx++) {
    if (_invent[idx])
      delete _invent[idx];
    _invent[idx] = (!other._invent[idx]) ? NULL : other._invent[idx]->clone();
  }
  return (*this);
}

Character::~Character(void) {
  debug::printCharacter();
  debug::debugMsg(debug::kDestructor);
  for (int idx = 0; idx < 4; idx++) {
    if (_invent[idx])
      delete _invent[idx];
    _invent[idx] = NULL;
  }
}

std::string const &Character::getName(void) const { return (_name); };

void Character::equip(AMateria *m) {
  debug::printCharacter();
  if (m == NULL) {
    std::cout << "! The argument must not be NULL pointer !" << std::endl;
    return;
  }
  showName();
  for (int idx = 0; idx < _kCap; idx++) {
    if (_invent[idx] == NULL) {
      _invent[idx] = m;
      std::cout << "* The new item(" << m->getType()
                << ")  successfully equipped *" << std::endl;
      return;
    }
  }
  std::cout << "! full inventory, unable to equip " << m->getType() << "!"
            << std::endl;
}

void Character::unequip(int idx) {
  debug::printCharacter();
  showName();
  if (_invent[idx] == NULL) {
    std::cout << "* empty " << idx << " inventory slot, nothing to unequip *"
              << std::endl;
    return;
  }
  std::cout << "* threw away the materia( " << _invent[idx]->getType() << " ) *"
            << std::endl;
  _invent[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
  debug::printCharacter();
  showName();
  if (_invent[idx] == NULL) {
    std::cout << "* empty " << idx << " inventory slot, nothing to use *"
              << std::endl;
  } else
    _invent[idx]->use(target);
}

AMateria const *Character::getItemPtr(int idx) const {
  return (_invent[idx]);
}
