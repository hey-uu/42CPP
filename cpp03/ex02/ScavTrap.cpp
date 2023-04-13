#include "ScavTrap.hpp"

// orthodox canonical form
ScavTrap::ScavTrap(void) : ClapTrap() {
  _hitPoints = 100;
  _energyPoints = 50;
  _attackDamage = 20;
  std::clog << "[ DEBUG ] ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name) {
  _hitPoints = 100;
  _energyPoints = 50;
  _attackDamage = 20;
  std::clog << "[ DEBUG ] ScavTrap string constructor Called : " << _name
            << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &other) : ClapTrap(other._name) {
  _hitPoints = other._hitPoints;
  _energyPoints = other._energyPoints;
  _attackDamage = other._attackDamage;
  std::clog << "[ DEBUG ] ScavTrap copy constructor Called : " << _name
            << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other) {
  _name = other._name;
  _hitPoints = other._hitPoints;
  _energyPoints = other._energyPoints;
  _attackDamage = other._attackDamage;
  std::clog << "[ DEBUG ] ScavTrap assignment operator Called : " << _name
            << std::endl;
  return (*this);
}

ScavTrap::~ScavTrap(void) {
  std::clog << "[ DEBUG ] ScavTrap destructor Called : " << ClapTrap::_name
            << std::endl;
}

// overriding
void ScavTrap::attack(std::string const &target) {
  if (_hitPoints == 0) {
    std::cout << _name << " : ScavTrap has no more hit points left"
              << std::endl;
    return;
  }
  if (_energyPoints == 0) {
    std::cout << _name << " : ScavTrap has no more energy points left"
              << std::endl;
    return;
  }
  _energyPoints -= 1;
  std::cout << _name << " : ScavTrap attacks " << target << ", causing ";
  std::cout << _attackDamage << " points of damage!" << std::endl;
}

// special function
void ScavTrap::guardGate(void) {
  std::cout << ClapTrap::_name << ": ScavTrap is now in Gate Keeper Mode!!"
            << std::endl;
}
