#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "phonebook_constants.hpp"
# include "Contact.hpp"

namespace	phonebook
{
	class PhoneBook
	{
	private:
		Contact contacts[8];
		int		lastIdx;
		int		count;
		void	_printErr(int errCode) const;

	public:
				PhoneBook(void);
		void	showMenu(void) const;
		void	showSummary(void) const;
		void	terminate(void) const;
		void	add(void);
		void	search(void) const;
		void	extra(void) const;
	};
}


#endif
