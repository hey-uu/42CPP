#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
	Fixed const		x;
	Fixed const		y;
public:
					Point(void);
					Point(float const x, float const y);
					Point(Point const &copy);
	Point			&operator=(Point const &ref);
					~Point();
/** functions **/
	Fixed const		&getX() const;
	Fixed const		&getY() const;
/** static functions **/
	static float	counterClockWise(Point const &from, 
									Point const &to1, Point const &to2);
};

std::ostream		&operator<<(std::ostream &outStream, Point const &point);
bool				bsp(Point const a, Point const b, Point const c, 
						Point const point);

#endif