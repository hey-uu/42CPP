#include "Cat.hpp"
#include <iostream>
#include <iomanip>

Cat::Cat(void) : Animal("Cat") {
  std::clog << "[ DEBUG ] Cat default constructor called" << std::endl;
}

Cat::Cat(Cat const &other) : Animal(other._type) {
  std::clog << "[ DEBUG ] Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &other) {
  std::clog << "[ DEBUG ] Cat assignment operator called" << std::endl;
  _type = other._type;
  return (*this);
}

Cat::~Cat(void) {
  std::clog << "[ DEBUG ] Cat destructor  called" << std::endl;
}

void Cat::makeSound(void) const {
  std::cout << std::setw(16) << std::left << "Animal( cat )";
  std::cout << " : MEOW~ MEOW~ MEOW~ " << std::endl;
}
