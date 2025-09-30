#include "Fixed.hpp"
#include <ostream>
#include "Colors.hpp"

int main( void )
{
	Fixed 		a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	
	a = Fixed( 1234.4321f );
	std::cout << CYAN << "a is " << WHITE << a << std::endl;
	std::cout << CYAN << "b is " << WHITE << b << std::endl;
	std::cout << CYAN << "c is " << WHITE << c << std::endl;
	std::cout << CYAN << "d is " << WHITE << d << std::endl;
	std::cout << CYAN << "a is " << WHITE << a.toInt() << CYAN <<" as integer" << std::endl;
	std::cout << CYAN << "b is " << WHITE << b.toInt() << CYAN <<" as integer" << std::endl;
	std::cout << CYAN << "c is " << WHITE << c.toInt() << CYAN <<" as integer" << std::endl;
	std::cout << CYAN << "d is " << WHITE << d.toInt() << CYAN <<" as integer" << RESET << std::endl;
	return 0;
}
