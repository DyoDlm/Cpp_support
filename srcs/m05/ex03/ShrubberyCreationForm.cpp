#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("ShrubberyForm", 145, 137), _target(target)
{
	std::string		fileName = target + "_shrubbery";
	std::ofstream	newFile(fileName.c_str());

	newFile << "I wrote an ASCII tree inside look : |\n"
	<< "well it has lost his leaves...\n";
	std::cout << "New shrubbery file created\n" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form) :
	AForm(form)
{
//	std::cout << std::endl;
	(void)form;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
//	std::cout << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form)
{
	(void)form;
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor)
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
