#include "FragTrap.hpp"

FragTrap::FragTrap(std::string const &name) : ClapTrap(name) {
  std::clog << "[ DEBUG ] FragTrap constructor Called : " << name << std::endl;
  setHitPoints(100);
  setEnergyPoints(100);
  setAttackDamage(30);
}

FragTrap::~FragTrap(void) {
  std::clog << "[ DEBUG ] FragTrap destructor Called : " << getName()
            << std::endl;
}

void FragTrap::attack(std::string const &target) {
  std::string const &name = getName();
  unsigned int hitPoints = getHitPoints();
  unsigned int energyPoints = getEnergyPoints();
  unsigned int attackDamage = getAttackDamage();

  if (hitPoints == 0) {
    std::cout << name << " : FragTrap has no more hit points left" << std::endl;
    return;
  }
  if (energyPoints == 0) {
    std::cout << name << " : FragTrap has no more energy points left"
              << std::endl;
    return;
  }
  setEnergyPoints(energyPoints - 1);
  std::cout << name << " : FragTrap attacks " << target << ", causing ";
  std::cout << attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
  std::cout << getName() << " : Let's high five guys!!" << std::endl;
}
