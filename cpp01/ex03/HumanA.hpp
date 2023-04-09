#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include <iostream>

#include "Weapon.hpp"

class HumanA {
 private:
  std::string _name;
  Weapon& _weapon;

 public:
  HumanA(std::string const& name, Weapon& weapon);
  ~HumanA(void);
  void attack(void) const;
  void setWeapon(Weapon const& weapon);
  std::string const& getName(void) const;
  Weapon const& getWeapon(void) const;
};

std::ostream& operator<<(std::ostream& os, HumanA const& human);

#endif