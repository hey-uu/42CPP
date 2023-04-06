#include "PhoneBook.hpp"
#include <iostream>
#include <string>

void	showMenu(void)
{
	if (std::cin.eof() == true)
		return ;
	std::cout << "\n";
	std::cout << "==============================================================\n";
	std::cout << "                     Phone Book Service!                      \n";
	std::cout << "==============================================================\n";
	std::cout << " * Please choose a command from the following options:\n";
	std::cout << "   (ADD, SEARCH, EXIT)\n";
	std::cout << "==============================================================\n";
	std::cout << " > " << std::flush;
}

void	exitService(void)
{
	std::cout << "\n";
	std::cout << "==============================================================\n";
	std::cout << "                          Good Bye!                          \n";
	std::cout << "==============================================================\n";
	std::cout << " * Thanks for using our service.\n";
	std::cout << "==============================================================\n";
	std::cout << std::endl;
	exit(0);
}

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	command;

	while (1)
	{
		showMenu();
		std::cin >> command;
		if (std::cin.eof() == true || command == "EXIT")
			exitService();
		if (command == "ADD") { 
			if (phoneBook.add() == false)
				exitService();
		}
		else if (command == "SEARCH") {
			if (phoneBook.search() == false)
				exitService();
		}
		else
			std::cout << "\n [ERR0R] : Unavailable command. Enter again." << std::endl;
	}
}
