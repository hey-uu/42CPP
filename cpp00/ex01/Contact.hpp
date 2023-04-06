#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Contact
{
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;
	std::string	summaryInfo[4];
public:
	Contact(void);
	void		initialize(std::string contactInfo[5]);
	static bool	getContactInput(std::string contactInfo[5]);
	void		showSummary(void) const ;
	void		showInfo(void) const;
};

#endif