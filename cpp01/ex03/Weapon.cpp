#include "Weapon.hpp"

Weapon::Weapon(void)
{ }

Weapon::Weapon(std::string const type) : type(type)
{
	std::cout << "[Weapon] String constructor called: " << type << "\n";
}

Weapon::Weapon(Weapon const &weapon) : type(weapon.type)
{
	std::cout << "[Weapon] Copy constructor called: " << type << "\n";
}

Weapon::~Weapon(void)
{
	std::cout << "[Weapon] Default destructor called: " << type << "\n";
}

const std::string	&Weapon::getType(void) const
{
	return (type);
}

void	Weapon::setType(std::string const &newType)
{
	type = newType;
}

std::ostream	&operator<<(std::ostream &outputStream, Weapon const &weapon)
{
	outputStream << weapon.getType();
	return (outputStream);
}