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
  void showBrainUpTo(int up_to) const;
  virtual Animal *clone(void) const;

private:
  static const std::string _kTypeDog;
  Brain *_brain_ptr;
};

#endif