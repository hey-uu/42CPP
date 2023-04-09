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
						Fixed(int const intVar);
						Fixed(float const floatVar);
						Fixed(Fixed const &ref);
	Fixed&				operator=(Fixed const &ref);
						~Fixed(void);
/** functions **/
	int					getRawBits(void) const;
	void				setRawBits(int const raw);
	float				toFloat(void) const;
	int					toInt(void) const;
/** operators **/
	// 6 comparison operators
	bool				operator>(Fixed const &ref) const;
	bool				operator<(Fixed const &ref) const;
	bool				operator>=(Fixed const &ref) const;
	bool				operator<=(Fixed const &ref) const;
	bool				operator==(Fixed const &ref) const;
	bool				operator!=(Fixed const &ref) const;
	// 4 arithmetic operators
	Fixed				operator+(Fixed const &ref) const;
	Fixed				operator-(Fixed const &ref) const;
	Fixed				operator*(Fixed const &ref) const;
	Fixed				operator/(Fixed const &ref) const;
	// 4 increment/decrement operators
	Fixed				&operator++(void);
	Fixed				operator++(int);
	Fixed				&operator--(void);
	Fixed				operator--(int);
/** static functions **/
	static Fixed		&min(Fixed &fixedNum1, Fixed &fixedNum2);
	static Fixed const	&min(Fixed const &fixedNum1, Fixed const &fixedNum2);
	static Fixed		&max(Fixed &fixedNum1, Fixed &fixedNum2);
	static Fixed const	&max(Fixed const &fixedNum1, Fixed const &fixedNum2);

};

std::ostream& operator<<(std::ostream &outStream, Fixed const &fixedNum);

#endif
