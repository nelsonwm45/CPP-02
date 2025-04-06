#include "Fixed.hpp"

/*
	- frac_bits = precision value
	- higher frac_bits = higher precision
	- since we using int (32bits) && 1 bit for sign, practical limit frac_bits is <= 16, we need to leave space for int
	- example int 5 << 8, equivalent to 5.0(fixed_point) [8 bit for 1 precision value behind the "."]
	- int 5 << 16, equivalent to 5.00(fixed_point) [16 bit for 2 precision value behind the "."]
*/
const int	Fixed::frac_bits = 8;

// Initialise the value to 0
Fixed::Fixed(): fixed_value(0)
{
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed& other)
{
	std::cout << BLUE << "Copy constructor called" << RESET << std::endl; 
	this->fixed_value = other.getRawBits();
}

// Copy Assignment Operator
Fixed	&Fixed::operator=(const Fixed& other)
{
	std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
	if (this != &other)
		this->fixed_value = other.getRawBits();
	return (*this);
}

// Destructor
Fixed::~Fixed()
{
	std::cout << RED << "Destructor called" << RESET << std::endl;
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

//----------------------------ADD-----------------------------

/*
	- constructor that takes a constant integer as a parameter.
	- It converts it to the corresponding fixed-point value.
	- Int multiply with 2 to the power of fractional_bits = fixed-point value.  (int) * 2^frac_bits = fixed-point value
	- multiplication by 2^n means left shift "<<" ; division by 2^n means right shift ">>"
*/
Fixed::Fixed(const int p_int)
{
	int	fixed_p_value = 0;

	std::cout << MAGENTA << "Int constructor called" << RESET << std::endl;
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

	std::cout << YELLOW << "Float constructor called" << RESET << std::endl;

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
