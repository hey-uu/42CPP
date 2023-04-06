#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int		lastIdx;
	int		count;
public:
	PhoneBook(void);
	void	showSummary(void) const;
	bool	add(void);
	bool	search(void) const;
};

#endif