#include "Point.hpp"

void	bspTest(Point const &a, Point const &b, Point const &c, Point const &point)
{
	static int	count;

	std::cout << "# " << ++count << " bspTest" << std::endl;
	std::cout << "a                   : " << a << std::endl;
	std::cout << "b                   : " << b << std::endl;
	std::cout << "c                   : " << c << std::endl;
	std::cout << "point               : " << point << std::endl;
	std::cout << "bsp(a, b, c, point) : " << bsp(a, b, c, point) << std::endl;
	std::cout << "bsp(a, c, b, point) : " << bsp(a, c, b, point) << std::endl;
	std::cout << "bsp(b, a, c, point) : " << bsp(b, a, c, point) << std::endl;
	std::cout << "bsp(b, c, a, point) : " << bsp(b, c, a, point) << std::endl;
	std::cout << "bsp(c, a, b, point) : " << bsp(c, a, b, point) << std::endl;
	std::cout << "bsp(c, b, a, point) : " << bsp(c, b, a, point) << std::endl;
	std::cout << std::endl;
}

int	main(void)
{
	Point	a( 0, 0 );
	Point	b( 4, 0 );
	Point	c( 0, 4 );

	// = operator test
	std::cout << std::endl << "** ASSIGN OPERATOR TEST **\n" << std::endl;
	std::cout << "Before Assign: a=" << a << std::endl;
	a = b;
	std::cout << "After Assign: a=" << a << std::endl;
	a = Point(0, 0);
	// on triangle
	std::cout << std::endl << "** POINT ON THE TRIANGLE **\n" << std::endl;
	bspTest(a, b, c, Point( 2, 2 ));
	bspTest(a, b, c, Point( 0, 0 ));
	// out of triangle
	std::cout << std::endl << "** POINT OUT OF THE TRIANGLE **\n" << std::endl;
	bspTest(a, b, c, Point( 3, 2 ));
	bspTest(a, b, c, Point( 2, 3 ));
	// in triangle
	std::cout << std::endl << "** POINT IN THE TRIANGLE **\n" << std::endl;
	bspTest(a, b, c, Point( 1, 1 ));
	bspTest(a, b, c, Point( 1, 2 ));
	bspTest(a, b, c, Point( 2, 1 ));
}