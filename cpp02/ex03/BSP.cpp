#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	dir1 = Point::counterClockWise(a, b, point);
	float	dir2 = Point::counterClockWise(b, c, point);
	float	dir3 = Point::counterClockWise(c, a, point);

	if ((dir1 > 0 && dir2 > 0 && dir3 > 0)
		|| (dir1 < 0 && dir2 < 0 && dir3 < 0))
		return (true);
	return (false);
}
