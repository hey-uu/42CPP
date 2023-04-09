#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
 private:
  std::string _name;
  unsigned int _hitPoints;
  unsigned int _energyPoints;
  unsigned int _attackDamage;

 public:
  ClapTrap(std::string const& name);
  ~ClapTrap(void);
  void printStatus(void) const;
  void attack(std::string const& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  void setAttackDamage(unsigned int amount);
};

#endif