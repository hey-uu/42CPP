#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "debug_msg.hpp"
#include <iostream>

MateriaSource::MateriaSource(void) : IMateriaSource() {
  debug::printMateriaSource();
  debug::debugMsg(debug::kDefaultConstructor);
  for (int idx = 0; idx < _kCap; idx++)
    _srcs[idx] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &other)
    : IMateriaSource(other) {
  debug::printMateriaSource();
  debug::debugMsg(debug::kCopyConstructor);
  for (int idx = 0; idx < _kCap; idx++) {
    _srcs[idx] = (other._srcs[idx]) ? other._srcs[idx]->clone() : NULL;
  }
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other) {
  debug::printMateriaSource();
  debug::debugMsg(debug::kAssignOperator);
  if (this == &other)
    return (*this);
  for (int idx = 0; idx < _kCap; idx++) {
    delete _srcs[idx];
    _srcs[idx] = (other._srcs[idx]) ? other._srcs[idx]->clone() : NULL;
  }
  return (*this);
}

MateriaSource::~MateriaSource(void) {
  debug::printMateriaSource();
  debug::debugMsg(debug::kDestructor);
  for (int idx = 0; idx < _kCap; idx++) {
    if (_srcs[idx])
      delete _srcs[idx];
    _srcs[idx] = NULL;
  }
}

void MateriaSource::learnMateria(AMateria *m) {
  debug::printMateriaSource();
  if (!m) {
    std::cout << "! The argument must not be NULL pointer !" << std::endl;
    return;
  }
  int empty_idx = -1;
  for (int idx = 0; idx < _kCap; idx++) {
    if (_srcs[idx] == m) {
      std::cout << "* You already know this materia(" << m->getType() << ") *"
                << std::endl;
      return;
    }
    if (_srcs[idx] == NULL && empty_idx < 0)
      empty_idx = idx;
  }
  if (empty_idx < 0)
    std::cout << "! Failed to learn new materia !" << m->getType() << std::endl;
  else {
    std::cout << "* Successed to learn new materia(" << m->getType() << ") *"
              << std::endl;
    _srcs[empty_idx] = m;
  }
}

AMateria *MateriaSource::createMateria(std::string const &type) {
  debug::printMateriaSource();
  for (int idx = 0; idx < _kCap; idx++) {
    if (_srcs[idx] == NULL)
      continue;
    if (_srcs[idx]->getType() == type) {
      std::cout << "Created a new Materia, " << type << std::endl;
      return (_srcs[idx]->clone());
    }
  }
  std::cout << "There is no such type " << type << " in materia source"
            << std::endl;
  return (NULL);
}
