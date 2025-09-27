#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include "Colors.hpp"
# include "typeOf.hpp"

typedef enum
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO,
	NONE
}	e_type;

typedef struct
{
	char		c;
	int			i;
	float		f;
	double		d;
}	t_values;

class ScalarConverter
{
	ScalarConverter();
	ScalarConverter(const ScalarConverter &obj);

	public:

		virtual	~ScalarConverter() = 0;

		virtual ScalarConverter	&operator=(const ScalarConverter &obj) = 0;

		static std::string	convert(const std::string &s);
};

#endif