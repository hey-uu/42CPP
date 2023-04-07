#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
private:
	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;
public:
				ClapTrap(std::string const &name);
	void		printStatus(void) const;
	void		attack(std::string const &target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	
}

namespace	log 
{
	namespace debug 
	{
		const std::string	kConstructorCalled = 
								"[ Debug ] Constructor Called : ";
	}
	namespace info_type
	{
		const std::string	kName = "Name : ";
		const std::string	kHitPoints = "Hit Points : ";
		const std::string	kEnergyPoints = "Energy Points : ";
		const std::string	kAttackDamage = "Attack Damage : ";
	}
	const std::string		kCurrentStatus =
								"====== Current Status =====";
	const std::string		kZeroHitPoint = 
								" : ClapTrap has zero hit point."
	const std::string		kNoEnergyPoints =
								" : ClapTrap has no more energy points left";
	const std::string		kAttack1 =
								" : ClapTrap attacks "; // targetName
	const std::string		kAttack2 =
								", causing "; // _attackDamage
	const std::string		kAttack3 =
								" points of damage!";
	const std::string		kTakeDamage1 =
								" : ClapTrap took damage and lost " // amount
	const std::string		kTakeDamage2 =
								" Hit points"
	const std::string		kBeRepaired1 =
								" : ClapTrap has been repaired and gained "
	const std::string		kBeRepaired2 =
								" Hit points"
}

#endif