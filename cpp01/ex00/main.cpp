#include "Zombie.hpp"

int main(void) {
  std::string name1 = "zombie1";
  std::string name2 = "zombie2";
  std::string name3 = "zombie3";
  std::string name4 = "zombie4";

  Zombie* zombie1 = newZombie(name1);
  Zombie* zombie2 = newZombie(name2);
  Zombie zombie3(name3);

  zombie1->announce();
  delete zombie1;

  zombie2->announce();
  delete zombie2;

  zombie3.announce();
  randomChump(name4);
  return (0);
}
