#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed();
	
		Fixed	&operator=(const Fixed &obj);
	
		//	Operateurs de comparaison
		bool	operator>(const Fixed &obj) const;
		bool	operator<(const Fixed &obj) const;
		bool	operator>=(const Fixed &obj) const;
		bool	operator<=(const Fixed &obj) const;
		bool	operator==(const Fixed &obj) const;
		bool	operator!=(const Fixed &obj) const;

		//	Operateurs arithmetiques
		Fixed	operator*(const Fixed &obj) const;
		Fixed	operator/(const Fixed &obj) const;
		Fixed	operator+(const Fixed &obj) const;
		Fixed	operator-(const Fixed &obj) const;

		//	operateurs d'incrementation
		Fixed	operator++();
		Fixed	operator++(int);
		Fixed	operator--();
		Fixed	operator--(int);

		//
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	    static const Fixed	&min(Fixed &a,Fixed &b);
		static const Fixed	&min(const Fixed& a, const Fixed& b);
	    static const Fixed	&max(Fixed& a, Fixed& b);
	    static const Fixed	&max(const Fixed& a, const Fixed& b);
};

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);

#endif
