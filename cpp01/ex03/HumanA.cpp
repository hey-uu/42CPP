#include "HumanA.hpp"

HumanA::HumanA(std::string const &name, Weapon &weapon) 
		: name(name), weapon(weapon)
{
	std::cerr << "[HumanA] Complex constructor called : " << *this << "\n";
}

HumanA::~HumanA(void)
{
	std::cerr << "[HumanA] Default destructor called  : " << *this << "\n";
}

void	HumanA::attack(void) const
{
	std::cout << name << " attacks with their " << weapon <<"\n";
}

bool const	HumanA::hasWeapon(void) const
{
	return (true);
}

void	HumanA::setWeapon(Weapon const &weapon)
{
	this->weapon = weapon;
}

std::string const	&HumanA::getName(void) const
{
	return (name);
}

Weapon const	&HumanA::getWeapon(void) const
{
	return (weapon);
}

std::ostream	&operator<<(std::ostream &outputStream, HumanA const &human)
{
	outputStream << "( " << human.getName() << ", " << human.getWeapon() << " )";
	return (outputStream);
}
