#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
public:
  Dog(void);
  Dog(std::string const &idea_prefix);
  Dog(Dog const &other);
  Dog &operator=(Dog const &other);
  virtual ~Dog(void);

  virtual void makeSound(void) const;
  void showBrain(void) const;
  void showBrainUpTo(int upTo) const;
  virtual AAnimal *clone(void) const;

private:
  static const std::string _kTypeDog;
  Brain *_brain_ptr;
};

#endif