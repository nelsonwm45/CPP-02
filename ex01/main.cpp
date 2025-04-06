#include "Fixed.hpp"

/*
	Expected Output:
	Default constructor called
	Int constructor called
	Float constructor called
	Copy constructor called
	Copy assignment operator called // this line will be missing cus of my copy constructor implementation
	Float constructor called
	Copy assignment operator called
	Destructor called
	a is 1234.43
	b is 10
	c is 42.4219
	d is 10
	a is 1234 as integer
	b is 10 as integer
	c is 42 as integer
	d is 10 as integer
	Destructor called
	Destructor called
	Destructor called
	Destructor called
*/
int main( void )
{
	Fixed	a;
	Fixed	const b( 10 );
	Fixed	const c( 42.42f );
	Fixed	const d( b );
	
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}

/*
	For easy to understand
*/
// int main( void )
// {
// 	std::cout << RED << "----------a is constructed using default constructor---------" << RESET << std::endl;
// 	Fixed	a;

// 	std::cout << RED << "----------b is constructed using int constructor------------" << RESET << std::endl;
// 	Fixed	const b( 10 );

// 	std::cout << RED << "----------c is constructed using float constructor---------" << RESET << std::endl;
// 	Fixed	const c( 42.42f );

// 	std::cout << RED << "----------d is constructed using copy constructor---------" << RESET << std::endl;
// 	Fixed	const d( b );
	
// 	std::cout << RED << "----------a is reassigned using copy assignment operator which created by float constructor---------" << RESET << std::endl;
// 	a = Fixed( 1234.4321f );

// 	std::cout << RED << "----------printing out converted float_value---------" << RESET << std::endl;
// 	std::cout << "a is " << a << std::endl;
// 	std::cout << "b is " << b << std::endl;
// 	std::cout << "c is " << c << std::endl;
// 	std::cout << "d is " << d << std::endl;
	
// 	std::cout << RED << "----------printing out converted int_value---------" << RESET << std::endl;
// 	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
// 	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
// 	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
// 	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

// 	return 0;
// }
