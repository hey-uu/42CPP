#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
  FragTrap(std::string const &name);
  virtual ~FragTrap(void);
  virtual void attack(std::string const &target);
  void highFivesGuys(void);
};

#endif