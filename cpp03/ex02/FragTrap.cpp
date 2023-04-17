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

FragTrap::FragTrap(FragTrap const &other) : ClapTrap(other) {
  std::clog << "[ DEBUG ] FragTrap copy constructor Called : " << _name
            << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &other) {
  if (this != &other) {
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
  }
  std::clog << "[ DEBUG ] FragTrap assignment operator Called : " << _name
            << std::endl;
  return (*this);
}

FragTrap::~FragTrap(void) {
  std::clog << "[ DEBUG ] FragTrap destructor Called : " << ClapTrap::_name
            << std::endl;
}

void FragTrap::attack(std::string const &target) {
  _printName();
  if (_isDead("FragTrap") || _isExhausted("FragTrap"))
    return;
  _energyPoints -= 1;
  std::cout << ": FragTrap attacks " << target << ", causing ";
  std::cout << _attackDamage << " points of damage!" << std::endl;
  _printEnergyPoints();
}

void FragTrap::highFivesGuys(void) {
  _printName();
  std::cout << ": Let's high five guys!!" << std::endl;
}

// extra
void FragTrap::printInfo(void) const {
  std::cout << "\n================================== INFO "
               "================================="
            << std::endl;
  std::cout << " + Type : FragTrap" << std::endl;
  std::cout << " + Name : " << _name << std::endl;
  std::cout << " + Hit Points : " << _hitPoints << std::endl;
  std::cout << " + Energy Points : " << _energyPoints << std::endl;
  std::cout << " + Attack Damage : " << _attackDamage << std::endl;
  std::cout << "=============================================================="
               "===========\n"
            << std::endl;
}