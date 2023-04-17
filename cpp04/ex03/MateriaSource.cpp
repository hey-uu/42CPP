#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>
#include "debug_msg.hpp"

MateriaSource::MateriaSource(void) : IMateriaSource() {
  debug::printMateriaSource();
  debug::debugMsg(debug::kDefaultConstructor);
  for (int i = 0; i < _kCap; i++)
    _srcs[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &other)
    : IMateriaSource(other) {
  debug::printMateriaSource();
  debug::debugMsg(debug::kCopyConstructor);
  for (int i = 0; i < _kCap; i++) {
    if (_srcs[i])
      delete _srcs[i];
    _srcs[i] = (!other._srcs[i]) ? NULL : other._srcs[i]->clone();
  }
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other) {
  debug::printMateriaSource();
  debug::debugMsg(debug::kAssignOperator);
  for (int i = 0; i < _kCap; i++) {
    if (_srcs[i])
      delete _srcs[i];
    _srcs[i] = (!other._srcs[i]) ? NULL : other._srcs[i]->clone();
  }
  return (*this);
}

MateriaSource::~MateriaSource(void) {
  debug::printMateriaSource();
  debug::debugMsg(debug::kDestructor);
  for (int i = 0; i < _kCap; i++) {
    if (_srcs[i])
      delete _srcs[i];
    _srcs[i] = NULL;
  }
}

void MateriaSource::learnMateria(AMateria *m) {
  debug::printMateriaSource();
  if (!m) {
    std::cout << "! The argument must not be NULL pointer !" << std::endl;
    return;
  }
  for (int i = 0; i < _kCap; i++) {
    if (_srcs[i] == NULL) {
      _srcs[i] = m;
      std::cout << "* Successed to learn new materia(" << m->getType() << ") *"
                << std::endl;
      return;
    } else if (_srcs[i] == NULL) {
      std::cout << "* You already know this materia(" << m->getType() << ") *"
                << std::endl;
      return;
    }
  }
  std::cout << "! Failed to learn new materia !" << m->getType() << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
  debug::printMateriaSource();
  for (int i = 0; i < _kCap; i++) {
    if (_srcs[i] == NULL)
      continue;
    if (_srcs[i]->getType() == type) {
      std::cout << "Created a new Materia, " << type << std::endl;
      return (_srcs[i]->clone());
    }
  }
  std::cout << "There is no such type " << type << " in materia source"
            << std::endl;
  return (NULL);
}
