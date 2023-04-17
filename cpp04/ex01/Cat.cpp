#include "Cat.hpp"
#include <iomanip>
#include <iostream>

Cat::Cat(void) : Animal("Cat") {
  std::clog << "[ DEBUG ] Cat default constructor called" << std::endl;

  _brain_ptr = new Brain();
}

Cat::Cat(std::string const &idea_prefix) : Animal("Cat") {
  std::clog << "[ DEBUG ] Cat string constructor called" << std::endl;

  _brain_ptr = new Brain(idea_prefix);
}

Cat::Cat(Cat const &other) : Animal(other._type) {
  _brain_ptr = new Brain(*other._brain_ptr);
  std::clog << "[ DEBUG ] Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &other) {
  delete _brain_ptr;
  _brain_ptr = NULL;
  _brain_ptr = new Brain(*other._brain_ptr);
  std::clog << "[ DEBUG ] Cat assignment operator called" << std::endl;
  _type = other._type;
  return (*this);
}

Cat::~Cat(void) {
  std::clog << "[ DEBUG ] Cat destructor  called" << std::endl;

  delete _brain_ptr;
  _brain_ptr = NULL;
}

void Cat::makeSound(void) const {
  std::cout << std::setw(16) << std::left << "Animal( cat )";
  std::cout << " : MEOW~ MEOW~ MEOW~ " << std::endl;
}

void Cat::showBrain(void) const { _brain_ptr->showIdeas(); }

void Cat::showBrainUpTo(int upTo) const { _brain_ptr->showIdeasUpTo(upTo); }

Animal *Cat::clone(void)
{
  return (new Cat(*this));
}
