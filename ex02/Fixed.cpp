#include "Fixed.hpp"

//----------------------------------------From Ex00------------------------------------------------------------------
/*
	- frac_bits = precision value
	- higher frac_bits = higher precision
	- since we using int (32bits) && 1 bit for sign, practical limit frac_bits is <= 16, we need to leave space for int
	- example int 5 << 8, equivalent to 5.0(fixed_point) [8 bit for 1 precision value behind the "."]
	- int 5 << 16, equivalent to 5.00(fixed_point) [16 bit for 2 precision value behind the "."]
*/
const int	Fixed::frac_bits = 8;

/*
	A scale for conversion
	if frac_bits = 8, then the value is 256
*/
const int	Fixed::convert_scale = 1 << frac_bits;

// Initialise the value to 0
Fixed::Fixed(): fixed_value(0)
{
	// std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed& other)
{
	// std::cout << BLUE << "Copy constructor called" << RESET << std::endl; 
	this->fixed_value = other.getRawBits();
}

// Copy Assignment Operator
Fixed	&Fixed::operator=(const Fixed& other)
{
	// std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
	if (this != &other)
		this->fixed_value = other.getRawBits();
	return (*this);
}

// Destructor
Fixed::~Fixed()
{
	// std::cout << RED << "Destructor called" << RESET << std::endl;
}
/*
	std::cout << GREEN << "getRawBits member function called" << RESET << std::endl;
	this line is not required for ex01
*/
int Fixed::getRawBits(void) const
{
	return (this->fixed_value);
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_value = raw;
}

//---------------------------------------From Ex01---------------------------------------------------

/*
	- constructor that takes a constant integer as a parameter.
	- It converts it to the corresponding fixed-point value.
	- Int multiply with 2 to the power of fractional_bits = fixed-point value.  (int) * 2^frac_bits = fixed-point value
	- multiplication by 2^n means left shift "<<" ; division by 2^n means right shift ">>"
*/
Fixed::Fixed(const int p_int)
{
	int	fixed_p_value = 0;

	// std::cout << MAGENTA << "Int constructor called" << RESET << std::endl;
	fixed_p_value = p_int << frac_bits; // left shift to multiply
	this->setRawBits(fixed_p_value);
}

/*
	Floating Point -> Fixed Point Value
	Step 1: Convert the value to Fixed Point Value (Only Int var allows bitwise shifting)
	- multiplication first because wanna keep the fractional_bits of float
	Step 2: Round off to the float to get no decimal point
*/
Fixed::Fixed(const float p_float)
{
	int	accurate = 0;
	int	shift = 1 << frac_bits; // int var allows bitwise shifting

	// std::cout << YELLOW << "Float constructor called" << RESET << std::endl;

	// Convert the value to fixed point and round off so that no decimal point
	accurate = static_cast<int>(roundf(p_float * shift));

	// Set the value
	this->setRawBits(accurate);
}

/*
	- converts the fixed-point value to a floating-point value
	- division with fractional_bits will get back floating-point value
	- cannot use direct shifting in float<->fixed-point value conversion
		as it may discard fractional_part of float
*/
float	Fixed::toFloat(void) const
{
	int	fixed_v = 0;
	int	shift = 1 << frac_bits;
	float float_v = 0;

	fixed_v = this->getRawBits();
	float_v = static_cast<float>(fixed_v) / shift;
	return (float_v);
}

/*
	fixed-point value -> integer
	division with fractional_bits will get back integer
*/
int	Fixed::toInt(void) const
{
	int	fixed_v = 0;
	int	int_v = 0;

	fixed_v = this->getRawBits();
	int_v = fixed_v >> frac_bits;
	return (int_v);
}

/*
	An overload of the insertion («) operator
	- inserts a floating-point representation of the fixed-point number 
		into the output stream object passed as parameter.
*/

std::ostream	&operator<<(std::ostream &output, const Fixed& other)
{
	output << other.toFloat();
	return (output);
}

//----------------------------ADD-----------------------------
/*
	6 comparison operators: >, <, >=, <=, == and !=
	All of them return true or false only for the operations
	They do not return reference:
		you only interest with the results
		you do not want to modify anything
*/
// comparsion operator: >
bool	Fixed::operator>(const Fixed& other) const
{
	if (this->fixed_value > other.fixed_value)
		return (true);
	else
		return (false);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	if (this->fixed_value >= other.fixed_value)
		return (true);
	else
		return (false);
}

bool	Fixed::operator<(const Fixed& other) const
{
	if (this->fixed_value < other.fixed_value)
		return (true);
	else
		return (false);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	if (this->fixed_value <= other.fixed_value)
		return (true);
	else
		return (false);
}

bool	Fixed::operator==(const Fixed& other) const
{
	if (this->fixed_value == other.fixed_value)
		return (true);
	else
		return (false);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	if (this->fixed_value != other.fixed_value)
		return (true);
	else
		return (false);
}

/*
	4 arithmetic operators: +,-, *, and /
*/
Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed	newFixed;
	int	results = 0;

	results = this->fixed_value + other.fixed_value;
	newFixed.setRawBits(results);
	return (newFixed);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed	newFixed;
	int	results = 0;

	results = this->fixed_value - other.fixed_value;
	newFixed.setRawBits(results);
	return (newFixed);
}

