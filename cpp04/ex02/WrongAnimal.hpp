#ifndef WRONG_WrongAnimal_HPP
#define WRONG_WrongAnimal_HPP

#include <string>

class WrongAnimal {
public:
  WrongAnimal(void);
  WrongAnimal(std::string const &type);
  WrongAnimal(WrongAnimal const &other);
  WrongAnimal &operator=(WrongAnimal const &other);
  virtual ~WrongAnimal(void);
  void makeSound(void) const;
  std::string getType(void) const;

protected:
  std::string _type;
};

#endif