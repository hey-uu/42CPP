#include <iomanip>
#include "Fixed.hpp"

int	main(void)
{
	/******************** BASIC TEST ********************/
	std::cout << std::setw(50) << std::setfill('=') << "\n";
	std::cout << " Basic Test" << "\n";
	std::cout << std::setw(50) << std::setfill('=') << "\n";

	Fixed		a;
	Fixed const	b( 10 );
	Fixed const	c( 42.42f );
	Fixed const	d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << "\n";
	std::cout << "b is " << b << "\n";
	std::cout << "c is " << c << "\n";
	std::cout << "d is " << d << "\n";

	std::cout << "a is " << a.toInt() << " as integer" << "\n";
	std::cout << "b is " << b.toInt() << " as integer" << "\n";
	std::cout << "c is " << c.toInt() << " as integer" << "\n";
	std::cout << "d is " << d.toInt() << " as integer" << "\n";

	/******************** MY TEST ********************/
	std::cout << std::setw(50) << std::setfill('=') << "\n";
	std::cout << " Test for negative numbers" << "\n";
	std::cout << std::setw(50) << std::setfill('=') << "\n";
	// 1
	std::cout << std::setw(50) << std::setfill('-') << "\n";
	std::cout << "#1 negative integer -3 " << "\n";
	std::cout << std::setw(50) << std::setfill('-') << "\n";
	a = Fixed( -3 );
	std::cout << "a is " << a << "\n";
	std::cout << "a is " << a.toInt() << " as integer" << "\n";
	// 2
	std::cout << std::setw(50) << std::setfill('-') << "\n";
	std::cout << "#2 negative integer -2147483647" << "\n";
	std::cout << std::setw(50) << std::setfill('-') << "\n";
	a = Fixed( -2147483647 );
	std::cout << "a is " << a << "\n";
	std::cout << "a is " << a.toInt() << " as integer" << "\n";
	// 3
	std::cout << std::setw(50) << std::setfill('-') << "\n";
	std::cout << "#3 negative float -123.12" << "\n";
	std::cout << std::setw(50) << std::setfill('-') << "\n";
	a = Fixed( -123.12f );
	std::cout << "a is " << a << "\n";
	std::cout << "a is " << a.toInt() << " as integer" << "\n";
	// 4
	std::cout << std::setw(50) << std::setfill('-') << "\n";
	std::cout << "#3 negative float -123.6" << "\n";
	std::cout << std::setw(50) << std::setfill('-') << "\n";
	a = Fixed( -123.6f );
	std::cout << "a is " << a << "\n";
	std::cout << "a is " << a.toInt() << " as integer" << "\n";
	return (0);
}