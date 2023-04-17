#include "ScavTrap.hpp"

int main(void) {

  std::cout << "\n================================= TEST1 "
               "=================================\n"
            << std::endl;
  /** TEST1 : ClapTrap vs ScavTrap **/
  ClapTrap clapTrap("Foo");
  ScavTrap scavTrap("Bar");

  // after calling constructor
  clapTrap.printStatus();
  scavTrap.printStatus();

  // attack
  clapTrap.setAttackDamage(1);
  clapTrap.attack("opponent1");

  scavTrap.attack("opponent2");

  // guardGate
  scavTrap.guardGate();

  std::cout << "\n===================================="
               "=====================================\n"
            << std::endl;
  /** Test2 : ClapTrap *, ScavTrap * **/
  std::cout << "\n================================= TEST2 "
               "=================================\n"
            << std::endl;
  ClapTrap *clapTrap2 = new ClapTrap("Foo");
  ClapTrap *scavTrap2 = new ScavTrap("Bar");
  ScavTrap *scavTrap3 = new ScavTrap("Baz");
  // show
  clapTrap2->printStatus();
  scavTrap2->printStatus();
  scavTrap3->printStatus();
  // attack
  clapTrap2->attack("opponent3");
  scavTrap2->attack("opponent4");
  scavTrap3->attack("opponent5");
  // special function
  // scavTrap2->guardGate();
  scavTrap3->guardGate();
  delete clapTrap2;
  delete scavTrap2;
  delete scavTrap3;
  std::cout << "\n===================================="
               "=====================================\n"
            << std::endl;

  /** Test3 : ClapTrap reference, ScavTrap reference **/
  std::cout << "\n================================= TEST3 "
               "=================================\n"
            << std::endl;
  ClapTrap &clapTrap_ref = clapTrap;
  ClapTrap &scavTrap_ref1 = scavTrap;
  ScavTrap &scavTrap_ref2 = scavTrap;
  // show
  clapTrap_ref.printStatus();
  scavTrap_ref1.printStatus();
  scavTrap_ref2.printStatus();
  // attack
  clapTrap_ref.attack("opponent3");
  scavTrap_ref1.attack("opponent4");
  scavTrap_ref2.attack("opponent5");
  // special function
  // scavTrap4.guardGate();
  scavTrap_ref2.guardGate();
   std::cout << "\n===================================="
               "=====================================\n"
            << std::endl;
}
