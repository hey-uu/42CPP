#ifndef I_CHARACTER_HPP
#define I_CHARACTER_HPP

#include <string>

class AMateria;

class ICharacter {
public:
  virtual ~ICharacter(void) {}
  virtual std::string const &getName() const = 0;
  virtual void equip(AMateria *m) = 0;
  virtual void unequip(int idx) = 0;
  virtual void use(int idx, ICharacter &target) = 0;

  virtual void showName(void) const = 0;
  virtual AMateria const *getItemPtr(int idx) const = 0;
};

#endif