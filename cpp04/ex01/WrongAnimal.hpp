#ifndef WRONG_WrongAnimal_HPP
#define WRONG_WrongAnimal_HPP

#include <string>

class WrongAnimal {
public:
  WrongAnimal(void);
  virtual ~WrongAnimal(void);

  void makeSound(void) const;
  std::string getType(void) const;

protected:
  static const int _kWidth = 25;
  std::string _type;
  WrongAnimal(std::string const &type);

private:
  WrongAnimal(WrongAnimal const &other);
  WrongAnimal &operator=(WrongAnimal const &other);
};

#endif