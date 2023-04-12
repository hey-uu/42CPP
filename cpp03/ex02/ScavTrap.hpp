#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
 public:
  ScavTrap(std::string const &name);
  virtual ~ScavTrap(void);
  virtual void attack(std::string const& target);
  void guardGate(void);
};

#endif