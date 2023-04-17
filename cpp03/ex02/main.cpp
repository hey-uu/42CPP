#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {

  /** TEST1 : ClapTrap vs ScavTrap vs FragTrap **/
  std::cout << "\n================================= TEST1 "
               "=================================\n"
            << std::endl;
  ClapTrap clapTrap("Foo");
  ScavTrap scavTrap("Bar");
  FragTrap fragTrap("Baz");

  // after calling constructor
  clapTrap.printInfo();
  scavTrap.printInfo();
  fragTrap.printInfo();

  // attack
  clapTrap.setAttackDamage(1);
  clapTrap.attack("opponent1");
  scavTrap.attack("opponent2");
  fragTrap.attack("opponent3");

  // unique methods
  scavTrap.guardGate();
  fragTrap.highFivesGuys();

  std::cout << "\n===================================="
               "=====================================\n"
            << std::endl;

  /** Test2 : ClapTrap *, ScavTrap *, FragTrap * **/
  std::cout << "\n================================= TEST2 "
               "=================================\n"
            << std::endl;
  ClapTrap *clapTrap_ptr = new ClapTrap("Foo");
  ClapTrap *scavTrap_ptr1 = new ScavTrap("Bar");
  ScavTrap *scavTrap_ptr2 = new ScavTrap("Baz");
  ClapTrap *fragTrap_ptr1 = new FragTrap("Qux");
  FragTrap *fragTrap_ptr2 = new FragTrap("Fred");

  // show
  clapTrap_ptr->printInfo();
  scavTrap_ptr1->printInfo();
  scavTrap_ptr2->printInfo();
  fragTrap_ptr1->printInfo();
  fragTrap_ptr2->printInfo();

  // attack
  clapTrap_ptr->attack("opponent1");
  scavTrap_ptr1->attack("opponent2");
  scavTrap_ptr2->attack("opponent3");
  fragTrap_ptr1->attack("opponent4");
  fragTrap_ptr2->attack("opponent5");

  // show
  clapTrap_ptr->printInfo();
  scavTrap_ptr1->printInfo();
  scavTrap_ptr2->printInfo();
  fragTrap_ptr1->printInfo();
  fragTrap_ptr2->printInfo();

  // unique
  // scavTrap_ptr1->guardGate();
  scavTrap_ptr2->guardGate();
  // fragTrap_ptr1->highFivesGuys();
  fragTrap_ptr2->highFivesGuys();

  delete clapTrap_ptr;
  delete scavTrap_ptr1;
  delete scavTrap_ptr2;
  delete fragTrap_ptr1;
  delete fragTrap_ptr2;

  std::cout << "\n===================================="
               "=====================================\n"
            << std::endl;

  /** Test3 : ClapTrap reference, ScavTrap reference, FragTrap reference**/
  std::cout << "\n================================= TEST3 "
               "=================================\n"
            << std::endl;
  ClapTrap &clapTrap_ref = clapTrap;
  ClapTrap &scavTrap_ref1 = scavTrap;
  ScavTrap &scavTrap_ref2 = scavTrap;
  ClapTrap &fragTrap_ref1 = fragTrap;
  FragTrap &fragTrap_ref2 = fragTrap;

  // show
  clapTrap_ref.printInfo();
  scavTrap_ref1.printInfo();
  scavTrap_ref2.printInfo();
  fragTrap_ref1.printInfo();
  fragTrap_ref2.printInfo();

  // attack
  clapTrap_ref.attack("opponent1");
  scavTrap_ref1.attack("opponent2");
  scavTrap_ref2.attack("opponent3");
  fragTrap_ref1.attack("opponent4");
  fragTrap_ref2.attack("opponent5");

  // special function
  // scavTrap_ref1.guardGate();
  scavTrap_ref2.guardGate();
  // fragTrap_ref1.highFivesGuys();
  fragTrap_ref2.highFivesGuys();
  std::cout << "\n===================================="
               "=====================================\n"
            << std::endl;
}