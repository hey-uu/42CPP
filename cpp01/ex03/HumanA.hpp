#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
private:
	std::string	name;
	Weapon		&weapon;
public:
	HumanA(std::string const &name, Weapon &weapon);
	~HumanA(void);
	void				attack(void) const;
	void				setWeapon(Weapon const &weapon);
	const std::string	&getName(void) const;
	const Weapon		&getWeapon(void) const;
};

std::ostream	&operator<<(std::ostream &outputStream, HumanA const &human);

#endif