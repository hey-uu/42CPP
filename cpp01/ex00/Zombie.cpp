#include "Zombie.hpp"

Zombie::Zombie(void)
{ 
	std::cout << "Default constructor called\n";
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "String constructor called: " << name << "\n";
}

Zombie::~Zombie(void)
{
	std::cout << "Destructor called: " << name << "\n";
}

void	Zombie::announce(void) const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
