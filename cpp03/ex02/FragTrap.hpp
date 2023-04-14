#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
  // orthodox canonical form
  FragTrap(void);
  FragTrap(std::string const &name);
  FragTrap(FragTrap const &other);
  FragTrap &operator=(FragTrap const &other);
  virtual ~FragTrap(void);
  // special functions
  void highFivesGuys(void);
};

#endif