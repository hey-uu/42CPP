#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
private:
	std::string	type;

public:
	Weapon();
	Weapon(std::string const type);
	Weapon(Weapon const &weapon);
	~Weapon();
	const std::string	&getType(void) const;
	void				setType(std::string const &newType);
};

std::ostream	&operator<<(std::ostream &outputStream, Weapon const &weapon);

#endif