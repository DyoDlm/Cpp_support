#include "Intern.hpp"

Intern::Intern()
{
	return ;
}

Intern::Intern(const Intern &i)
{
	(void)i;
	return ;
}

Intern::~Intern()
{
	return ;
}

Intern	&Intern::operator=(const Intern &i)
{
	if (this != &i)
		*this = i;
	return *this;
}

AForm	*Intern::makeForm(std::string format, std::string target)
{
	std::string	fmt[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	std::string	msg[] = {"shrubForm", "RobotRequest", "PresPardon", "Nothing"};
	AForm		*newForm = NULL;
	int	i = -1;

	while (++i < 3)
		if (format == fmt[i])
			break ;
	switch (i)
	{
		case SHRUB:
			newForm = new ShrubberyCreationForm(target);
			break;
		case ROBOT:
			newForm = new RobotomyRequestForm(target);
			break ;
		case PRES:
			newForm = new PresidentialPardonForm();
			break ;
		default:
			std::cout << "Invalid format. Try [robotomy request]"
			<< " or [shrubbery creation] or [presidential pardon]\n";
			break;
	}
	std::cout << "Intern creates " << msg[i] << std::endl;
	return (newForm);
}
