#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
public:
  // orthodox canonical form
  ClapTrap(void);
  ClapTrap(std::string const &name);
  ClapTrap(ClapTrap const &other);
  ClapTrap &operator=(ClapTrap const &other);
  virtual ~ClapTrap(void);
  // actions
  virtual void attack(std::string const &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  // extra
  virtual void printInfo(void) const;
  void setAttackDamage(unsigned int amount);

protected:
  std::string _name;
  unsigned int _hitPoints;
  unsigned int _energyPoints;
  unsigned int _attackDamage;

  static const int _kWidth = 20;

  // extra
  bool _isDead(std::string const &type) const;
  bool _isExhausted(std::string const &type) const;
  void _printName(void) const;
  void _printHitPoints(void) const;
  void _printEnergyPoints(void) const;
};

#endif