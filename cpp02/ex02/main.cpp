#include "Fixed.hpp"
#include "Colors.hpp"
#include <ostream>

static void	ComparaisonTest()
{
	std::cout << RED << "\n\nTESTING COMPARING OPERATORS\n\n" << WHITE;

	std::string	input;

	std::cout << "Choose an integer for a : \n";
	std::getline(std::cin, input);
	Fixed	int_a(atoi(input.c_str()));
	std::cout << "Now chose an integer for b : \n";
	std::getline(std::cin, input);
	Fixed	int_b(atoi(input.c_str()));

	std::cout << GREEN << "Operators ['<', '>', '<=', '>=', '==', '!='] :\n" << ROSE
	<< "\ta is : " << WHITE << int_a << ROSE << " and b is : " << WHITE << int_b << "\n\n"
	<< YELLOW  << "Result for 'a < b'  : " << WHITE << ((int_a < int_b) ? "true" : "false") << std::endl
	<< CYAN << "Result for 'a > b'  : " << WHITE << ((int_a > int_b) ? "true" : "false") << std::endl
	<< YELLOW  << "Result for 'a <= b' : " << WHITE << ((int_a <= int_b)? "true" : "false") << std::endl
	<< CYAN << "Result for 'a >= b' : " << WHITE << ((int_a >= int_b)? "true" : "false") << std::endl
	<< YELLOW  << "Result for 'a == b' : " << WHITE << ((int_a == int_b)? "true" : "false") << std::endl
	<< CYAN << "Result for 'a != b' : " << WHITE << ((int_a != int_b)? "true" : "false") << std::endl;

	std::cout << "\n\n\n" << WHITE;
}

static void	ArithmeticTest()
{
	std::cout << "TESTING ARITHMETIC OPERATORS\n\n";

	std::string	input;

	std::cout << "Choose an integer for a : \n";
	std::getline(std::cin, input);
	Fixed	int_a(atoi(input.c_str()));
	std::cout << "Now chose an integer for b : \n";
	std::getline(std::cin, input);
	Fixed	int_b(atoi(input.c_str()));

	std::cout << GREEN << "Operators ['+', '-', '*', '/'] :\n" << ROSE
	<< "\ta is : " << WHITE << int_a << ROSE << " and b is : " << WHITE << int_b << "\n\n"
	<< YELLOW  << "Result for 'a + b' : " << WHITE << int_a + int_b << std::endl
	<< CYAN << "Result for 'a - b' : " << WHITE << int_a - int_b << std::endl
	<< YELLOW  << "Result for 'a * b' : " << WHITE << int_a * int_b << std::endl
	<< CYAN << "Result for 'a / b' : " << WHITE << int_a / int_b << std::endl;

	std::cout << "\n\n\n";
}

static void	IncrementTest()
{
	std::cout << "TESTING INCREMENT AND DECREMENT OPERATORS\n\n";

		std::string	input;

	std::cout << "Choose an integer for a : \n";
	std::getline(std::cin, input);
	Fixed	int_a(atoi(input.c_str()));

	std::cout << GREEN << "Operators ['++(int)', '(int)++', '--(int)', '(int)--'] :\n" << RESET
	<< "\ta is : " << int_a << "\n\n"
	<< YELLOW  << "Result for '++a' : " << RESET << ++int_a << " " << int_a << std::endl
	<< CYAN << "A is now : " << WHITE << int_a << std::endl
	<< YELLOW << "Result for 'a++' : " << RESET << int_a++ << " " << int_a << std::endl
	<< CYAN << "A is now : " << WHITE << int_a << std::endl
	<< YELLOW  << "Result for '--a' : " << RESET << --int_a << std::endl
	<< CYAN << "A is now : " << WHITE << int_a << std::endl
	<< YELLOW << "Result for 'a--' : " << RESET << int_a-- << std::endl
	<< CYAN << "A is now : " << WHITE << int_a << std::endl << RESET;

	std::cout << "\n\n\n";
}

static void	MinMaxTest()
{
	return ;
}

int main( void )
{
	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << WHITE << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	//	Personnal tests
	ComparaisonTest();
	ArithmeticTest();
	IncrementTest();
	MinMaxTest();
	return (1);
}
