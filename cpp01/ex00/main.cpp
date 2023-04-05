#include "Zombie.hpp"

int	main(void)
{
	std::string	name1 = "zombie1";
	std::string	name2 = "zombie2";
	std::string name3 = "zombie3";
	std::string name4 = "zombie4";
	Zombie		*zombie1 = newZombie(name1);
	Zombie		*zombie2 = newZombie(name2);
	Zombie		zombie3(name3);

	zombie1->announce();
	zombie2->announce();
	zombie3.announce();
	randomChump(name4);
	delete zombie1;
	delete zombie2;
	return (0);
}