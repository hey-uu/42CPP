#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
 public:
  Zombie(void);
  Zombie(std::string);
  ~Zombie(void);
  void announce(void);

 private:
  std::string name;
};

Zombie* newZombie(std::string name);

void randomChump(std::string name);

#endif