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
	bool const			hasWeapon(void) const;
	void				setWeapon(Weapon const &weapon);
	std::string const	&getName(void) const;
	Weapon const		&getWeapon(void) const;
};

std::ostream	&operator<<(std::ostream &outputStream, HumanA const &human);

#endif