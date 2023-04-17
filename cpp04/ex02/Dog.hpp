#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
public:
  Dog(void);
  Dog(std::string const &idea_prefix);
  Dog(Dog const &other);
  Dog &operator=(Dog const &other);
  virtual ~Dog(void);
  virtual void makeSound(void) const;
  void showBrain(void) const;
  void showBrainUpTo(int upTo) const;
  virtual Animal *clone(void);

private:
  Brain *_brain_ptr;
};

#endif