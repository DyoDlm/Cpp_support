#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("RobotomyRequest", 72, 45), _target(target)
{
	std::cout << "Drrrrr Bip Bap Bup" << std::endl;
	time_t	chance = time(0);

	if (chance % 2 == 0)
		std::cout << target << " has been robotomized\n";
	else
		std::cout << target << " dead. Robotomization failed\nReanimation in progress\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form) :
	AForm(form)
{
//	std::cout << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
//	std::cout << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &form)
{
	(void)form;
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor)
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
