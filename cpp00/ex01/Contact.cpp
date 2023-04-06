#include "Contact.hpp"

Contact::Contact(void)
{ }

void	Contact::initialize(std::string contactInfo[5])
{
	firstName = contactInfo[0];
	lastName = contactInfo[1];
	nickname = contactInfo[2];
	phoneNumber = contactInfo[3];
	darkestSecret = contactInfo[4];
	for (int i = 0 ; i < 4 ; i++)
	{
		if (contactInfo[i].length() >= 10)
			summaryInfo[i] = contactInfo[i].substr(0, 10).replace(9, 1, ".");
		else
			summaryInfo[i] = contactInfo[i];
	}
}

void	Contact::showInfo() const
{
	std::cout << "\n";
	std::cout << "==============================================================\n";
	std::cout << "                     Specific Information                     \n";
	std::cout << "==============================================================\n";
	std::cout << " + First Name : " << firstName << "\n";
	std::cout << " + Last Name : " << lastName << "\n";
	std::cout << " + Nickname : " << nickname << "\n";
	std::cout << " + Phone Number : " << phoneNumber << "\n";
	std::cout << " + Darkest Secret : " << darkestSecret << "\n" << std::endl;
}

void	Contact::showSummary() const
{
	std::cout << "|";
	for (int i = 0 ; i < 4 ; i++)
	{
		std::cout << std::setw(10) << std::right << summaryInfo[i];
		std::cout << "|";
	}
	std::cout << std::endl;
}

bool	Contact::getContactInput(std::string contactInfo[5])
{
	std::string	message[5] = {
		"First Name", "Last Name", "Nickname", "Phone Number", "Darkest Secret"
	};

	std::cout << "\n * Enter Information for new contact.\n";
	for (int i = 0 ; i < 5 ; i++)
	{
		std::cout << "   >> " << message[i] << " : " << std::flush;
		std::cin >> contactInfo[i];
		if (std::cin.eof() == true)
			return (false);
	}
	return (true);
}
