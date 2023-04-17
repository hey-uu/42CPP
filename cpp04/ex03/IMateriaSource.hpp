#ifndef I_MATERIA_SOURCE_HPP
#define I_MATERIA_SOURCE_HPP

#include <string>

class AMateria;

class IMateriaSource {
public:
  IMateriaSource(void);
  IMateriaSource(IMateriaSource const &other);
  IMateriaSource &operator=(IMateriaSource const &other);
  virtual ~IMateriaSource(void);

  virtual void learnMateria(AMateria *) = 0;
  virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif