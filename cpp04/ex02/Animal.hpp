#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
public:
  Animal &operator=(Animal const &other);
  virtual ~Animal(void);

  std::string getType(void) const;
  virtual void makeSound(void) const = 0;
  virtual Animal *clone(void) = 0;

protected:
  std::string _type;

private:
  Animal(void);
  Animal(std::string const &type);
  Animal(Animal const &other);
};

#endif