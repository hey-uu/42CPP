#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
public:
  DiamondTrap(std::string const &name, std::string const &clapName);
  virtual ~DiamondTrap(void);
  virtual void attack(std::string const &target);
  // special function
  void whoAmI(void);
  // getter
  virtual std::string const &getName(void) const;
  virtual unsigned int getHitPoints(void) const;
  virtual unsigned int getEnergyPoints(void) const;
  virtual unsigned int getAttackDamage(void) const;
  std::string const &DiamondTrap::getClapTrapName(void) const;
  // setter
  virtual void setName(std::string const &name);
  virtual void setHitPoints(unsigned int amount);
  virtual void setEnergyPoints(unsigned int amount);
  virtual void setAttackDamage(unsigned int amount);
  void DiamondTrap::setClapTrapName(std::string const &name);
  // show
  virtual void printStatus(void) const;

private:
  std::string _name;
};

#endif