#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main(void) {

  std::cout << "\n=========================(  new MateriaSource()  )=========================\n\n";
  std::cout << ">> IMateriaSource *src = new MateriaSource();\n";
  IMateriaSource *src = new MateriaSource();

  std::cout << "\n=========================(     learnMateria      )=========================\n\n";
  std::cout << ">> src->learnMateria(new Ice());\n";
  src->learnMateria(new Ice());
  std::cout << "\n>> src->learnMateria(new Cure());\n";
  src->learnMateria(new Cure());


  std::cout << "\n=========================(  new Character(\"me\")  )=========================\n\n";
  std::cout << ">> ICharacter *me = new Character(\"me\");\n";
  ICharacter *me = new Character("me");

  std::cout << "\n=========================( createMateria,  equip )=========================\n\n";
  std::cout << ">> AMateria *tmp;\n";
  AMateria *tmp;
  std::cout << ">> tmp = learnMateria(\"ice\");\n";
  tmp = src->createMateria("ice");
  std::cout << "\n>> me->equip(tmp);\n";
  me->equip(tmp);
  std::cout << "\n>> tmp = learnMateria(\"ice\");\n";
  tmp = src->createMateria("cure");
  std::cout << "\n>> me->equip(tmp)\n";
  me->equip(tmp);

  std::cout << "\n=========================( new  Character(\"bob\") )=========================\n\n";
  std::cout << ">> ICharacter *bob = new Character(\"bob\");\n";
  ICharacter *bob = new Character("bob");

  std::cout << "\n=========================(          use          )=========================\n\n";
  std::cout << ">> me->use(0, *bob);\n";
  me->use(0, *bob);
  std::cout << "\n>> me->use(1, *bob);\n";
  me->use(1, *bob);
  std::cout << "\n>> me->use(1, *bob);\n";
  me->use(2, *bob);

  std::cout << "\n=========================(        unequip        )=========================\n\n";
  AMateria  *unequiped[3];
  std::cout << ">> me->unequip(0);\n";
  unequiped[0] = const_cast<AMateria *>(me->getItemPtr(0));
  me->unequip(0);
  std::cout << "\n>> me->use(1, *bob);\n";
  unequiped[1] = const_cast<AMateria *>(me->getItemPtr(1));
  me->unequip(1);
  std::cout << "\n>> me->use(1, *bob);\n";
  unequiped[2] = const_cast<AMateria *>(me->getItemPtr(2));
  me->unequip(2);

  std::cout << "\n=========================(        delete         )=========================\n\n";
  std::cout << ">> delete bob;\n";
  delete bob;
  std::cout << "\n>> delete me;\n";
  delete me;
  std::cout << "\n>> delete src;\n";
  delete src;
  std::cout << "\n>> delete unequiped;\n";
  for (int i = 0; i < 3; i++)
    delete unequiped[i];
  (void) unequiped;

  return (0);
}