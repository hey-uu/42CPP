#ifndef I_CHARACTER_HPP
#define I_CHARACTER_HPP

#include <string>

class AMateria;

class ICharacter {
public:
  ICharacter(void);
  ICharacter(std::string const &name);
  ICharacter(ICharacter const &other);
  ICharacter &operator=(ICharacter const &other);
  virtual ~ICharacter(void);

  virtual std::string const &getName() const = 0;
  virtual void equip(AMateria *m) = 0;
  virtual void unequip(int idx) = 0;
  virtual void use(int idx, ICharacter &target) = 0;

  // show
  void  showName(void) const;
  virtual AMateria const *getItemPtr(int idx) = 0;

protected:
  std::string _name;
  
};

#endif