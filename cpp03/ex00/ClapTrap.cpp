#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string const &name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::clog << log::debug::kConstructorCalled << name << std::endl;
}

void	ClapTrap::attack(std::string const &target)
{
	if (_energyPoints == 0) {
		std::cout << _name << log::kNoEnergyPoints << std::endl;
		printStatus();
		return ;
	}
	_energyPoints -= 1;
	std::cout << __name << log::kAttack1 << target << log::kAttack2;
	std::cout << _attackDamage << log::kAttack3 << std::endl;
	printStatus();
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	_hitPoints -= amount;
	std::cout << log::kTakeDamage1 << amount << log::kTakeDamage2 << std::endl;
	printStatus();
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints == 0) {
		std::cout << _name << log::kNoEnergyPoints << std::endl;
		printStatus();
		return ;
	}
	_energyPoints -= 1;
	_hitPoints += amount;
	std::cout << log::kBeRepaired1 << amount << log::kBeRepaired2 << std::endl;
	printStatus();
}

void	ClapTrap::printStatus(void) const
{
	std::cout << log::kCurrentStatus << "\n";
	std::cout << log::info_type::kName << _name << "\n";
	std::cout << log::info_type::kHitPoints << _hitPoints << "\n";
	std::cout << log::info_type::kEnergyPoints << _energyPoints << "\n";
	std::cout << log::info_type::kAttackDamage << _attackDamage << std::endl;
}
