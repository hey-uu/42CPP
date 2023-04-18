#include "Dog.hpp"
#include <iomanip>
#include <iostream>

const std::string Dog::_kTypeDog = "Dog";

Dog::Dog(void) : Animal(_kTypeDog) {
  std::clog << "[ DEBUG ] Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const &other) : Animal(_kTypeDog) {
  std::clog << "[ DEBUG ] Dog copy constructor called" << std::endl;
  (void)other;
}

Dog &Dog::operator=(Dog const &other) {
  std::clog << "[ DEBUG ] Dog assignment operator called" << std::endl;
  (void)other;
  return (*this);
}

Dog::~Dog(void) {
  std::clog << "[ DEBUG ] Dog destructor  called" << std::endl;
}

void Dog::makeSound(void) const {
  std::cout << std::setw(_kWidth) << std::left << "Animal( dog )"
            << " : BARK! BARK! BARK!" << std::endl;
}
