#include "WrongAnimal.hpp"
#include <iomanip>
#include <iostream>

WrongAnimal::WrongAnimal(void) : _type("") {
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

  _type = other._type;
  return (*this);
}

WrongAnimal::~WrongAnimal(void) {
  std::clog << "[ DEBUG ] WrongAnimal destructor  called" << std::endl;
}

void WrongAnimal::makeSound(void) const {
  if (_type.length() > 0)
    std::cout << std::setw(25) << std::left << "WrongAnimal( " + _type + " )";
  else
    std::cout << std::setw(25) << std::left << "WrongAnimal( ? )";
  std::cout << " : PUHAKHAKHAK! " << std::endl;
}

std::string WrongAnimal::getType(void) const { return (_type); }
