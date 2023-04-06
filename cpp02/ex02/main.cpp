#include "Fixed.hpp"

void	comparisonTest(Fixed &fixedNum1, Fixed &fixedNum2)
{
	static int	count;

	std::cout << "# " << ++count << " ";
	std::cout << "comaparison test betwen " << fixedNum1 << ", " << fixedNum2 << std::endl;
	std::cout << "> : " << (fixedNum1 > fixedNum2) << std::endl;
	std::cout << "< : " << (fixedNum1 < fixedNum2) << std::endl;
	std::cout << ">= : " << (fixedNum1 >= fixedNum2) << std::endl;
	std::cout << "<= : " << (fixedNum1 <= fixedNum2) << std::endl;
	std::cout << "== : " << (fixedNum1 == fixedNum2) << std::endl;
	std::cout << "!= : " << (fixedNum1 != fixedNum2) << std::endl;
}

void	arithmeticTest(Fixed &fixedNum1, Fixed &fixedNum2)
{
	static int	count;

	std::cout << "# " << ++count << " ";
	std::cout << "arithmetic test betwen " << fixedNum1 << ", " << fixedNum2 << std::endl;
	std::cout << "+ : " << fixedNum1 + fixedNum2 << std::endl;
	std::cout << "- : " << fixedNum1 - fixedNum2 << std::endl;
	std::cout << "* : " << fixedNum1 * fixedNum2 << std::endl;
	std::cout << "/ : " << fixedNum1 / fixedNum2 << std::endl;
}

void	minmaxTest(Fixed &fixedNum1, Fixed &fixedNum2)
{
	static int	count;

	std::cout << "# " << ++count << " ";
	std::cout << "min/max Test betwen " << fixedNum1 << ", " << fixedNum2 << std::endl;
	std::cout << "min : " << Fixed::min(fixedNum1, fixedNum2) << std::endl; 
	std::cout << "max : " << Fixed::max(fixedNum1, fixedNum2) << std::endl; 
}

void	minmaxTest(Fixed const &fixedNum1, Fixed const &fixedNum2)
{
	static int	count;

	std::cout << "# " << ++count << " ";
	std::cout << "const min/max Test betwen " << fixedNum1 << ", " << fixedNum2 << std::endl;
	std::cout << "min : " << Fixed::min(fixedNum1, fixedNum2) << std::endl; 
	std::cout << "max : " << Fixed::max(fixedNum1, fixedNum2) << std::endl; 
}

int	main(void)
{
try {
	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed		c;
	Fixed		d;
	Fixed const e( 1.3f );

	/******************** BASIC TEST ********************/
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;

	/******************** COMPARISON TEST ********************/
	// 1
	c = Fixed( 12.3f );
	d = Fixed( -4.3f );
	std::cout << std::endl << "> initialized as 12.3f, -4.3f" << std::endl;
	comparisonTest(c, d);
	// 2
	c = Fixed( 12.00000001f );
	d = Fixed( 12.00000002f );
	std::cout << std::endl << "> initialized as 12.00000001f, 12.00000002f" << std::endl;
	comparisonTest(c, d);
	// 3
	c = Fixed( 12.01f );
	d = Fixed( 12.02f );
	std::cout << std::endl << "> initialized as 12.01f, 12.02f" << std::endl;
	comparisonTest(c, d);

	/******************** ARITHMETIC TEST ********************/
	// 1

	c = Fixed( 2 );
	d = Fixed( 3 );
	std::cout << std::endl << "> initialized as 2, 3" << std::endl;
	arithmeticTest(c, d);
	// 2
	c = Fixed( -2 );
	d = Fixed( 3 );
	std::cout << std::endl << "> initialized as -2, 3" << std::endl;
	arithmeticTest(c, d);
	// 3
	c = Fixed( -2 );
	d = Fixed( -3 );
	std::cout << std::endl << "> initialized as -2, -3" << std::endl;
	arithmeticTest(c, d);
	// // 4 : division by zero
	// c = Fixed( -2 );
	// d = Fixed( 0 );
	// std::cout << std::endl << "> initialized as -2, 0" << std::endl;
	// arithmeticTest(c, d);
	/******************** INCREMENT/DECREMENT TEST ********************/

	c = Fixed(1);
	std::cout << std::endl << "> initialized as 1" << std::endl;
	std::cout << "increment decrement operator test" << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "++c: " << ++c << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "c++: " << c++ << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "--c: " << --c << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "c--: " << c-- << std::endl;
	std::cout << "c: " << c << std::endl;

	/******************** MIN/MAX TEST ********************/

	// 1
	c = Fixed( 2.123f );
	d = Fixed( -0.123f );
	std::cout << std::endl << "> initialized as 2.123f, -0.123f" << std::endl;
	minmaxTest(c, d);
	// 2
	std::cout << std::endl << "> initialized as Fixed( 5.05f ) * Fixed( 2 ), 1.3f" << std::endl;
	minmaxTest(b, e);
}
catch (std::exception &e) {
	std::cerr << "\n[ERROR] " << e.what() << "\n";
}
	return (0);
}