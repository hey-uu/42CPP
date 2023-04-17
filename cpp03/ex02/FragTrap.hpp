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
  // overriding
  virtual void attack(std::string const &target);
  // special
  void highFivesGuys(void);
  // extra
  virtual void printInfo(void) const;
};

#endif