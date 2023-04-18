#include "Animal.hpp"
#include <iomanip>
#include <iostream>

Animal::Animal(void) : _type("?") {
  std::clog << "[ DEBUG ] Animal default constructor called" << std::endl;
}

Animal::Animal(std::string const &type) : _type(type) {
  std::clog << "[ DEBUG ] Animal string constructor called" << std::endl;
}

Animal::Animal(Animal const &other) : _type(other._type) {
  std::clog << "[ DEBUG ] Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &other) {
  std::clog << "[ DEBUG ] Animal assignment operator called" << std::endl;
  if (this != &other)
    _type = other._type;
  return (*this);
}

Animal::~Animal(void) {
  std::clog << "[ DEBUG ] Animal destructor  called" << std::endl;
}

void Animal::makeSound(void) const {
  std::cout << std::setw(_kWidth) << std::left << "Animal( " + _type + " )"
            << " : PUHAKHAKHAK! " << std::endl;
}

std::string Animal::getType(void) const { return (_type); }

// extra
Animal *Animal::clone(void) const { return (new Animal(this->_type)); }