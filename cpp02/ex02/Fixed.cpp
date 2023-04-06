#include "Fixed.hpp"

Fixed::Fixed(void) : fixedNum(0)
{ }

Fixed::Fixed(int const intVar)
{
	fixedNum = (intVar << fractionBits);
}

Fixed::Fixed(float const floatVar)
{
	fixedNum = roundf(floatVar * (1 << fractionBits));
}

Fixed::Fixed(Fixed const &copy)
{
	*this = copy;
}

Fixed	&Fixed::operator=(Fixed const &ref)
{
	setRawBits(ref.getRawBits());
	return (*this);
}

Fixed::~Fixed(void)
{ }


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
	return (roundf(this->toFloat()));
}

// 6 comparison operators
bool	Fixed::operator>(Fixed const &ref) const
{
	if (this->toFloat() > ref.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator<(Fixed const &ref) const
{
	if (this->toFloat() < ref.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator>=(Fixed const &ref) const
{
	if (this->toFloat() >= ref.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator<=(Fixed const &ref) const
{
	if (this->toFloat() <= ref.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator==(Fixed const &ref) const
{
	if (this->getRawBits() == ref.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(Fixed const &ref) const
{
	return (!(*this == ref));
}

// 4 arithmetic operators
Fixed	Fixed::operator+(Fixed const &ref) const
{
	Fixed	newFixedNum(this->toFloat() + ref.toFloat());

	return (newFixedNum);
}

Fixed	Fixed::operator-(Fixed const &ref) const
{
	Fixed	newFixedNum(this->toFloat() - ref.toFloat());

	return (newFixedNum);
}

Fixed	Fixed::operator*(Fixed const &ref) const
{
	Fixed	newFixedNum(this->toFloat() * ref.toFloat());

	return (newFixedNum);
}

Fixed	Fixed::operator/(Fixed const &ref) const
{
	const float	devisor = ref.toFloat();
	if (devisor == 0)
		throw (std::overflow_error("divided by zero exception"));
	Fixed	newFixedNum(this->toFloat() / ref.toFloat());
	return (newFixedNum);
}

// 4 increment/decrement operators
Fixed	&Fixed::operator++(void)
{
	fixedNum += 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tempFixedNum(*this);

	fixedNum += 1;
	return (tempFixedNum);
}

Fixed	&Fixed::operator--(void)
{
	fixedNum -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tempFixedNum(*this);

	fixedNum -= 1;
	return (tempFixedNum);
}

/** static functions : min, max **/
Fixed	&Fixed::min(Fixed &fixedNum1, Fixed &fixedNum2)
{
	if (fixedNum1.toFloat() < fixedNum2.toFloat())
		return (fixedNum1);
	return (fixedNum2);
}

Fixed const	&Fixed::min(Fixed const &fixedNum1, Fixed const &fixedNum2)
{
	if (fixedNum1.toFloat() < fixedNum2.toFloat())
		return (fixedNum1);
	return (fixedNum2);
}

Fixed	&Fixed::max(Fixed &fixedNum1, Fixed &fixedNum2)
{
	if (fixedNum1.toFloat() > fixedNum2.toFloat())
		return (fixedNum1);
	return (fixedNum2);
}

Fixed const	&Fixed::max(Fixed const &fixedNum1, Fixed const &fixedNum2)
{
	if (fixedNum1.toFloat() > fixedNum2.toFloat())
		return (fixedNum1);
	return (fixedNum2);
}

// << overloading
std::ostream& operator<<(std::ostream &outStream, Fixed const &fixedNum)
{
	outStream << fixedNum.toFloat();
	return (outStream);
}
