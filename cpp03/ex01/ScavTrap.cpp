#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name, 100, 50, 20) {
  std::clog << "[ DEBUG ] ScravTrap constructor Called : " << name << "\n";
}

ScavTrap::~ScavTrap(void) {
  std::clog << "[ DEBUG ] ScravTrap destructor Called : " << getName() << "\n";
}

void ScavTrap::attack(std::string const &target) {
  if (getHitPoints() == 0) {
    std::cout << getName() << " : ScavTrap has no more hit points left\n";
    return;
  }
  if (getEnergyPoints() == 0) {
    std::cout << getName() << " : ScavTrap has no more energy points left\n";
    return;
  }
  setEnergyPoints(getEnergyPoints() - 1);
  std::cout << getName() << " : ScavTrap attacks " << target << ", causing ";
  std::cout << getAttackDamage() << " points of damage!\n";
}

void ScavTrap::takeDamage(unsigned int amount) {
  if (getHitPoints() < amount) {
    
    std::cout << _name << " : ScavTrap has no more hit points left\n";
    return;
  }
  _hitPoints -= amount;
  std::cout << _name << " : ScavTrap took damage and lost " << amount
            << " Hit points\n";
}

void ScavTrap::beRepaired(unsigned int amount) {
  if (_hitPoints == 0) {
    std::cout << _name << " : ScavTrap has no more hit points left\n";
    return;
  }
  if (_energyPoints == 0) {
    std::cout << _name << " : ScavTrap has no more energy points left\n";
    return;
  }
  _energyPoints -= 1;
  _hitPoints += amount;
  std::cout << _name << " : ScavTrap has been repaired and gained " << amount
            << " Hit points\n";
}

void ScavTrap::setAttackDamage(unsigned int amount) {
  _attackDamage = amount;
  std::cout << _name << " : ScavTrap's attack damage is set to " << amount
            << "\n";
}

void ScavTrap::printStatus(void) const {
  std::cout << "===================== Current Status ====================\n";
  std::cout << " + Name : " << _name << "\n";
  std::cout << " + Hit Points : " << _hitPoints << "\n";
  std::cout << " + Energy Points : " << _energyPoints << "\n";
  std::cout << " + Attack Damage : " << _attackDamage << "\n";
  std::cout << "=========================================================\n";
}
