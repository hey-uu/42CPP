#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
public:
  Animal(void);
  Animal(std::string const &type);
  Animal(Animal const &other);
  Animal &operator=(Animal const &other);
  virtual ~Animal(void);
  virtual void makeSound(void) const;
  std::string getType(void) const;
  virtual Animal *clone(void);

protected:
  std::string _type;
};

#endif