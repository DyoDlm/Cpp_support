#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "Colors.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

enum
{
	SHRUB,
	ROBOT,
	PRES
};

class Intern
{
	public:
		Intern();
		Intern(const Intern &i);
		~Intern();

		Intern	&operator=(const Intern &i);

		AForm	*makeForm(std::string format, std::string target);
};

#endif