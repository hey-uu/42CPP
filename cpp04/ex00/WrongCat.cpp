#include "WrongCat.hpp"
#include <iomanip>
#include <iostream>

const std::string WrongCat::_kTypeWrongCat = "WrongCat";

WrongCat::WrongCat(void) : WrongAnimal(_kTypeWrongCat) {
  std::clog << "[ DEBUG ] WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &other) : WrongAnimal(_kTypeWrongCat) {
  (void)other;
  std::clog << "[ DEBUG ] WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &other) {
  (void)other;
  std::clog << "[ DEBUG ] WrongCat assignment operator called" << std::endl;
  return (*this);
}

WrongCat::~WrongCat(void) {
  std::clog << "[ DEBUG ] WrongCat destructor  called" << std::endl;
}

void WrongCat::makeSound(void) const {
  std::cout << std::setw(_kWidth) << std::left << "WrongAnimal( wrongCat )"
            << " : MEOW~ MEOW~ MEOW~ " << std::endl;
}