/*
	Provided frac_bits = 8
	256a * 256b = ab(256)^2 
	so u need to remove 1 time 256, similar to >> 2^8
	ab(256)^2 / 256 = 256 ab
*/
Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed	newFixed;
	int	results = 0;

	results = (this->fixed_value * other.fixed_value) >> frac_bits;
	newFixed.setRawBits(results);
	return (newFixed);
}

/*
	Provided frac_bits = 8
	256a / 256b = a/b (So u lacking 256 here as a fixed point number)
	a/b * 256 (now u re fixed point value)
	but this way will cause u loss decimal while dividing, so u have to multiply before division
	(256 * 256)a / 256b = (256)(a/b)
*/
Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed	newFixed;
	int	temp = 0;
	int	results = 0;

	temp = this->fixed_value << frac_bits;
	results = temp / other.fixed_value;
	newFixed.setRawBits(results);
	return (newFixed);
}

/*
	The 4 increment/decrement operators : ++x, x++, --x, x++
*/

// smallest representable ϵ, just to see how much it was added
// const float	Fixed::epsilon = 1.0f / (1 << frac_bits);

/*
	pre-increment (++a)
	No parameters.
	Increases the object before returning it.
	Returns by reference
	Can work also if no return by reference, but it will create a copy, which may lead to less efficient
*/
Fixed	&Fixed::operator++(void)
{
	this->fixed_value++;
	return (*this);
}

/*
	post-increment (a++)
	takes in INT as dummy to tell compiler it's post increment
	Returns a copy of the original value (before increment).
	Can’t return by reference here since the value is from before the change.
*/
Fixed	Fixed::operator++(int)
{
	Fixed	a = *this; // Make a copy of original value
	this->fixed_value++; // increase the value
	return (a); // Return the copy
}

/*
	Pre-decrement
	return reference
*/
Fixed	&Fixed::operator--(void)
{
	this->fixed_value--;
	return (*this);
}

/*
	Post-decrement
	return a copy of unmodified value
*/
Fixed	Fixed::operator--(int)
{
	Fixed	a = *this;
	this->fixed_value--;
	return (a);
}

/*
	A static member function min that takes as parameters two references on fixed-point numbers
	and returns a reference to the smallest one.
*/
Fixed	&Fixed::min(Fixed& first, Fixed& second)
{
	if (first.fixed_value < second.fixed_value)
		return (first);
	else
		return (second);
}

/*
	A static member function min that takes as parameters two references to constant
	fixed-point numbers, and returns a reference to the smallest one
*/
const Fixed	&Fixed::min(const Fixed& first, const Fixed& second)
{
	if (first.fixed_value < second.fixed_value)
		return (first);
	else
		return (second);
}

/*
	A static member function max that takes as parameters two references on fixed-point
	numbers, and returns a reference to the greatest one.
*/
Fixed	&Fixed::max(Fixed& first, Fixed& second)
{
	if (first.fixed_value > second.fixed_value)
		return (first);
	else
		return (second);
}

/*
	A static member function max that takes as parameters two references to constant
	fixed-point numbers, and returns a reference to the greatest one.
*/
const Fixed	&Fixed::max(const Fixed& first, const Fixed& second)
{
	if (first.fixed_value > second.fixed_value)
		return (first);
	else
		return (second);
}

/************************DELETED STUFF BUT STILL USEFUL************************ */

// Fixed	Fixed::operator+(const Fixed& other) const
// {
// 	Fixed	newFixed;
// 	float	v1 = 0;
// 	float	v2 = 0;
// 	float	results = 0;

// 	v1 = this->toFloat();
// 	v2 = other.toFloat();
// 	results = v1 + v2;
// 	newFixed = Fixed(results);
// 	return (newFixed);
// }

// Fixed	Fixed::operator-(const Fixed& other) const
// {
// 	Fixed	newFixed;
// 	float	v1 = 0;
// 	float	v2 = 0;
// 	float	results = 0;

// 	v1 = this->toFloat();
// 	v2 = other.toFloat();
// 	results = v1 - v2;
// 	newFixed = Fixed(results);
// 	return (newFixed);
// }

// Fixed	Fixed::operator*(const Fixed& other) const
// {
// 	Fixed	newFixed;
// 	float	v1 = 0;
// 	float	v2 = 0;
// 	float	results = 0;

// 	v1 = this->toFloat();
// 	v2 = other.toFloat();
// 	results = v1 * v2;
// 	newFixed = Fixed(results);
// 	return (newFixed);
// }

// Fixed	Fixed::operator/(const Fixed& other) const
// {
// 	Fixed	newFixed;
// 	float	v1 = 0;
// 	float	v2 = 0;
// 	float	results = 0;

// 	v1 = this->toFloat();
// 	v2 = other.toFloat();
// 	results = v1 / v2;
// 	newFixed = Fixed(results);
// 	return (newFixed);
// }