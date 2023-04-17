#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
public:
  Animal(void);
  Animal(std::string const &type);
  virtual ~Animal(void);

  virtual void makeSound(void) const;
  std::string getType(void) const;
  virtual Animal *clone(void) const;

protected:
  std::string _type;
  static const int _kWidth = 16;

private:
  Animal(Animal const &other);
  Animal &operator=(Animal const &other);
};

#endif