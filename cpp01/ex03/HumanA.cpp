#include "HumanA.hpp"

HumanA::HumanA(std::string const &name, Weapon &weapon) 
		: name(name), weapon(weapon)
{
	std::cout << "[HumanA] Complex constructor called: " << *this << "\n";
}

HumanA::~HumanA(void)
{
	std::cout << "[HumanA] Default destructor called: " << *this << "\n";
}

void	HumanA::attack(void) const
{
	std::cout << name << " attacks with their " << weapon <<"\n";
}

void	HumanA::setWeapon(Weapon const &weapon)
{
	this->weapon = weapon;
}

const std::string	&HumanA::getName(void) const
{
	return (name);
}

const Weapon	&HumanA::getWeapon(void) const
{
	return (weapon);
}

std::ostream	&operator<<(std::ostream &outputStream, HumanA const &human)
{
	std::cout << "( " << human.getName() << ", " << human.getWeapon() << " )";
	return (outputStream);
}
