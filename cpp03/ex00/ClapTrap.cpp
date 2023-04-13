#include "ClapTrap.hpp"

// orthodox canonical form
ClapTrap::ClapTrap(void)
    : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::clog << "[ DEBUG ] Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string const &name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::clog << "[ DEBUG ] String constructor called : " << name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other) {
  _name = other._name;
  _hitPoints = other._hitPoints;
  _energyPoints = other._energyPoints;
  _attackDamage = other._attackDamage;
  std::clog << "[ DEBUG ] Copy constructor called : " << _name << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other) {
  _name = other._name;
  _hitPoints = other._hitPoints;
  _energyPoints = other._energyPoints;
  _attackDamage = other._attackDamage;
  std::clog << "[ DEBUG ] Assignment operator called : " << _name << std::endl;
  return (*this);
}

ClapTrap::~ClapTrap(void) {
  std::clog << "[ DEBUG ] Destructor called : " << _name << std::endl;
}

// actions
void ClapTrap::attack(std::string const &target) {
  if (_hitPoints == 0) {
    std::cout << _name << " : ClapTrap has no more hit points left"
              << std::endl;
    return;
  }
  if (_energyPoints == 0) {
    std::cout << _name << " : ClapTrap has no more energy points left"
              << std::endl;
    return;
  }
  _energyPoints -= 1;
  std::cout << _name << " : ClapTrap attacks " << target << ", causing ";
  std::cout << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (_hitPoints < amount) {
    _hitPoints = 0;
    std::cout << _name << " : ClapTrap has no more hit points left"
              << std::endl;
    return;
  }
  _hitPoints -= amount;
  std::cout << _name << " : ClapTrap took damage and lost " << amount
            << " Hit points" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_hitPoints == 0) {
    std::cout << _name << " : ClapTrap has no more hit points left"
              << std::endl;
    return;
  }
  if (_energyPoints == 0) {
    std::cout << _name << " : ClapTrap has no more energy points left"
              << std::endl;
    return;
  }
  _energyPoints -= 1;
  _hitPoints += amount;
  std::cout << _name << " : ClapTrap has been repaired and gained " << amount
            << " Hit points" << std::endl;
}

// tests
void ClapTrap::printStatus(void) const {
  std::cout << "===================== Current Status ===================="
            << std::endl;
  std::cout << " + Name : " << _name << std::endl;
  std::cout << " + Hit Points : " << _hitPoints << std::endl;
  std::cout << " + Energy Points : " << _energyPoints << std::endl;
  std::cout << " + Attack Damage : " << _attackDamage << std::endl;
  std::cout << "========================================================="
            << std::endl;
}

void ClapTrap::setAttackDamage(unsigned int amount) { _attackDamage = amount; }
