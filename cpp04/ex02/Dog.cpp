#include "Dog.hpp"
#include <iomanip>
#include <iostream>

const std::string Dog::_kTypeDog = "Dog";

Dog::Dog(void) : AAnimal(_kTypeDog) {
  std::clog << "[ DEBUG ] Dog default constructor called" << std::endl;
  _brain_ptr = new Brain();
}

Dog::Dog(std::string const &idea_prefix) : AAnimal(_kTypeDog) {
  std::clog << "[ DEBUG ] Dog string constructor called" << std::endl;
  _brain_ptr = new Brain(idea_prefix);
}

Dog::Dog(Dog const &other) : AAnimal(_kTypeDog) {
  std::clog << "[ DEBUG ] Dog copy constructor called" << std::endl;
  _brain_ptr = new Brain(*other._brain_ptr);
}

Dog &Dog::operator=(Dog const &other) {
  std::clog << "[ DEBUG ] Dog assignment operator called" << std::endl;
  if (this != &other)
    *_brain_ptr = *other._brain_ptr;
  return (*this);
}

Dog::~Dog(void) {
  std::clog << "[ DEBUG ] Dog destructor  called" << std::endl;
  delete _brain_ptr;
  _brain_ptr = NULL;
}

void Dog::makeSound(void) const {
  std::cout << std::setw(_kWidth) << std::left << "Animal( dog )"
            << " : BARK! BARK! BARK!" << std::endl;
}

void Dog::showBrain(void) const { _brain_ptr->showIdeas(); }

void Dog::showBrainUpTo(int up_to) const { _brain_ptr->showIdeasUpTo(up_to); }

AAnimal *Dog::clone(void) const { return (new Dog(*this)); }
