#include "Cat.hpp"
#include <iomanip>
#include <iostream>

const std::string Cat::_kTypeCat = "Cat";

Cat::Cat(void) : Animal(_kTypeCat) {
  std::clog << "[ DEBUG ] Cat default constructor called" << std::endl;
  _brain_ptr = new Brain();
}

Cat::Cat(std::string const &idea_prefix) : Animal(_kTypeCat) {
  std::clog << "[ DEBUG ] Cat string constructor called" << std::endl;
  _brain_ptr = new Brain(idea_prefix);
}

Cat::Cat(Cat const &other) : Animal(_kTypeCat) {
  std::clog << "[ DEBUG ] Cat copy constructor called" << std::endl;
  _brain_ptr = new Brain(*other._brain_ptr);
}

Cat &Cat::operator=(Cat const &other) {
  std::clog << "[ DEBUG ] Cat assignment operator called" << std::endl;
  if (this != &other)
    *_brain_ptr = *other._brain_ptr;
  return (*this);
}

Cat::~Cat(void) {
  std::clog << "[ DEBUG ] Cat destructor  called" << std::endl;
  delete _brain_ptr;
  _brain_ptr = NULL;
}

void Cat::makeSound(void) const {
  std::cout << std::setw(_kWidth) << std::left << "Animal( cat )"
            << " : MEOW~ MEOW~ MEOW~ " << std::endl;
}

void Cat::showBrain(void) const { _brain_ptr->showIdeas(); }

void Cat::showBrainUpTo(int up_to) const { _brain_ptr->showIdeasUpTo(up_to); }

Animal *Cat::clone(void) const { return (new Cat(*this)); }
