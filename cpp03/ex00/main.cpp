#include "ClapTrap.hpp"

int main(void) {
  const int repairAmount[6] = {4, 3, 2, 1, 0, 0};
  const int damageAmount[6] = {1, 2, 3, 4, 5, 6};
  ClapTrap foo("Foo");

  foo.printInfo();
  for (int i = 0; i < 6; i++) {
    foo.setAttackDamage(i);
    foo.attack("Bar");
    foo.beRepaired(repairAmount[i]);
    foo.takeDamage(damageAmount[i]);
    foo.printInfo();
  }
}
