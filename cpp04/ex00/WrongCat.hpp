#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
  WrongCat(void);
  virtual ~WrongCat(void);
  void makeSound(void) const;

private:
  WrongCat(WrongCat const &other);
  WrongCat &operator=(WrongCat const &other);
  
  static const std::string _kTypeWrongCat;
};

#endif