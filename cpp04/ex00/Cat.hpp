#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
class Cat : public Animal {
public:
  Cat(void);
  virtual ~Cat(void);

  virtual void makeSound(void) const;

private:
  static const std::string _kTypeCat;
  Cat(Cat const &other);
  Cat &operator=(Cat const &other);
};

#endif