#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int					fixedNum;
	static const int	fractionBits = 8;
public:
			Fixed(void);
			Fixed(int const intNum);
			Fixed(float const floatNum);
			Fixed(Fixed const &other);
	Fixed&	operator=(Fixed const &other);
			~Fixed(void);
/** functions **/
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

};

std::ostream& operator<<(std::ostream &outStream, Fixed const &fixedNum);

#endif