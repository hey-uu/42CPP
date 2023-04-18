#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
  WrongCat(void);
  virtual ~WrongCat(void);

  void makeSound(void) const;

private:
  static const std::string _kTypeWrongCat;
  WrongCat(WrongCat const &other);
  WrongCat &operator=(WrongCat const &other);
};

#endif