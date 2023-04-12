#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
public:
  ClapTrap(std::string const &name);
  virtual ~ClapTrap(void);
  // actions
  virtual void attack(std::string const &target);
  virtual void takeDamage(unsigned int amount);
  virtual void beRepaired(unsigned int amount);
  // getter
  virtual std::string const &getName(void) const;
  virtual unsigned int getHitPoints(void) const;
  virtual unsigned int getEnergyPoints(void) const;
  virtual unsigned int getAttackDamage(void) const;
  // setter
  virtual void setName(std::string const &name);
  virtual void setHitPoints(unsigned int amount);
  virtual void setEnergyPoints(unsigned int amount);
  virtual void setAttackDamage(unsigned int amount);
  // show
  virtual void printStatus(void) const;

private:
  std::string _name;
  unsigned int _hitPoints;
  unsigned int _energyPoints;
  unsigned int _attackDamage;
};

#endif