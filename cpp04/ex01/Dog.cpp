#include "Dog.hpp"
#include <iomanip>
#include <iostream>

Dog::Dog(void) : Animal("Dog") {
  std::clog << "[ DEBUG ] Dog default constructor called" << std::endl;

  _brain_ptr = new Brain();
}

Dog::Dog(std::string const &idea_prefix) : Animal("Dog") {
  std::clog << "[ DEBUG ] Dog string constructor called" << std::endl;

  _brain_ptr = new Brain(idea_prefix);
}

Dog::Dog(Dog const &other) : Animal(other._type) {
  _brain_ptr = new Brain(*other._brain_ptr);
  std::clog << "[ DEBUG ] Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &other) {
  delete _brain_ptr;
  _brain_ptr = NULL;
  _brain_ptr = new Brain(*other._brain_ptr);
  std::clog << "[ DEBUG ] Dog assignment operator called" << std::endl;
  _type = other._type;
  return (*this);
}

Dog::~Dog(void) {
  std::clog << "[ DEBUG ] Dog destructor  called" << std::endl;

  delete _brain_ptr;
  _brain_ptr = NULL;
}

void Dog::makeSound(void) const {
  std::cout << std::setw(16) << std::left << "Animal( dog )";
  std::cout << " : BARK! BARK! BARK!" << std::endl;
}

void Dog::showBrain(void) const { _brain_ptr->showIdeas(); }

void Dog::showBrainUpTo(int upTo) const { _brain_ptr->showIdeasUpTo(upTo); }

Animal *Dog::clone(void)
{
  return (new Dog(*this));
}
