#include "DiamondTrap.hpp"

int main(void) {

  std::cout << "======================== TEST1 ========================="
            << std::endl;
  /** TEST1 : ClapTrap vs ScavTrap **/
  ClapTrap clapTrap("Foo");
  ScavTrap scavTrap("Bar");
  FragTrap fragTrap("Baz");
  DiamondTrap diamondTrap("DIAMOND");

  // after calling constructor
  clapTrap.printStatus();
  scavTrap.printStatus();
  fragTrap.printStatus();
  diamondTrap.printStatus();

  // attack
  clapTrap.setAttackDamage(1);
  clapTrap.attack("opponent1");
  scavTrap.attack("opponent2");
  fragTrap.attack("opponent3");

  // unique methods
  scavTrap.guardGate();
  fragTrap.highFivesGuys();

  std::cout << std::endl << std::endl;
  std::cout << "========================= TEST2 ========================="
            << std::endl;
  /** Test2 : ClapTrap *, ScavTrap * **/
  ClapTrap *clapTrap2 = new ClapTrap("Foo");
  ClapTrap *scavTrap2 = new ScavTrap("Bar");
  ScavTrap *scavTrap3 = new ScavTrap("Baz");
  FragTrap *fragTrap2 = new FragTrap("Qux");

  // show
  clapTrap2->printStatus();
  scavTrap2->printStatus();
  scavTrap3->printStatus();
  fragTrap2->printStatus();

  // attack
  clapTrap2->attack("opponent1");
  scavTrap2->attack("opponent2");
  scavTrap3->attack("opponent3");
  fragTrap2->attack("opponent4");

  // show
  clapTrap2->printStatus();
  scavTrap2->printStatus();
  scavTrap3->printStatus();
  fragTrap2->printStatus();

  // unique
  // scavTrap2->guardGate();
  scavTrap3->guardGate();
  fragTrap2->highFivesGuys();

  delete clapTrap2;
  delete scavTrap2;
  delete scavTrap3;
  delete fragTrap2;
  std::cout << "========================================================="
            << std::endl;
}