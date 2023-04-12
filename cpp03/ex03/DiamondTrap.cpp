#include "DiamondTrap.hpp"

// constructor
DiamondTrap::DiamondTrap(std::string const &name, std::string const &)
    : ClapTrap(name) {
  std::clog << "[ DEBUG ] DiamondTrap constructor Called : " << name << std::endl;
  setHitPoints(100);
  setEnergyPoints(100);
  setAttackDamage(30);
}

// destructor
DiamondTrap::~DiamondTrap(void) {
  std::clog << "[ DEBUG ] DiamondTrap destructor Called : " << getName()
            << std::endl;
}

// action
void DiamondTrap::attack(std::string const &target) {
  ScavTrap::attack(target);
}

// special
void DiamondTrap::whoAmI(void) {
  std::cout << "DiamondTrap Name : " << getName() << std::endl;
}

// getter
std::string const &DiamondTrap::getName(void) const { return (_name); }

std::string const &DiamondTrap::getClapTrapName(void) const {
  return (ScavTrap::getName());
}

unsigned int DiamondTrap::getHitPoints(void) const { return (FragTrap::getHitPoints()); }

unsigned int DiamondTrap::getEnergyPoints(void) const {
  return (ScavTrap::getEnergyPoints());
}

unsigned int DiamondTrap::getAttackDamage(void) const {
  return (FragTrap::getAttackDamage());
}

// setter
void DiamondTrap::setName(std::string const &name) { _name = name; }

void DiamondTrap::setClapTrapName(std::string const &name) {
  ClapTrap::setName(name);
}

void DiamondTrap::setHitPoints(unsigned int amount) { _hitPoints = amount; }

void DiamondTrap::setEnergyPoints(unsigned int amount) {
  _energyPoints = amount;
}

void DiamondTrap::setAttackDamage(unsigned int amount) {
  _attackDamage = amount;
}