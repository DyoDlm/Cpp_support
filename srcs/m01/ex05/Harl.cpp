#include "Harl.hpp"

Harl::Harl()
{
	setLevels(); setComplaints();
}

Harl::~Harl() {}

void	Harl::debug(void)
{
	std::cout << "debuging\n";
}

void	Harl::info(void)
{
	std::cout << "infoing\n";
}

void	Harl::warning(void)
{
	std::cout << "waringing\n";
}

void	Harl::error(void)
{
	std::cout << "erroring\n";
}

/*	Function ptr format == (Class::newname)()
*	Function exec goes == (this->*newname)()
*	the this refers to actual member
*	--> it also help to point to ref.	*/

void	Harl::complain(std::string level)
{
	int		i;
	void 	(Harl::*complaint)() = 0;

	for (i = 0; i < COMPLAINTS; i++)
	{
		if (levels[i] == level)
		{
			complaint = complaints[i];
			break ;
		}
	}
	if (i == COMPLAINTS)
		std::cout << "Invalid complaint\n";
	else
		(this->*complaint)();
}

/*	Init array format == 'returnValue	(Class::*foo[size])() --> because array of functions not allowed
*	Pointer before foo, because foo is local et 
*	pointe vers membres de Harl.
*	refToFunc | Class::arrayElement, ... }.	*/

void	Harl::setComplaints()
{
	void (Harl::*complaintsArr[COMPLAINTS])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	for (int i = 0; i < COMPLAINTS; ++i)
		complaints[i] = complaintsArr[i];
}

void	Harl::setLevels()
{
	std::string e[COMPLAINTS] = {
		"DEBUG", "INFO", "WARNING", "ERROR"
	};

	for (int i = 0; i < COMPLAINTS; ++i)
		levels[i] = e[i];
}
