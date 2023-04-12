#include "ScavTrap.hpp"

int	main(void)
{

std::cout << "======================== TEST1 =========================" << std::endl;
/** TEST1 : ClapTrap vs ScavTrap **/
	ClapTrap	clapTrap("Foo");
	ScavTrap	scavTrap("Bar");

	// after calling constructor
	clapTrap.printStatus();
	scavTrap.printStatus();

	// attack
	clapTrap.setAttackDamage(1);
	clapTrap.attack("opponent1");
	
	scavTrap.attack("opponent2");
	
	// guardGate
	scavTrap.guardGate();

std::cout << std::endl << std::endl;
std::cout << "========================= TEST2 =========================" << std::endl;
/** Test2 : ClapTrap *, ScavTrap * **/
	ClapTrap	*clapTrap2 = new ClapTrap("Foo");
	ClapTrap	*scavTrap2 = new ScavTrap("Bar");
	ScavTrap	*scavTrap3 = new ScavTrap("Baz");

	// show
	clapTrap2->printStatus();
	scavTrap2->printStatus();
	scavTrap3->printStatus();

	// attack
	clapTrap2->attack("opponent3");
	scavTrap2->attack("opponent4");
	scavTrap3->attack("opponent5");
	delete clapTrap2;
	delete scavTrap2;
	delete scavTrap3;
std::cout << "=========================================================" << std::endl;
}