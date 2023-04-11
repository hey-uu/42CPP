#include "ClapTrap.hpp"

/** PUBLIC **/
// constructor
ClapTrap::ClapTrap(std::string const &name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::clog << "[ DEBUG ] ClapTrap(name) constructor called : " << name << "\n";
}

ClapTrap::ClapTrap(std::string const &name, int hitPoints, int energyPoints,
                   int attackDamage) {
  std::clog << "[ DEBUG ] ClapTrap(name, hitPoints, energyPoints, "
               "attackDamage) constructor called : "
            << name << "\n";
}

// destructor
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

// getter
std::string const &ClapTrap::getName(void) const { 
  std::cout << _name << " : Claptrap::getName() called\n";
  return (_name); }

unsigned int ClapTrap::getHitPoints(void) const { 
  std::cout << _name << " : Claptrap::getHitPoints() called\n";
  return (_hitPoints); }

unsigned int ClapTrap::getEnergyPoints(void) const {
  std::cout << _name << " : Claptrap::getEnergyPoints() called\n";
   return (_energyPoints); }

unsigned int ClapTrap::getAttackDamage(void) const { 
  std::cout << _name << " : Claptrap::getAttackDamage() called\n";
  return (_attackDamage); }

// setter
void ClapTrap::setName(std::string const &name) {
  std::cout << _name << " : Claptrap's name is set to  " << name << "\n";
  _name = name;
}

void ClapTrap::setHitPoints(unsigned int amount) {
  std::cout << _name << " : Claptrap's hit points are set to  " << amount
            << "\n";
  _hitPoints = amount;
}

void ClapTrap::setEnergyPoints(unsigned int amount) {
  std::cout << _name << " : Claptrap's energy points are set to  " << amount
            << "\n";
  _energyPoints = amount;
}

void ClapTrap::setAttackDamage(unsigned int amount) {
  _attackDamage = amount;
  std::cout << _name << " : Claptrap's attack damage is set to " << amount
            << "\n";
}

// show
void ClapTrap::printStatus(void) const {
  std::cout << "===================== Current Status ====================\n";
  std::cout << " + Name : " << _name << "\n";
  std::cout << " + Hit Points : " << _hitPoints << "\n";
  std::cout << " + Energy Points : " << _energyPoints << "\n";
  std::cout << " + Attack Damage : " << _attackDamage << "\n";
  std::cout << "=========================================================\n";
}
