#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
public:
  ClapTrap(std::string const &name);
  ClapTrap(std::string const &name, int hitPoints, int energyPoints,
           int attackDamage);
  virtual ~ClapTrap(void);
  // actions
  virtual void attack(std::string const &target);
  virtual void takeDamage(unsigned int amount);
  virtual void beRepaired(unsigned int amount);
  // getter
  std::string const &getName(void) const;
  unsigned int getHitPoints(void) const;
  unsigned int getEnergyPoints(void) const;
  unsigned int getAttackDamage(void) const;
  // setter
  void setName(std::string const &name);
  void setHitPoints(unsigned int amount);
  void setEnergyPoints(unsigned int amount);
  void setAttackDamage(unsigned int amount);
  // show
  virtual void printStatus(void) const;

private:
  std::string _name;
  unsigned int _hitPoints;
  unsigned int _energyPoints;
  unsigned int _attackDamage;
};

#endif