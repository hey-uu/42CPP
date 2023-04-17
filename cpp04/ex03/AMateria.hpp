#ifndef A_MATERIA_HPP
#define A_MATERIA_HPP

#include <string>

class ICharacter;

class AMateria {
public:
  AMateria(void);
  AMateria(std::string const &type);
  virtual ~AMateria(void);

  std::string const &getType() const;

  virtual AMateria *clone() const = 0;
  virtual void use(ICharacter &target);

protected:
  std::string _type;

private:
  AMateria(AMateria const &other);
  AMateria &operator=(AMateria const &other);
};

#endif