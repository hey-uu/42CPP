#include "Dog.hpp"
#include <iostream>
#include <iomanip>

Dog::Dog(void) : Animal("Dog") {
  std::clog << "[ DEBUG ] Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const &other) : Animal(other._type) {
  std::clog << "[ DEBUG ] Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &other) {
  std::clog << "[ DEBUG ] Dog assignment operator called" << std::endl;
  _type = other._type;
  return (*this);
}

Dog::~Dog(void) {
  std::clog << "[ DEBUG ] Dog destructor  called" << std::endl;
}

void Dog::makeSound(void) const {
  std::cout << std::setw(16) << std::left << "Animal( dog )";
  std::cout << " : BARK! BARK! BARK!" << std::endl;
}
