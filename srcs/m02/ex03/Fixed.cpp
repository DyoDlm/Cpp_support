#include "Fixed.hpp"
#include "Colors.hpp"

Fixed::Fixed() : _rawBits(0)
{
//	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &other)
{
//	std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed::Fixed(const int value)
{
//	std::cout << "Int constructor called\n";
	this->_rawBits = value << this->_fractionalBits;
}

Fixed::Fixed(const float value)
{
//	std::cout << "Float constructor called\n";
	this->_rawBits = roundf(value * (1 << this->_fractionalBits));
}

Fixed::~Fixed()
{
//	std::cout << "Destructor called\n";
}

int	Fixed::getRawBits(void) const
{
//	std::cout << "getRawBits member function called\n";
	return this->_rawBits;
}

void	Fixed::setRawBits(int const raw)
{
//	std::cout << "setRawBits member function called\n";
	this->_rawBits = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_rawBits / (1 << this->_fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (this->_rawBits >> this->_fractionalBits);
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	if (this != &obj)
		this->_rawBits = obj.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

//	Comparison operators
bool Fixed::operator>(const Fixed &obj) const
{
	return this->_rawBits > obj.getRawBits();
}
bool Fixed::operator<(const Fixed &obj) const
{
	return this->_rawBits < obj.getRawBits();
}
bool Fixed::operator>=(const Fixed &obj) const
{
	return this->_rawBits >= obj.getRawBits();
}
bool Fixed::operator<=(const Fixed &obj) const
{
	return this->_rawBits <= obj.getRawBits();
}
bool Fixed::operator==(const Fixed &obj) const
{
	return this->_rawBits == obj.getRawBits();
}
bool Fixed::operator!=(const Fixed &obj) const
{
	return this->_rawBits != obj.getRawBits();
}

//	Arithmetic operators
Fixed Fixed::operator+(const Fixed &obj) const
{
	Fixed	res;

	res._rawBits = this->_rawBits + obj.getRawBits();
	return res;
}
Fixed Fixed::operator-(const Fixed &obj) const
{
	Fixed	res;

	res._rawBits = this->_rawBits - obj.getRawBits();
	return res;
}
Fixed Fixed::operator*(const Fixed &obj) const
{
	Fixed	res;
	long long product = (long long)this->_rawBits * obj.getRawBits();

	res._rawBits = (int)(product >> this->_fractionalBits);
	return res;
}
Fixed Fixed::operator/(const Fixed &obj) const
{
	Fixed	res;

	if (!obj.getRawBits())
	{
		std::cerr << RED << "Division by zero error" << RESET << std::endl;
		return res;
	}
	long long numerator = ((long long)this->_rawBits << this->_fractionalBits);
	res._rawBits = (int)(numerator / obj.getRawBits());
	return res;
}

//	Increment and decrement
Fixed Fixed::operator++()
{
	++_rawBits;
	return *this;
}
Fixed Fixed::operator++(int)
{
	Fixed	tmp(*this);

	++(*this);
	return tmp;
}
Fixed Fixed::operator--()
{
	--_rawBits;
	return *this;
}
Fixed Fixed::operator--(int)
{
	Fixed	tmp(*this);

	--(*this);
	return tmp;
}

//	Min and Max
const Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a.getRawBits() < b.getRawBits() ? a : b);
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() < b.getRawBits() ? a : b);
}
const Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a.getRawBits() > b.getRawBits() ? a : b);
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() > b.getRawBits() ? a : b);
}
