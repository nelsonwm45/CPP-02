#include "Fixed.hpp"

/*
	The following main is from pdf
*/
int	main(void)
{
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}

// Modified main to allow better visuality
// int	main(void)
// {
// 	std::cout << "------Going to call default constructor to construct a-------" << std::endl;
// 	Fixed a;

// 	std::cout << "------Going to call copy constructor to construct b-------" << std::endl;
// 	Fixed b( a );

// 	std::cout << "------Going to call default constructor to construct c-------" << std::endl;
// 	Fixed c;

// 	std::cout << "------Going to call copy assignment operator to assign c-------" << std::endl;
// 	c = b;

// 	std::cout << "------a calling getRawBits()-------" << std::endl;
// 	std::cout << a.getRawBits() << std::endl;
// 	std::cout << "------b calling getRawBits()-------" << std::endl;
// 	std::cout << b.getRawBits() << std::endl;
// 	std::cout << "------c calling getRawBits()-------" << std::endl;
// 	std::cout << c.getRawBits() << std::endl;
// 	return 0;
// }
