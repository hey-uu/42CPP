#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class AAnimal {
public:
  AAnimal(void);
  AAnimal(std::string const &type);
  virtual ~AAnimal(void);

  std::string getType(void) const;
  virtual void makeSound(void) const = 0;
  virtual AAnimal *clone(void) const = 0;

protected:
  std::string _type;
  static const int _kWidth = 16;

private:
  AAnimal(AAnimal const &other);
  AAnimal &operator=(AAnimal const &other);
};

#endif