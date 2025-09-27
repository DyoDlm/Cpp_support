#include "typeOf.hpp"

typeOf::typeOf()
{
	setTypes();
	return ;
}

typeOf::typeOf(const typeOf &obj)
{
	(void)obj;
	setTypes();
	return ;
}

typeOf::~typeOf()
{
	return ;
}

void	typeOf::setTypes()
{
	bool	(typeOf::*typeOfArr[TYPES])(const std::string &s) = {
		&typeOf::isChar,
		&typeOf::isInt,
		&typeOf::isFloat,
		&typeOf::isDouble,
		&typeOf::isPseudo
	};

	for (int i = 0; i < TYPES; i++)
		lookType[i] = typeOfArr[i];
}

bool	typeOf::isChar(const std::string &s)
{
	std::cout << s << std::endl;
	return (false);
}

bool	typeOf::isInt(const std::string &s)
{
	std::cout << s << std::endl;
	return (false);
}

bool	typeOf::isFloat(const std::string &s)
{
	std::cout << s << std::endl;
	return (false);
}

bool	typeOf::isDouble(const std::string &s)
{
	std::cout << s << std::endl;
	return (false);
}

bool	typeOf::isPseudo(const std::string &s)
{
	std::cout << s << std::endl;
	return (false);
}

int	typeOf::search(const std::string &s)
{
	int			isTypeOf = 0;
	bool		(typeOf::*search)(const std::string &s) = 0;

	while (isTypeOf < TYPES)
	{
		search = this->typeOf[isTypeOf];
		if ((this->*search)(s))
			break ;
		isTypeOf++;
	}
	return (isTypeOf);
}
