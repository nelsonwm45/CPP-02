#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath> // for roundf

# define RED "\033[31m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define YELLOW "\033[33m"
# define CYAN "\033[36m"
# define MAGENTA "\033[35m"
# define WHITE "\033[37m"
# define RESET "\033[0m"

/*
	fixed-point value is a way to reallocate the bits of an integer (or similar type)
	to store both the integer part and the fractional (decimal) part.

	floating point has precision loss and rounding errors
*/
class Fixed
{
	private:
		int					fixed_value;
		static const int	frac_bits;
		static const int	convert_scale;

	public:
		// default constructor
		Fixed(void);

		// constructor that takes a constant integer as a parameter.
		Fixed(const int p_int);

		// constructor that takes a constant floating-point number as a parameter.
		Fixed(const float p_float);

		// copy constructor
		Fixed(const Fixed& other);

		// copy assignment operator
		Fixed	&operator=(const Fixed& other);

		// 6 comparison operators: >, <, >=, <=, == and !=
		bool	operator>(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;

		// 4 arithmetic operators: +,-, *, and /
		Fixed	operator+(const Fixed& other) const;
		Fixed	operator-(const Fixed& other) const;
		Fixed	operator*(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;

		
		// Since increment is based on smallest representable ϵ such as 1 + ϵ > 1
		// this allow us to check how much is added
		// const float epsilon;

		// The 4 increment/decrement operators : ++x, x++, --x, x++
		// (pre-increment and post-increment, pre-decrement and post-decrement)
		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);

		static Fixed& min(Fixed& first, Fixed& second);
		static const Fixed& min(const Fixed& first, const Fixed& second);
		static Fixed& max(Fixed& first, Fixed& second);
		static const Fixed& max(const Fixed& first, const Fixed& second);

		// destructor
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;
};

// overload of insertion (<<)
std::ostream	&operator<<(std::ostream &output, const Fixed& other);

#endif