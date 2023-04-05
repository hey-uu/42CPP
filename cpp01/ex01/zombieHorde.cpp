#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*horde = new Zombie[N];
	// for (int i = 0; i < N; i++)
	// 	horde[i] = Zombie(name);
	for (int i = 0; i < N; i++)
		horde[i].changeName(name);
	return (horde);
}
