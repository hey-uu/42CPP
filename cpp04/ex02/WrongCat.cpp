#include "WrongCat.hpp"
#include <iomanip>
#include <iostream>

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
  std::clog << "[ DEBUG ] WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &other) : WrongAnimal(other._type) {
  std::clog << "[ DEBUG ] WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &other) {
  std::clog << "[ DEBUG ] WrongCat assignment operator called" << std::endl;
  _type = other._type;
  return (*this);
}

WrongCat::~WrongCat(void) {
  std::clog << "[ DEBUG ] WrongCat destructor  called" << std::endl;
}

void WrongCat::makeSound(void) const {
  std::cout << std::setw(25) << std::left << "WrongAnimal( wrongCat )";
  std::cout << " : MEOW~ MEOW~ MEOW~ " << std::endl;
}
