#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB
{
private:
	std::string	name;
	Weapon		*weapon;
public:
	HumanB(std::string name);
	~HumanB(void);
	void				attack(void) const;
	void				setWeapon(Weapon &weapon);
	const std::string	&getName(void) const;
	const Weapon		&getWeapon(void) const;
};

std::ostream	&operator<<(std::ostream &outputStream, HumanB const &human);

#endif