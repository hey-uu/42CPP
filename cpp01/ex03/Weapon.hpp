#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
 private:
  std::string _type;

 public:
  Weapon(std::string const type);
  ~Weapon();
  std::string& const getType(void) const;
  void setType(std::string const& newType);
};

std::ostream& operator<<(std::ostream& os, Weapon const& weapon);

#endif