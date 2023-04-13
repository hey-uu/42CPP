#include "DiamondTrap.hpp"

// orthodox canonical form
DiamondTrap::DiamondTrap(void) : ScavTrap(), FragTrap() {
  std::clog << "[ DEBUG ] DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string const &name) : ScavTrap(), FragTrap() {
  _name = name;
  ClapTrap::_name = name + "_clap_name";
  std::clog << "[ DEBUG ] DiamondTrap string constructor Called : " << _name
            << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &other) : ScavTrap(), FragTrap() {
  _name = other._name;
  ClapTrap::_name = other.ClapTrap::_name;
  _hitPoints = other._hitPoints;
  _energyPoints = other._energyPoints;
  _attackDamage = other._attackDamage;
  std::clog << "[ DEBUG ] DiamondTrap copy constructor Called : " << _name
            << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other) {
  _name = other._name;
  ClapTrap::_name = other.ClapTrap::_name;
  _hitPoints = other._hitPoints;
  _energyPoints = other._energyPoints;
  _attackDamage = other._attackDamage;
  std::clog << "[ DEBUG ] DiamondTrap assignment operator Called : " << _name
            << std::endl;
  return (*this);
}

DiamondTrap::~DiamondTrap(void) {
  std::clog << "[ DEBUG ] DiamondTrap destructor Called : " << ClapTrap::_name
            << std::endl;
}

// overriding
void DiamondTrap::attack(std::string const &target) {
  ScavTrap::attack(target);
}

// special
void DiamondTrap::whoAmI(void) {
  std::cout << "DiamondTrap Name : " << _name << std::endl;
}

// show
void DiamondTrap::printStatus(void) const {
  std::cout << "================= DiamondTrap Current Status ================\n";
  std::cout << " + DiamondTrap Name : " << _name << "\n";
  std::cout << " + ClapTrap Name : " << ClapTrap::_name << "\n";
  std::cout << " + Hit Points : " << _hitPoints << "\n";
  std::cout << " + Energy Points : " << _energyPoints << "\n";
  std::cout << " + Attack Damage : " << _attackDamage << "\n";
  std::cout << "==========================================================\n";
}