#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
public:
  Cure(void);
  virtual ~Cure(void);

  virtual AMateria *clone() const;
  virtual void use(ICharacter &target);

private:
  Cure(Cure const &other);
  Cure &operator=(Cure const &other);
};

#endif