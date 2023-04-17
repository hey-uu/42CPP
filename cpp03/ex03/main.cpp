#include "DiamondTrap.hpp"

int main(void) {

  /** TEST1 : ClapTrap vs ScavTrap vs FragTrap **/
  std::cout << "\n================================= TEST1 "
               "=================================\n"
            << std::endl;
  DiamondTrap diamondTrap("SunShine");

  diamondTrap.printInfo();
  
  diamondTrap.attack("FOO");
  diamondTrap.beRepaired(10);
  diamondTrap.takeDamage(20);
  
  std::cout << std::endl;
  diamondTrap.guardGate();
  std::cout << std::endl;
  diamondTrap.highFivesGuys();
  std::cout << std::endl;
  diamondTrap.whoAmI();

  std::cout << "\n===================================="
               "=====================================\n"
            << std::endl;
}