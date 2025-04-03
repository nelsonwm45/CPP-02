#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define YELLOW "\033[33m"
# define CYAN "\033[36m"
# define MAGENTA "\033[35m"
# define WHITE "\033[37m"
# define RESET "\033[0m"

class Fixed
{
	private:
		int	fixed_value;
		static const int	frac_bits;

	public:
		// default constructor
		Fixed(void);

		// copy constructor
		Fixed(const Fixed& other);

		// copy assignment operator
		Fixed	&operator=(const Fixed& other);

		// destructor
		~Fixed(void);

		int getRawBits(void) const;
		void setRawBits(int const raw);
};


#endif