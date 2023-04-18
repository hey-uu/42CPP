#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
public:
  Animal(void);
  virtual ~Animal(void);

  virtual void makeSound(void) const;
  std::string getType(void) const;
  virtual Animal *clone(void) const;

protected:
  static const int _kWidth = 16;
  std::string _type;
  Animal(std::string const &type);

private:
  Animal(Animal const &other);
  Animal &operator=(Animal const &other);
};

#endif