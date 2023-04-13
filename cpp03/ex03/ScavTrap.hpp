#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
  // orthodox canonical form
  ScavTrap(void);
  ScavTrap(std::string const &name);
  ScavTrap(ScavTrap const &other);
  ScavTrap &operator=(ScavTrap const &other);
  virtual ~ScavTrap(void);
  // overriding
  virtual void attack(std::string const &target);
  // special
  void guardGate(void);
  // show
  virtual void printStatus(void) const;
};

#endif