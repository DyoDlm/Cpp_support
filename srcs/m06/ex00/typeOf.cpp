#include "typeOf.hpp"

typeOf::typeOf()
{
	setTypes();
	return ;
}

typeOf::typeOf(const typeOf &obj)
{
	setTypes();
	(void)obj;
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
	if (s.length() == 1 && isprint(s[0]) && !isdigit(s[0]))
		return (true);
	return (false);
}

bool	typeOf::isInt(const std::string &s)
{
	if (s.find_first_of('-') != s.find_last_of('-')
		|| (s.find_last_of('-') != 0 && s.find_last_of('-') != std::string::npos))
		return (false);
	if (s.length() < 11)
		for (size_t i = 0; i < s.length(); i++)
			if (!isdigit(s[i]) && s[i] != '-')
				return (false);
	return (true);
}

bool	typeOf::isFloat(const std::string &s)
{
	size_t	i = 0;

	if (!s.find('.')
		|| s.find_first_of('.') != s.find_last_of('.')
		|| s.find_first_of('-') != s.find_last_of('-')
		|| (s.find_last_of('-') != 0 && s.find_last_of('-') != std::string::npos)
		|| s[s.length() - 1] != 'f')
		return (false);
	while (++i < s.length() - 1)
		if (!isdigit(s[i]) && s[i] != '.')
			return (false);
	return (true);
}

bool	typeOf::isDouble(const std::string &s)
{
	size_t	i = 0;

	if (!s.find('.')
		|| s.find_first_of('.') != s.find_last_of('.')
		|| s.find_first_of('-') != s.find_last_of('-')
		|| (s.find_last_of('-') != 0 && s.find_last_of('-') != std::string::npos))
		return (false);
	while (++i < s.length())
		if (!isdigit(s[i]) && s[i] != '.')
			return (false);
	return (true);
}

bool	typeOf::isPseudo(const std::string &s)
{
	std::string	ptypes[] = {
		"-inff", "+inff", "nanf", "-inf", "+inf", "nan" 
	};

	for (size_t i = 0; i < 6; i++)
	{
		if (s == ptypes[i])
			return (true);
//		if (s.find_first_of(ptypes[i]) == s.find_last_of(ptypes[i]))
//		{
//			for (size_t j = i; j < 6; j++)
//			{
//				if (j < 5 && s.find(ptypes[j + 1]))
//					return (false);
//				else
//					return (true);
//			}
//		}
	}
	return (false);
}

int	typeOf::search(const std::string &s)
{
	int			isTypeOf = 0;
	bool		(typeOf::*search)(const std::string &s) = 0;

	while (isTypeOf < TYPES)
	{
		search = this->lookType[isTypeOf];
		if ((this->*search)(s))
			break ;
		isTypeOf++;
	}
	return (isTypeOf);
}
