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

bool	PhoneBook::search(void) const
{
	int	idx;

	showSummary();
	while (1) {
		std::cout << " * Enter index of the entry to display.\n";
		std::cout << "   Enter -1 if you want to stop.         : " << std::flush;
		idx = 0;
		std::cin >> idx;
		if (std::cin.eof() == true)
			throw (std::exception());
		if (std::cin.fail() == true)
			printErr(WRONG_VALUE);
		else if (idx < -1 || idx >= count)
			printErr(OUT_OF_RANGE);
		else if (idx == -1)
			return (true);
		else
			break ;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	contacts[idx].showInfo();
	return (true);
}

void	PhoneBook::printErr(int errCode) const
{
	const std::string	errMsg[] = {
		[WRONG_VALUE] = ERRMSG_WRONG_VALUE,
		[OUT_OF_RANGE] = ERRMSG_OUT_OF_RANGE,
		[UNAVAILABLE_CMD] = ERRMSG_UNAVAILABLE_CMD
	};

	std::cerr << "\n " << errMsg[errCode] << std::endl;
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
