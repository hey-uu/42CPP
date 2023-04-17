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
  std::clog << "[ DEBUG ] ScavTrap string constructor called : " << _name
            << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &other) : ClapTrap(other) {
  std::clog << "[ DEBUG ] ScavTrap copy constructor called : " << _name
            << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other) {
  if (this != &other) {
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
  }
  std::clog << "[ DEBUG ] ScavTrap assignment operator called : " << _name
            << std::endl;
  return (*this);
}

ScavTrap::~ScavTrap(void) {
  std::clog << "[ DEBUG ] ScavTrap destructor called : " << _name << std::endl;
}

// overriding
void ScavTrap::attack(std::string const &target) {
  _printName();
  if (_isDead("ScavTrap") || _isExhausted("ScavTrap"))
    return;
  _energyPoints -= 1;
  std::cout << ": ScavTrap attacks " << target << ", causing ";
  std::cout << _attackDamage << " points of damage!" << std::endl;
  _printEnergyPoints();
}

// special function
void ScavTrap::guardGate(void) {
  _printName();
  std::cout << ": ScavTrap is now in Gate Keeper Mode!!" << std::endl;
}
