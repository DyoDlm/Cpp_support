#include "Harl.hpp"

Harl::Harl()
{
	setLevels();
	setComplaints();
}

Harl::~Harl() {}

void	Harl::debug(void)
{
	std::cout << "[DEBUG]"
	<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void	Harl::info(void)
{
	std::cout << "[INFO]"
	<< "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}

void	Harl::warning(void)
{
	std::cout << "[INFO]"
	<< "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month.\n";
}

void	Harl::error(void)
{
	std::cout << "[ERROR]"
	<< "This is unacceptable! I want to speak to the manager now.\n";
}

/*	Function ptr format == (Class::newname)()
*	Function exec goes == (this->*newname)()
*	the this refers to actual member
*	--> it also help to point to ref.	*/

int	Harl::findComplain(std::string complaint) const
{
	int		i;

	for (i = 0; i < COMPLAINTS; i++)
		if (commands[i] == complaint)
			break ;
	return (i);
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
		commands[i] = e[i];
}

void	Harl::harlFilter(std::string input)
{
	const int	level = findComplain(input);

	if (level == OTHER)
	{
		std::cout << "Probably complaining about insignificant problems\n";
		return ;
	}
	switch (level)
	{
		case DEBUG:
			(this->*complaints[0])();
			// fall through
		case INFO:
			(this->*complaints[1])();
			// fall through
		case WARNING:
			(this->*complaints[2])();
			// fall through
		case ERROR:
			(this->*complaints[3])();
			// fall through
		default:
			break;
	}
}
