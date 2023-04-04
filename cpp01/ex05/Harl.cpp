#include "Harl.hpp"

Harl::Harl(void)
{ 
	std::cout << "[ Harl ] Constructor called\n\n";
}

Harl::~Harl(void)
{
	std::cout << "[ Harl ] Destructor called\n\n";
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my\n";
	std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger.\n";
	std::cout << "I really do!\n\n";
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money.\n";
	std::cout << "You didn’t put enough bacon in my burger!\n";
	std::cout << "If you did, I wouldn’t be asking for more!\n\n";
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free.\n";
	std::cout << "I’ve been coming for years whereas you started working here since last month.\n\n";
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]\n";
	std::cout <<  "This is unacceptable! I want to speak to the manager now.\n\n";
}

void	Harl::extra(void)
{
	std::cout << "[ EXTRA ]\n";
	std::cout << "Probably complaining about insignificant problems\n\n";
}

void	Harl::setLevelIdx(std::string const &level)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level) 
		{
			levelIdx = i;
			return ;
		}
	}
	levelIdx = 4;
}

void	Harl::complain(std::string level)
{
	typedef	void (Harl::*fPtr)(void);
	fPtr		fptrs[5] = {&Harl::debug, &Harl::info, &Harl::warning, 
							&Harl::error, &Harl::extra};

	setLevelIdx(level);
	(this->*fptrs[levelIdx])();
}
