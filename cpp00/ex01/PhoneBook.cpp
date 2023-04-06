#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	lastIdx = -1;
	count = 0;
}

bool	PhoneBook::add(void)
{
	std::string	contactInfo[5];

	if (Contact::getContactInput(contactInfo) == false)
		return (false);
	lastIdx = (lastIdx + 1) & 7;
	contacts[lastIdx].initialize(contactInfo);
	if (count < 8)
		count++;
	return (true);
}

void	PhoneBook::showSummary(void) const
{
	std::cout << "\n";
	std::cout << "==============================================================\n";
	std::cout << "                    Phone Book Information                    \n";
	std::cout << "==============================================================\n";
	std::cout << "         +-------------------------------------------+\n";
	std::cout << "         |  index   |first name|last name | nickname |\n";
	std::cout << "         |----------+----------+----------+----------|\n";
	for (int i = 0 ; i < count ; i++) {
		std::cout << "         ";
		contacts[i].showSummary();
		if (i != count - 1)
			std::cout << "         |----------+----------+----------+----------|\n";
	}
	std::cout << "         +-------------------------------------------+\n" << std::endl;
}

bool	PhoneBook::search(void) const
{
	int	idx;

	showSummary();
	while (1) {
		std::cout << " * Enter index of the entry to display.\n";
		std::cout << "   Enter -1 if you want to stop         : " << std::flush;
		std::cin >> idx;
		if (std::cin.eof() == true) return (false);
		if (std::cin.fail() == true) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\n [ERROR] : Index has wrong value\n";
		}
		else if (idx < -1 || idx >= count)
			std::cout << "\n [ERROR] : Index is out of range\n";
		else if (idx == -1) return (true);
		else break ;
	}
	contacts[idx].showInfo();
	return (true);
}
