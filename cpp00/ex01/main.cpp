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

	try {
		while (1) {
			showMenu();
			std::getline(std::cin, command);
			if (std::cin.eof() == true)
				throw (std::exception());
			if (command == "EXIT")
				exitService();
			if (command == "ADD")
				phoneBook.add();
			if (command == "SEARCH")
				phoneBook.search();
			else
				phoneBook.printErr(UNAVAILABLE_CMD);
		}
	}
	catch (std::exception &e) {
		exitService();
	}
}
