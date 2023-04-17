#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
public:
  Character(void);
  Character(std::string const &name);
  Character(Character const &other);
  Character &operator=(Character const &other);
  virtual ~Character(void);

  virtual std::string const &getName() const;
  virtual void equip(AMateria *m);
  virtual void unequip(int idx);
  virtual void use(int idx, ICharacter &target);

  virtual AMateria const *getItemPtr(int idx) const;

private:
  AMateria *_invent[4];
  static const int _kCap = 4;
};

#endif