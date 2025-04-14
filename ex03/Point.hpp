#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define YELLOW "\033[33m"
# define CYAN "\033[36m"
# define MAGENTA "\033[35m"
# define WHITE "\033[37m"
# define RESET "\033[0m"

class Point
{
	private:
		// since it's a const, we cannot modify
		const Fixed	_x;
		const Fixed	_y;
	
	public:
		Point();
		Point(const float num1, const float num2);

		Point(const Point &other);

		Point	&operator=(const Point &other);

		// Getters
		const Fixed getX() const;
		const Fixed	getY() const;

		// Setters (Probably not needed)
		void setX(const Fixed newX);
		void setY(const Fixed newY);

		~Point();

};

Fixed	Calc_Area(const Point &a, const Point &b, const Point &c);
bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif