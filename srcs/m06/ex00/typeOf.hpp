#ifndef TYPEOF_HPP
# define TYPEOF_HPP

# define TYPES 5

# include <string>
# include <iostream>

class typeOf
{
	void	setTypes();
	bool	isInt(const std::string &s);
	bool	isChar(const std::string &s);
	bool	isFloat(const std::string &s);
	bool	isDouble(const std::string &s);
	bool	isPseudo(const std::string &s);
	bool	(typeOf::*lookType[TYPES])(const std::string &s);
	public:
		typeOf();
		typeOf(const typeOf &obj);
		~typeOf();

		int		search(const std::string &s);
};

#endif