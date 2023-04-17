#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "IMateriaSource.hpp"
#include <string>

class AMateria;

class MateriaSource : public IMateriaSource {
public:
  MateriaSource(void);
  MateriaSource(MateriaSource const &other);
  MateriaSource &operator=(MateriaSource const &other);
  virtual ~MateriaSource(void);

  virtual void learnMateria(AMateria *);
  virtual AMateria *createMateria(std::string const &type);

private:
  AMateria *_srcs[4];
  static const int _kCap = 4;
};

#endif