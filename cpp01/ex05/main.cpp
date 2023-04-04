#include "Harl.hpp"

int	main(void)
{
	std::string levels[] = {
		"DEBUG", "INFO", "WARNING", "ERROR",
		"DEBUG\n", "INFO\n", "WARNING\n", "ERROR\n",
		"THIS IS STRANGE"
	};
	Harl	harl;

	for (int i = 0; i < 9; i++)
		harl.complain(levels[i]);
	return (0);
}