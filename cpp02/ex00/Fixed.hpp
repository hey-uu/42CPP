#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int					fixedNum;
	static const int	fractionBits = 8;
public:
			Fixed(void);
			Fixed(Fixed const &other);
	Fixed&	operator=(Fixed const &other);
			~Fixed(void);
/** functions **/
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif