#include "ClapTrap.hpp"
#include <iomanip>

// orthodox canonical form
ClapTrap::ClapTrap(void)
    : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::clog << "[ DEBUG ] ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string const &name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::clog << "[ DEBUG ] ClapTrap String constructor called : " << name
            << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other) {
  _name = other._name;
  _hitPoints = other._hitPoints;
  _energyPoints = other._energyPoints;
  _attackDamage = other._attackDamage;
  std::clog << "[ DEBUG ] ClapTrap Copy constructor called : " << _name
            << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other) {
  if (this != &other) {
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
  }
  std::clog << "[ DEBUG ] ClapTrap Assignment operator called : " << _name
            << std::endl;
  return (*this);
}

ClapTrap::~ClapTrap(void) {
  std::clog << "[ DEBUG ] ClapTrap Destructor called : " << _name << std::endl;
}

// actions
void ClapTrap::attack(std::string const &target) {
  _printName();
  if (_isDead("ClapTrap") || _isExhausted("ClapTrap"))
    return;
  _energyPoints -= 1;
  std::cout << ": ClapTrap attacks " << target << ", causing ";
  std::cout << _attackDamage << " points of damage!" << std::endl;
  _printEnergyPoints();
}

void ClapTrap::takeDamage(unsigned int amount) {
  _printName();
  std::cout << ": ClapTrap had " << _hitPoints << " hit points and took "
            << amount << " hit points damage. " << std::endl;
  if (_hitPoints <= amount) {
    _hitPoints = 0;
    std::cout << std::setw(_kWidth + 3) << " "
              << "Now it is dead... (hit points = 0)" << std::endl;
  } else {
    _hitPoints -= amount;
    _printHitPoints();
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  _printName();
  if (_isDead("ClapTrap") || _isExhausted("ClapTrap"))
    return;
  _energyPoints -= 1;
  _hitPoints += amount;
  std::cout << ": ClapTrap has been repaired and gained " << amount
            << " hit points" << std::endl;
  _printHitPoints();
  _printEnergyPoints();
}

// tests
void ClapTrap::printStatus(void) const {
  std::cout << "\n================================== INFO "
               "================================="
            << std::endl;
  std::cout << " + Name : " << _name << std::endl;
  std::cout << " + Hit Points : " << _hitPoints << std::endl;
  std::cout << " + Energy Points : " << _energyPoints << std::endl;
  std::cout << " + Attack Damage : " << _attackDamage << std::endl;
  std::cout << "=============================================================="
               "===========\n"
            << std::endl;
}

void ClapTrap::setAttackDamage(unsigned int amount) { _attackDamage = amount; }

void ClapTrap::_printName(void) const {
  std::cout << std::setw(_kWidth) << std::left << _name << " ";
}

void ClapTrap::_printHitPoints(void) const {
  std::cout << std::setw(_kWidth + 3) << " "
            << "(hit points = " << _hitPoints << ")" << std::endl;
}

void ClapTrap::_printEnergyPoints(void) const {
  std::cout << std::setw(_kWidth + 3) << " "
            << "(energy points = " << _energyPoints << ")" << std::endl;
}

bool ClapTrap::_isDead(std::string const &type) const {
  if (_hitPoints != 0)
    return (false);
  std::cout << ": " << type << " is dead... (hit points = 0)" << std::endl;
  return (true);
}

bool ClapTrap::_isExhausted(std::string const &type) const {
  if (_energyPoints != 0)
    return (false);
  std::cout << ": " << type << " is exhausted... (energy points = 0)"
            << std::endl;
  return (true);
}