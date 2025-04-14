#include "Point.hpp"

// default constructor
Point::Point(): _x(0), _y(0) {};

Point::Point(const float num1, const float num2): _x(num1), _y(num2) {};

// destructor
Point::~Point() {};

// copy constructor
Point::Point(const Point &other): _x(other._x), _y(other._y) {};

// copy assignment operator
Point	&Point::operator=(const Point &other)
{
	// const so means we cant use copy assignment operator
	// if (this != other)
	// {
	// 	this->_x = other.getX()
	// 	this->_y = other.getY();
	// }
	(void)other;
	return (*this);
}

// Getters
const Fixed	Point::getX() const
{
	return (this->_x);
}

const Fixed Point::getY() const
{
	return (this->_y);
}

// Setters
// void	Point::setX(const Fixed newX)
// {
// 	this->_x = newX;
// }

// void	Point::setY(const Fixed newY)
// {
// 	this->_y = newY;
// }
