#include "Fixed.hpp"

Fixed::Fixed() : fixedNum(0)
{
	std::clog << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy)
{
	std::clog << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed	&Fixed::operator=(Fixed const &ref)
{
	std::clog << "Copy assignment operator called" << std::endl;
	fixedNum = ref.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::clog << "Destructor called" << std::endl;
}

/** functions **/
int	Fixed::getRawBits(void) const
{
	std::clog << "getRawBits member function called" << std::endl;
	return (fixedNum);

}

void	Fixed::setRawBits(int const raw)
{
	std::clog << "setRawBits member function called" << std::endl;
	fixedNum = raw;
}
