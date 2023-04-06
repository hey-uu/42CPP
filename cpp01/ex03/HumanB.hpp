#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB
{
private:
	std::string	name;
	Weapon		*weapon;
	bool		_hasWeapon;
public:
	HumanB(std::string name);
	~HumanB(void);
	void				attack(void) const;
	bool const			hasWeapon(void) const;
	void				setWeapon(Weapon &weapon);
	std::string const	&getName(void) const;
	Weapon const		&getWeapon(void) const;
};

std::ostream	&operator<<(std::ostream &outputStream, HumanB const &human);

#endif