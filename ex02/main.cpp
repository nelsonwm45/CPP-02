#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}

// int main(void)
// {
// 	Fixed a;
// 	Fixed const b(Fixed(5.05f) * Fixed(2));
// 	const Fixed c(Fixed(10.5f));
// 	const Fixed d(Fixed(42.42f));
// 	Fixed e(43.41f);
// 	Fixed f(21.54f);
// 	Fixed g = e;
// 	Fixed h = f;
// 	Fixed i(50.00f);

// 	std::cout << WHITE << "a : " << a << RESET << std::endl;
// 	std::cout << WHITE << "b : " << b << RESET << std::endl;
// 	std::cout << WHITE << "c : " << c << RESET << std::endl;
// 	std::cout << WHITE << "d : " << d << RESET << std::endl;
// 	std::cout << WHITE << "e : " << e << RESET << std::endl;
// 	std::cout << WHITE << "f : " << f << RESET << std::endl;
// 	std::cout << WHITE << "g : " << g << RESET << std::endl;
// 	std::cout << WHITE << "h : " << h << RESET << std::endl;
// 	std::cout << WHITE << "i : " << i << RESET << std::endl;

// 	std::cout << GREEN << "---------Testing Arithmetic Operators----------" << RESET << std::endl;
// 	std::cout << GREEN << "a + b   : " << a + b << RESET << std::endl;
// 	std::cout << GREEN << "a - b   : " << a - b << RESET << std::endl;
// 	std::cout << GREEN << "a * b   : " << a + b << RESET << std::endl;
// 	std::cout << GREEN << "a / b   : " << a / b << RESET << std::endl;
// 	Fixed sum = e + f;
// 	std::cout << GREEN << "e + f : " << sum << RESET << std::endl;
// 	Fixed diff = e - f;
// 	std::cout << GREEN << "e - f : " << diff << RESET << std::endl;
// 	Fixed product = e * f;
// 	std::cout << GREEN << "e * f : " << product << RESET << std::endl;
// 	Fixed quotient = e / f;
// 	std::cout << GREEN << "e / f : " << quotient << RESET << std::endl;
// 	Fixed combined = (e + f) - g;
// 	std::cout << GREEN << "(e + f) - g : " << combined << RESET << std::endl;

// 	std::cout << YELLOW << "---------Testing post/pre increment/decrement--------" << RESET << std::endl;
// 	std::cout << YELLOW << "a      : " << a << RESET << std::endl;
// 	std::cout << YELLOW << "++a    : " << ++a << RESET << std::endl;
// 	std::cout << YELLOW << "a      : " << a << RESET << std::endl;
// 	std::cout << YELLOW << "a++    : " << a++ << RESET << std::endl;
// 	std::cout << YELLOW << "a      : " << a << RESET << std::endl;
// 	std::cout << YELLOW << "b      : " << b << RESET << std::endl;
// 	std::cout << YELLOW << "e               : " << e << RESET << std::endl;
// 	std::cout << YELLOW << "Pre-decrement e : " << --e << RESET << std::endl;
// 	std::cout << YELLOW << "Post-decrement e : " << e-- << RESET << std::endl;
// 	std::cout << YELLOW << "e after post-decrement : " << e << RESET << std::endl;
// 	std::cout << YELLOW << "f               : " << f << RESET << std::endl;
// 	std::cout << YELLOW << "Pre-increment f : " << ++f << RESET << std::endl;
// 	std::cout << YELLOW << "Post-increment f : " << f++ << RESET << std::endl;
// 	std::cout << YELLOW << "f after post-increment : " << f << RESET << std::endl;

// 	// Non-const max/min
// 	std::cout << BLUE << "---------Testing non-const max/min--------" << RESET << std::endl;
// 	std::cout << BLUE << "max(a, b): " << Fixed::max(a, b) << RESET << std::endl;
// 	std::cout << BLUE << "min(a, b): " << Fixed::min(a, b) << RESET << std::endl;

// 	// Const max/min
// 	std::cout << BLUE << "---------Testing CONST max/min--------" << RESET << std::endl;
// 	std::cout << RED << "c (const): " << c << RESET << std::endl;
// 	std::cout << RED << "d (const): " << d << RESET << std::endl;
// 	std::cout << RED << "max(c, d): " << Fixed::max(c, d) << RESET << std::endl;
// 	std::cout << RED << "min(c, d): " << Fixed::min(c, d) << RESET << std::endl;

// 	// Comparison
// 	std::cout << MAGENTA << "---------Testing Comparison Operators--------" << RESET << std::endl;
// 	std::cout << MAGENTA << "e : " << e << RESET << std::endl;
// 	std::cout << MAGENTA << "f : " << f << RESET << std::endl;
// 	std::cout << MAGENTA << "g : " << g << RESET << std::endl;
// 	std::cout << MAGENTA << "h : " << h << RESET << std::endl;
// 	std::cout << MAGENTA << "i : " << i << RESET << std::endl;

// 	if (e > f)
// 		std::cout << MAGENTA << "e > f" << RESET << std::endl;
// 	if (f < e)
// 		std::cout << MAGENTA << "f < e" << RESET << std::endl;
// 	if (e == g)
// 		std::cout << MAGENTA << "e == g" << RESET << std::endl;
// 	if (e != f)
// 		std::cout << MAGENTA << "e != f" << RESET << std::endl;
// 	if (e >= f)
// 		std::cout << MAGENTA << "e >= f" << RESET << std::endl;
// 	if (f <= e)
// 		std::cout << MAGENTA << "f <= e" << RESET << std::endl;
// 	if (i >= e)
// 		std::cout << MAGENTA << "i >= e" << RESET << std::endl;

// 	return 0;
// }
