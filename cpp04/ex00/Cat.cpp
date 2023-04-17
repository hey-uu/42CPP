#include "Cat.hpp"
#include <iomanip>
#include <iostream>

const std::string Cat::_kTypeCat = "Cat";

Cat::Cat(void) : Animal(_kTypeCat) {
  std::clog << "[ DEBUG ] Cat default constructor called" << std::endl;
}

Cat::Cat(Cat const &other) : Animal(_kTypeCat) {
  (void) other;
  std::clog << "[ DEBUG ] Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &other) {
  (void) other;
  std::clog << "[ DEBUG ] Cat assignment operator called" << std::endl;
  return (*this);
}

Cat::~Cat(void) {
  std::clog << "[ DEBUG ] Cat destructor  called" << std::endl;
}

void Cat::makeSound(void) const {
  std::cout << std::setw(_kWidth) << std::left << "Animal( cat )";
  std::cout << " : MEOW~ MEOW~ MEOW~ " << std::endl;
}
