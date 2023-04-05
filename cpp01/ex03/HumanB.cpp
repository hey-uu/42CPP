#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
	std::cout << "[Weapon] Strings constructor called: " << *this << "\n";
}

HumanB::~HumanB(void)
{
	std::cout << "[Weapon] Default destructor called: " << *this << "\n";
}

void	HumanB::attack(void) const
{
	std::cout << name << " attacks with their " << *weapon <<"\n";
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

const std::string	&HumanB::getName(void) const
{
	return (name);
}

const Weapon	&HumanB::getWeapon(void) const
{
	return (*weapon);
}

std::ostream	&operator<<(std::ostream &outputStream, HumanB const &human)
{
	std::cout << "( " << human.getName() << ", " << human.getWeapon() << " )";
	return (outputStream);
}
