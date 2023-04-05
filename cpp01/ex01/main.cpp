#include "Zombie.hpp"

int	main(void)
{
	const int	N = 10;
	std::string	name = "PUHAKHAK";

	Zombie	*horde = zombieHorde(N, name);
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete []horde;
	return (0);
}