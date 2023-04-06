#include "Zombie.hpp"

Zombie::Zombie(void)
{ 
	std::cerr << "Default constructor called\n";
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cerr << "String constructor called: " << name << "\n";
}

Zombie::~Zombie(void)
{
	std::cerr << "Destructor called: " << name << "\n";
}

// void	Zombie::announce(void) const
void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
