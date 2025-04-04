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
	this->fixed_value = fixed_p_value;
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

int Fixed::getRawBits(void) const
{
	std::cout << GREEN << "getRawBits member function called" << RESET << std::endl;
	return (this->fixed_value);
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_value = raw;
}
