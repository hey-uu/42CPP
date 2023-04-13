#include "FragTrap.hpp"

// orthodox canonical form
FragTrap::FragTrap(void) : ClapTrap() {
  _hitPoints = 100;
  _energyPoints = 100;
  _attackDamage = 30;
  std::clog << "[ DEBUG ] FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name) {
  _hitPoints = 100;
  _energyPoints = 100;
  _attackDamage = 30;
  std::clog << "[ DEBUG ] FragTrap string constructor Called : " << _name
            << std::endl;
}

FragTrap::FragTrap(FragTrap const &other) : ClapTrap(other._name) {
  _hitPoints = other._hitPoints;
  _energyPoints = other._energyPoints;
  _attackDamage = other._attackDamage;
  std::clog << "[ DEBUG ] FragTrap copy constructor Called : " << _name
            << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &other) {
  _name = other._name;
  _hitPoints = other._hitPoints;
  _energyPoints = other._energyPoints;
  _attackDamage = other._attackDamage;
  std::clog << "[ DEBUG ] FragTrap assignment operator Called : " << _name
            << std::endl;
  return (*this);
}

FragTrap::~FragTrap(void) {
  std::clog << "[ DEBUG ] FragTrap destructor Called : " << ClapTrap::_name
            << std::endl;
}

void FragTrap::highFivesGuys(void) {
  std::cout << _name << " : Let's high five guys!!" << std::endl;
}
