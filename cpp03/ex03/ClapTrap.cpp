#include "ClapTrap.hpp"

// orthodox canonical form
ClapTrap::ClapTrap(void)
    : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::clog << "[ DEBUG ] ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string const &name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::clog << "[ DEBUG ] ClapTrap string constructor called : " << name
            << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other) {
  _name = other._name;
  _hitPoints = other._hitPoints;
  _energyPoints = other._energyPoints;
  _attackDamage = other._attackDamage;
  std::clog << "[ DEBUG ] ClapTrap copy constructor called : " << _name
            << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other) {
  _name = other._name;
  _hitPoints = other._hitPoints;
  _energyPoints = other._energyPoints;
  _attackDamage = other._attackDamage;
  std::clog << "[ DEBUG ] ClapTrap assignment operator called : " << _name
            << std::endl;
  return (*this);
}

ClapTrap::~ClapTrap(void) {
  std::clog << "[ DEBUG ] ClapTrap destructor called : " << _name << "\n";
}

// actions
void ClapTrap::attack(std::string const &target) {
  if (_hitPoints == 0) {
    std::cout << _name << " : ClapTrap has no more hit points left\n";
    return;
  }
  if (_energyPoints == 0) {
    std::cout << _name << " : ClapTrap has no more energy points left\n";
    return;
  }
  _energyPoints -= 1;
  std::cout << _name << " : ClapTrap attacks " << target << ", causing ";
  std::cout << _attackDamage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (_hitPoints < amount) {
    _hitPoints = 0;
    std::cout << _name << " : ClapTrap has no more hit points left\n";
    return;
  }
  _hitPoints -= amount;
  std::cout << _name << " : ClapTrap took damage and lost " << amount
            << " Hit points\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_hitPoints == 0) {
    std::cout << _name << " : ClapTrap has no more hit points left\n";
    return;
  }
  if (_energyPoints == 0) {
    std::cout << _name << " : ClapTrap has no more energy points left\n";
    return;
  }
  _energyPoints -= 1;
  _hitPoints += amount;
  std::cout << _name << " : ClapTrap has been repaired and gained " << amount
            << " Hit points\n";
}

// tests
void ClapTrap::printStatus(void) const {
  std::cout << "================= ClapTrap Current Status ================\n";
  std::cout << " + ClapTrap Name : " << _name << "\n";
  std::cout << " + Hit Points : " << _hitPoints << "\n";
  std::cout << " + Energy Points : " << _energyPoints << "\n";
  std::cout << " + Attack Damage : " << _attackDamage << "\n";
  std::cout << "==========================================================\n";
}

void ClapTrap::setAttackDamage(unsigned int amount) { _attackDamage = amount; }
