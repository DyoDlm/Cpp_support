#include "ScalarConverter.hpp"
#include <cmath>
#include <limits>
#include <sstream>

ScalarConverter::ScalarConverter()
{
	return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
	if (this != &obj)
		(void)obj;
	return ;
}

ScalarConverter::~ScalarConverter()
{
	return ;
}

t_values	getValuesFrom(char c)
{
	return (t_values){
		.c = c,
		.i = static_cast<int>(c),
		.f = static_cast<float>(c),
		.d = static_cast<double>(c)
	};
}

t_values	getValuesFrom(int i)
{
	return (t_values){
		.c = static_cast<char>(i),
		.i = i,
		.f = static_cast<float>(i),
		.d = static_cast<double>(i)
	};
}
t_values	getValuesFrom(double f)
{
	return (t_values){
		.c = static_cast<char>(f),
		.i = static_cast<int>(f),
		.f = static_cast<float>(f),
		.d = f
	};
}

t_values	getValuesFrom(const std::string &s)
{
	t_values	values = {0, 0, 0.0f, 0.0};

	if (s == "nan" || s == "+nan" || s == "-nan")
	{
		values.f = std::numeric_limits<float>::quiet_NaN();
		values.d = std::numeric_limits<double>::quiet_NaN();
	}
	else if (s == "inf" || s == "+inf")
	{
		values.f = std::numeric_limits<float>::infinity();
		values.d = std::numeric_limits<double>::infinity();
	}
	else if (s == "-inf")
	{
		values.f = -std::numeric_limits<float>::infinity();
		values.d = -std::numeric_limits<double>::infinity();
	}
	else if (s == "+inff")
	{
		values.f = std::numeric_limits<float>::infinity();
		values.d = std::numeric_limits<double>::infinity();
	}
	else if (s == "-inff")
	{
		values.f = -std::numeric_limits<float>::infinity();
		values.d = -std::numeric_limits<double>::infinity();
	}
	return values;
}

void	formatStream(t_values values, std::stringstream &ss, int type, const std::string &s)
{
	std::cout << RED << "Char is : "  << values.c << std::endl << RESET;
 	if (type != PSEUDO)
	{
		if (isprint(values.c))
			ss << "char	: '" << values.c << "'\n";
		else
			ss << "char	: Non displayable\n";
		ss << "int	: " << values.i << "\n";
		ss << "float	: " << values.f;
		if (values.f == values.i)
			ss << ".0";
		ss << "f\n";
		ss << "double	: " << values.d;
		if (values.d == values.i)
			ss << ".0";
		ss << "\n";
	}
	else
	{
		ss << "char	: Impossible\n";
		ss << "int	: Impossible\n";
		ss << "float	: " << values.f;
		if (s.find_last_of("f") != 4)
			ss << "f";
		ss << "\n";
		ss << "double	: " << values.d << "\n";
	}
}

std::string	ScalarConverter::convert(const std::string &s)
{
	typeOf				t;
	int					type = t.search(s);
	std::stringstream	ss;
	t_values			values = {0, 0, 0.0f, 0.0};

	std::cout << std::endl;
	switch (type)
	{
		case CHAR:
			std::cout << GREEN << "str is char\n" << RESET;
			values = getValuesFrom(s[0]);
			break ;
		case INT:
			std::cout << ROSE << "str is int\n" << RESET;
			values = getValuesFrom(atoi(s.c_str()));
			break ;
		case FLOAT:
			std::cout << CYAN << "str is float\n" << RESET;
			values = getValuesFrom(atof(s.c_str()));
			break ;
		case DOUBLE:
			std::cout << BLUE << "str is double\n" << RESET;
			values = getValuesFrom(atof(s.c_str()));
			break ;
		case PSEUDO:
			std::cout << WHITE << "str is pseudo\n" << RESET;
			values = getValuesFrom(s);
			break ;
		case NONE:
			std::cout << "Unkown type\n";
			break ;
		default:
			break ;
	}
	formatStream(values, ss, type, s);
	std::cout << std::endl;
	return (ss.str());
}

