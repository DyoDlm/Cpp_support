#include "Fixed.hpp"

Fixed::Fixed(int i)
{
	std::cout << "Default Constructor called" << std::endl;
	_stored_value = i;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy Constructor called" << std::endl;
	_stored_value = obj.getRawBits();
}

Fixed&	Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &obj)
		this->_stored_value = obj.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const
{
	int	bits = _stored_value;

	std::cout << "getRawBits member function called" << std::endl;
	return (bits);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_stored_value = raw;
}
