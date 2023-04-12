#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name) {
  std::clog << "[ DEBUG ] ScavTrap constructor Called : " << name << std::endl;
  setHitPoints(100);
  setEnergyPoints(50);
  setAttackDamage(20);
}

ScavTrap::~ScavTrap(void) {
  std::clog << "[ DEBUG ] ScavTrap destructor Called : " << getName()
            << std::endl;
}

void ScavTrap::attack(std::string const &target) {
  std::string const &name = getName();
  unsigned int hitPoints = getHitPoints();
  unsigned int energyPoints = getEnergyPoints();
  unsigned int attackDamage = getAttackDamage();

  if (hitPoints == 0) {
    std::cout << name << " : ScavTrap has no more hit points left" << std::endl;
    return;
  }
  if (energyPoints == 0) {
    std::cout << name << " : ScavTrap has no more energy points left"
              << std::endl;
    return;
  }
  setEnergyPoints(energyPoints - 1);
  std::cout << name << " : ScavTrap attacks " << target << ", causing ";
  std::cout << attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void) {
  std::cout << getName() << ": ScavTrap is now in Gate Keeper Mode!!"
            << std::endl;
}
