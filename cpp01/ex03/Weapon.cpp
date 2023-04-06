#include "Weapon.hpp"

Weapon::Weapon(std::string const type) : type(type)
{
	std::cerr << "[Weapon] String constructor called  : ( " << type << " )\n";
}

Weapon::~Weapon(void)
{
	std::cerr << "[Weapon] Default destructor called  : ( " << type << " )\n";
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