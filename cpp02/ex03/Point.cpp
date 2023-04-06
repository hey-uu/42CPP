#include "Point.hpp"

Point::Point(void) : x(0), y(0)
{ 
	// std::clog << "[Point] Default constructor called" << std::endl;
}

Point::Point(float const x, float const y) : x(x), y(y)
{
	// std::clog << "[Point] Float constructor called" << std::endl;
}

Point::Point(Point const &copy) : x(copy.x), y(copy.y)
{
	// std::clog << "[Point] Copy constructor called" << std::endl;
}

Point::~Point()
{
	// std::clog << "[Point] Destructor called" << std::endl;
}

Point	&Point::operator=(Point const &ref)
{
	// std::clog << "[Point] Copy assignment operator called" << std::endl;
	Fixed	*xPtr = const_cast<Fixed *>(&x);
	Fixed	*yPtr = const_cast<Fixed *>(&y);

	*xPtr = ref.x;
	*yPtr = ref.y;
	return (*this);
}

Fixed const	&Point::getX() const
{
	return (x);
}

Fixed const	&Point::getY() const
{
	return (y);
}

/**
 * Determines the direction of 2D two vectors, "to1 - from" and "to2 - from".
 * If the direction is counter clock wise, then returns positive float number.
 * Or if it's parallel, then returns 0.
 * Otherwise, returns negative float number.
*/
float	Point::counterClockWise(
		Point const &from, Point const &to1, Point const &to2)
{
	Fixed	direction((to1.x - from.x) * (to2.y - from.y)
						- (to2.x - from.x) * (to1.y - from.y));
	
	return (direction.toFloat());
}

std::ostream	&operator<<(std::ostream &outStream, Point const &point)
{
	outStream << "(" << point.getX() << ", " << point.getY() << ")";
	return (outStream);
}
