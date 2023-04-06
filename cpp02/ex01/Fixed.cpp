#include "Fixed.hpp"

Fixed::Fixed() : fixedNum(0)
{
	std::clog << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const intNum)
{
	std::clog << "Int constructor called" << std::endl;
	fixedNum = (intNum << fractionBits);
}

Fixed::Fixed(float const floatNum)
{
	std::clog << "Float constructor called" << std::endl;
	fixedNum = roundf(floatNum * (1 << fractionBits));
}

Fixed::Fixed(Fixed const &other)
{
	std::clog << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed	&Fixed::operator=(Fixed const &other)
{
	std::clog << "Copy assignment operator called" << std::endl;
	setRawBits(other.getRawBits());
	return (*this);
}

Fixed::~Fixed()
{
	std::clog << "Destructor called" << std::endl;
}

/** functions **/
int	Fixed::getRawBits(void) const
{
	return (fixedNum);
}

void	Fixed::setRawBits(int const raw)
{
	fixedNum = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(fixedNum) / (1 << fractionBits));
}

int	Fixed::toInt(void) const
{
	return (roundf(toFloat()));
}

std::ostream& operator<<(std::ostream &outStream, Fixed const &fixedNum)
{
	outStream << fixedNum.toFloat();
	return (outStream);
}
