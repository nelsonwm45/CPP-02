#include "Point.hpp"

/*
	Shoelace algorithm for Triangle Area Calculation
	A(1, 2), B(4, 5), C(6, 3)

		A   B   C   A
	x:  1   4   6   1  
	y:  2   5   3   2

	(1×5 + 4×3 + 6×2) - (2×4 + 5×6 + 3×1)
	= (5 + 12 + 12) - (8 + 30 + 3)
	= 29 - 41 = -12

	Area = |–12| / 2 = 6
*/
Fixed	Calc_Area(const Point &a, const Point &b, const Point &c)
{
	Fixed	area;

	// Find the area using shoelace method
	area = (a.getX() * b.getY() + b.getX() * c.getY() + c.getX() * a.getY()) -
			(a.getY() * b.getX() + b.getY() * c.getX() + c.getY() * a.getX());

	// Absolute the area if negative
	if (area < 0)
		area = area * -1;

	// so according to shoelace formula, we need to half it
	area = area / 2;

	return (area);
}


bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	area_abc;
	Fixed	area_abpoint;
	Fixed	area_acpoint;
	Fixed	area_bcpoint;
	Fixed	sum;

	// calculate the original area abc
	area_abc = Calc_Area(a, b , c);

	// if area_abc == 0, means no area, all three points are same
	if (area_abc == 0)
		return (false);

	// calculate the three small triangle
	area_abpoint = Calc_Area(a, b, point);
	area_acpoint = Calc_Area(a, c, point);
	area_bcpoint = Calc_Area(b, c, point);

	// Total up the small triangle
	sum = area_abpoint + area_acpoint + area_bcpoint;

	// Check if the point lies on a vertex
	if (point.getX() == a.getX() && point.getY() == a.getY())
		return (false);
	if (point.getX() == b.getX() && point.getY() == b.getY())
		return (false);
	if (point.getX() == c.getX() && point.getY() == c.getY())
		return (false);
	
	// Check if the point lies on an edge (allow small precision errors)
	if (area_abpoint.toFloat() < 0.001 || area_acpoint.toFloat() < 0.001 || area_bcpoint.toFloat() < 0.001)
		return (false);

	// Check if sum == abc, if same means inside the triangle abc
	// Due to float precision error, so minus approximately 0 is still acceptable
	if (std::abs((sum - area_abc).toFloat()) < 0.001)
		return (true);
	else
		return (false);
}
