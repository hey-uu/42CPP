#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define ERRMSG_WRONG_VALUE "[ERROR] : Index has wrong value"
# define ERRMSG_OUT_OF_RANGE "[ERROR] : Index is out of range"
# define ERRMSG_UNAVAILABLE_CMD "[ERR0R] : Unavailable command. Enter again."

enum ePhoneBookErrCode
{
	WRONG_VALUE,
	OUT_OF_RANGE,
	UNAVAILABLE_CMD
};

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
	void	printErr(int errCode) const;
};

#endif
