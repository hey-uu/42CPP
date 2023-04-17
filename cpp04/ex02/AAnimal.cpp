#include "AAnimal.hpp"
#include <iomanip>
#include <iostream>

AAnimal::AAnimal(void) : _type("") {
  std::clog << "[ DEBUG ] Animal default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string const &type) : _type(type) {
  std::clog << "[ DEBUG ] Animal string constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &other) : _type(other._type) {
  std::clog << "type : " << other._type << std::endl;
  std::clog << "[ DEBUG ] Animal copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(AAnimal const &other) {
  std::clog << "[ DEBUG ] Animal assignment operator called" << std::endl;
  _type = other._type;
  return (*this);
}

AAnimal::~AAnimal(void) {
  std::clog << "[ DEBUG ] Animal destructor  called" << std::endl;
}

std::string AAnimal::getType(void) const { return (_type); }
