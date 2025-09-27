#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("PresidentialPardon", 25, 5), _target(target)
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form) :
	AForm(form)
{
	(void)form;
//	std::cout << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
//	std::cout << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &form)
{
	(void)form;
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor)
{
	try
	{
		executor.executeForm(*this);
		std::cout << GREEN << "Shrubbery Form executed\n" << RESET;
	}
	catch(...)
	{
		std::cerr << RED << "Shrubbery Form Unexecuted\n" << RESET;
	}
}
