#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
  Dog(void);
  virtual ~Dog(void);

  virtual void makeSound(void) const;

private:
  static const std::string _kTypeDog;
  Dog(Dog const &other);
  Dog &operator=(Dog const &other);
};

#endif