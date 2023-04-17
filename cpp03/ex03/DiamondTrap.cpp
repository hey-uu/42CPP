#include "DiamondTrap.hpp"
#include <iomanip>

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
  if (this != &other) {
    _name = other._name;
    ClapTrap::_name = other.ClapTrap::_name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
  }
  std::clog << "[ DEBUG ] DiamondTrap assignment operator Called : " << _name
            << std::endl;
  return (*this);
}

DiamondTrap::~DiamondTrap(void) {
  std::clog << "[ DEBUG ] DiamondTrap destructor Called : " << _name
            << std::endl;
}

// overriding
void DiamondTrap::attack(std::string const &target) {
  ScavTrap::attack(target);
}

// special
void DiamondTrap::whoAmI(void) {
  std::cout << "DiamondTrap Name is " << _name << std::endl;
  std::cout << "ClapTrap Name is " << ClapTrap::_name << std::endl;
}

// show
void DiamondTrap::printInfo(void) const {
  std::cout << "\n================================== INFO "
               "================================="
            << std::endl;
  std::cout << " + Type : DiamondTrap" << std::endl;
  std::cout << " + Name : " << std::endl;
  std::cout << "    + DiamondTrap Name : " << _name << std::endl;
  std::cout << "    + ClapTrap Name    : " << ClapTrap::_name << std::endl;
  std::cout << " + Hit Points : " << _hitPoints << std::endl;
  std::cout << " + Energy Points : " << _energyPoints << std::endl;
  std::cout << " + Attack Damage : " << _attackDamage << std::endl;
  std::cout << "=============================================================="
               "===========\n"
            << std::endl;
}
