#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
public:
  Cat(void);
  Cat(std::string const &idea_prefix);
  Cat(Cat const &other);
  Cat &operator=(Cat const &other);
  virtual ~Cat(void);

  virtual void makeSound(void) const;
  void showBrain(void) const;
  void showBrainUpTo(int upTo) const;
  virtual Animal *clone(void) const;

private:
  Brain *_brain_ptr;
  static const std::string _kTypeCat;

};

#endif