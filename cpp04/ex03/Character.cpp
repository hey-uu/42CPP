#include "Character.hpp"
#include "AMateria.hpp"
#include "debug_msg.hpp"
#include <iomanip>
#include <iostream>

Character::Character(void) : ICharacter() {
  debug::printCharacter();
  debug::debugMsg(debug::kDefaultConstructor);
  _name = "";
  for (int idx = 0; idx < _kCap; idx++)
    _invent[idx] = NULL;
}

Character::Character(std::string const &name) : ICharacter() {
  debug::printCharacter();
  debug::debugMsg(debug::kStringConstructor);
  _name = name;
  for (int idx = 0; idx < _kCap; idx++)
    _invent[idx] = NULL;
}

Character::Character(Character const &other) : ICharacter() {
  debug::printCharacter();
  debug::debugMsg(debug::kCopyConstructor);
  _name = other._name;
  for (int idx = 0; idx < _kCap; idx++) {
    _invent[idx] = (other._invent[idx]) ? other._invent[idx]->clone() : NULL;
  }
}

Character &Character::operator=(Character const &other) {
  debug::printCharacter();
  debug::debugMsg(debug::kAssignOperator);
  if (this == &other)
    return (*this);
  _name = other._name;
  for (int idx = 0; idx < _kCap; idx++) {
    delete _invent[idx];
    _invent[idx] = (other._invent[idx]) ? other._invent[idx]->clone() : NULL;
  }
  return (*this);
}

Character::~Character(void) {
  debug::printCharacter();
  debug::debugMsg(debug::kDestructor);
  for (int idx = 0; idx < _kCap; idx++) {
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
  int empty_idx = -1;
  for (int idx = 0; idx < _kCap; idx++) {
    if (_invent[idx] == m) {
      std::cout << "! You already has this materia(" << m->getType() << ") !";
      return;
    }
    if (_invent[idx] == NULL && empty_idx < 0)
      empty_idx = idx;
  }
  if (empty_idx < 0)
    std::cout << "! Full inventory, unable to equip " << m->getType() << "!"
              << std::endl;
  else {
    std::cout << "* The new item(" << m->getType()
              << ")  successfully equipped *" << std::endl;
    _invent[empty_idx] = m;
  }
}

void Character::unequip(int idx) {
  debug::printCharacter();
  showName();
  if (idx < 0 || idx >= _kCap) {
    std::cout << "! wrong index !" << std::endl;
  } else if (_invent[idx] == NULL) {
    std::cout << "* empty " << idx << " inventory slot, nothing to unequip *"
              << std::endl;
  } else {
    std::cout << "* threw away the materia( " << _invent[idx]->getType()
              << " ) *" << std::endl;
    _invent[idx] = NULL;
  }
}

void Character::use(int idx, ICharacter &target) {
  debug::printCharacter();
  showName();
  if (idx < 0 || idx >= _kCap) {
    std::cout << "! wrong index !" << std::endl;
  } else if (_invent[idx] == NULL) {
    std::cout << "* empty " << idx << " inventory slot, nothing to use *"
              << std::endl;
  } else
    _invent[idx]->use(target);
}

void Character::showName(void) const {
  std::cout << std::setw(_kNameWidth) << std::left << "( " + _name + " ) ";
}

AMateria const *Character::getItemPtr(int idx) const { return (_invent[idx]); }
