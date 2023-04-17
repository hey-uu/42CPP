#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main(void) {

  std::cout << "\n=========================(  new MateriaSource()  "
               ")=========================\n"
            << std::endl;
  std::cout << ">> IMateriaSource *src = new MateriaSource();" << std::endl;
  IMateriaSource *src = new MateriaSource();

  std::cout << "\n=========================(     learnMateria      "
               ")=========================\n"
            << std::endl;
  std::cout << ">> src->learnMateria(new Ice());" << std::endl;
  src->learnMateria(new Ice());
  std::cout << "\n>> src->learnMateria(new Cure());" << std::endl;
  src->learnMateria(new Cure());

  std::cout << "\n=========================(  new Character(\"me\")  "
               ")=========================\n"
            << std::endl;
  std::cout << ">> ICharacter *me = new Character(\"me\");" << std::endl;
  ICharacter *me = new Character("me");

  std::cout << "\n=========================( createMateria,  equip "
               ")=========================\n"
            << std::endl;
  std::cout << ">> AMateria *tmp;" << std::endl;
  AMateria *tmp;
  std::cout << ">> tmp = learnMateria(\"ice\");" << std::endl;
  tmp = src->createMateria("ice");
  std::cout << "\n>> me->equip(tmp);" << std::endl;
  me->equip(tmp);
  std::cout << "\n>> tmp = learnMateria(\"ice\");" << std::endl;
  tmp = src->createMateria("cure");
  std::cout << "\n>> me->equip(tmp)\n";
  me->equip(tmp);

  std::cout << "\n=========================( new  Character(\"bob\") "
               ")=========================\n"
            << std::endl;
  std::cout << ">> ICharacter *bob = new Character(\"bob\");" << std::endl;
  ICharacter *bob = new Character("bob");

  std::cout << "\n=========================(          use          "
               ")=========================\n"
            << std::endl;
  std::cout << ">> me->use(0, *bob);" << std::endl;
  me->use(0, *bob);
  std::cout << "\n>> me->use(1, *bob);" << std::endl;
  me->use(1, *bob);
  std::cout << "\n>> me->use(1, *bob);" << std::endl;
  me->use(2, *bob);

  std::cout << "\n=========================(        unequip        "
               ")=========================\n"
            << std::endl;
  AMateria *unequiped[3];
  std::cout << ">> me->unequip(0);" << std::endl;
  unequiped[0] = const_cast<AMateria *>(me->getItemPtr(0));
  me->unequip(0);
  std::cout << "\n>> me->use(1, *bob);" << std::endl;
  unequiped[1] = const_cast<AMateria *>(me->getItemPtr(1));
  me->unequip(1);
  std::cout << "\n>> me->use(1, *bob);" << std::endl;
  unequiped[2] = const_cast<AMateria *>(me->getItemPtr(2));
  me->unequip(2);

  std::cout << "\n=========================(        delete         "
               ")=========================\n"
            << std::endl;
  std::cout << ">> delete bob;" << std::endl;
  delete bob;
  std::cout << "\n>> delete me;" << std::endl;
  delete me;
  std::cout << "\n>> delete src;" << std::endl;
  delete src;
  std::cout << "\n>> delete unequiped;" << std::endl;
  for (int i = 0; i < 3; i++)
    delete unequiped[i];
  (void)unequiped;

  return (0);
}