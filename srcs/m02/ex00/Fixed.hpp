#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
	int					_stored_value;
	static const int	_stored_bits = 8;
	public:
		Fixed(int i = 0);
		Fixed(const Fixed &obj);
		~Fixed();
		Fixed  &operator=(const Fixed &obj);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif