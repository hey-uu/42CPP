#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
public:
  Cat(void);
  Cat(std::string const &idea_prefix);
  Cat(Cat const &other);
  Cat &operator=(Cat const &other);
  virtual ~Cat(void);

  virtual void makeSound(void) const;
  void showBrain(void) const;
  void showBrainUpTo(int upTo) const;
  virtual AAnimal *clone(void) const;

private:
  static const std::string _kTypeCat;
  Brain *_brain_ptr;
};

#endif