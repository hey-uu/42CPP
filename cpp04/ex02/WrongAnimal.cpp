#include "WrongAnimal.hpp"
#include <iomanip>
#include <iostream>

WrongAnimal::WrongAnimal(void) : _type("!") {
  std::clog << "[ DEBUG ] WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string const &type) : _type(type) {
  std::clog << "[ DEBUG ] WrongAnimal string constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other) : _type(other._type) {
  std::clog << "[ DEBUG ] WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other) {
  std::clog << "[ DEBUG ] WrongAnimal assignment operator called" << std::endl;
  if (this != &other)
    _type = other._type;
  return (*this);
}

WrongAnimal::~WrongAnimal(void) {
  std::clog << "[ DEBUG ] WrongAnimal destructor  called" << std::endl;
}

void WrongAnimal::makeSound(void) const {
  std::cout << std::setw(_kWidth) << std::left << "WrongAnimal( " + _type + " )"
            << " : HAKHAKHAKPU! " << std::endl;
}

std::string WrongAnimal::getType(void) const { return (_type); }
