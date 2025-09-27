#include "ScalarConverter.hpp"
#include "Colors.hpp"

static void	checkChars()
{
	std::cout << YELLOW
		<< "//////////////////////\n"
		<< "// CHECKING IF CHAR //\n"
		<< "//////////////////////\n" << RESET;

	std::cout << ScalarConverter::convert("a") << std::endl;
	return ;
}
static void	checkDigits()
{
	std::cout << YELLOW
		<< "//////////////////////\n"
		<< "// CHECKING IF INT  //\n"
		<< "//////////////////////\n" << RESET;

	std::cout << ScalarConverter::convert("1");
	std::cout << ScalarConverter::convert("123456");
	std::cout << ScalarConverter::convert("-123");
}
static void	checkFloats()
{
	std::cout << YELLOW
		<< "///////////////////////\n"
		<< "// CHECKING IF FLOAT //\n"
		<< "///////////////////////\n" << RESET;

	std::cout << ScalarConverter::convert("0.12f");
	std::cout << ScalarConverter::convert("-0.12f");
}
static void	checkDoubles()
{
	std::cout << YELLOW
		<< "////////////////////////\n"
		<< "// CHECKING IF DOUBLE //\n"
		<< "////////////////////////\n" << RESET;

	std::cout << ScalarConverter::convert("0.1243");
	std::cout << ScalarConverter::convert("-124.124");
}
static void	checkPseudos()
{
	std::cout << YELLOW
		<< "////////////////////////\n"
		<< "// CHECKING IF PSEUDO //\n"
		<< "////////////////////////\n" << RESET;

	std::cout << ScalarConverter::convert("-inff");
	std::cout << ScalarConverter::convert("+inff");
	std::cout << ScalarConverter::convert("nanf");

	std::cout << ScalarConverter::convert("-inf");
	std::cout << ScalarConverter::convert("+inf");
	std::cout << ScalarConverter::convert("nan");
}

static void	checkUnknow()
{
	std::cout << YELLOW
		<< "////////////////////////\n"
		<< "// CHECKING IF UNKNOW //\n"
		<< "////////////////////////\n" << RESET;
	
	std::cout << ScalarConverter::convert("arvn");
	std::cout << ScalarConverter::convert("13qrnl");
	std::cout << ScalarConverter::convert("13...1441");
	std::cout << ScalarConverter::convert("..14+qrv");
	std::cout << ScalarConverter::convert("+24f");
}

static void	whatIsInSubject()
{
	std::cout << YELLOW
		<< "/////////////////////////////\n"
		<< "// CHECKING SUBJECT VALUES //\n"
		<< "/////////////////////////////\n" << RESET;

	std::cout << ScalarConverter::convert("0");
	std::cout << ScalarConverter::convert("nan");
	std::cout << ScalarConverter::convert("42.0f");
}
int	main()
{
	whatIsInSubject();
	checkChars();
	checkDigits();
	checkFloats();
	checkDoubles();
	checkPseudos();
	checkUnknow();
	return (0);
}
