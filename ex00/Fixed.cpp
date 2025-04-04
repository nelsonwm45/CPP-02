#include "Fixed.hpp"

// fractional bits will always 8
const int	Fixed::frac_bits = 8;

// Initialise the value to 0
Fixed::Fixed(): fixed_value(0)
{
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

// Copy constructor
// Shallow copy is sufficient for int variable
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
