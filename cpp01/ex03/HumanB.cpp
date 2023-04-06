#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), _hasWeapon(false)
{
	std::cerr << "[HumanB] String constructor called  : " << *this << "\n";
}

HumanB::~HumanB(void)
{
	std::cerr << "[HumanB] Default destructor called  : " << *this << "\n";
}

void	HumanB::attack(void) const
{
	std::cout << name << " attacks with their " << *weapon <<"\n";
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_hasWeapon = true;
	this->weapon = &weapon;
}

std::string const	&HumanB::getName(void) const
{
	return (name);
}

bool const	HumanB::hasWeapon(void) const
{
	return (_hasWeapon);
}

Weapon const	&HumanB::getWeapon(void) const
{
	return (*weapon);
}

std::ostream	&operator<<(std::ostream &outputStream, HumanB const &human)
{
	if (human.hasWeapon())
		outputStream << "( " << human.getName() << ", " << human.getWeapon() << " )";
	else
		outputStream << "( " << human.getName() << ", )";
	return (outputStream);
}
