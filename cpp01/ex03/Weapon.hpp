#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
private:
	std::string	type;

public:
	Weapon(std::string const type);
	~Weapon();
	const std::string	&getType(void) const;
	void				setType(std::string const &newType);
};

std::ostream	&operator<<(std::ostream &outputStream, Weapon const &weapon);

#endif