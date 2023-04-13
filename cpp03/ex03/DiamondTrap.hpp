#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
public:
  // orthodox canonical form
  DiamondTrap(void);
  DiamondTrap(std::string const &name);
  DiamondTrap(DiamondTrap const &other);
  DiamondTrap &operator=(DiamondTrap const &other);
  virtual ~DiamondTrap(void);
  // actions
  virtual void attack(std::string const &target);
  // special function
  void whoAmI(void);
  // show
  virtual void printStatus(void) const;

private:
  std::string _name;
  using FragTrap::_attackDamage;
  using FragTrap::_hitPoints;
  using ScavTrap::_energyPoints;
};

#endif