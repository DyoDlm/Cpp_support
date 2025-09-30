#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void	checkInitialisation()
{
	AForm	shrubbery = ShrubberyCreationForm();
	AForm	presidential = PresidentialPardonForm();
	AForm	robotomy = RobotomyRequestForm();

	std::cout << shrubbery.getName() << "\n"
	<< shrubbery.getSignGrade() << "\n"
	<< shrubbery.getExecGrade() << "\n";

	std::cout << presidential.getName() << "\n"
	<< presidential.getSignGrade() << "\n"
	<< presidential.getExecGrade() << "\n";

	std::cout << robotomy.getName() << "\n"
	<< robotomy.getSignGrade() << "\n"
	<< robotomy.getExecGrade() << "\n";
}

static void	ShrubberyTest()
{
	Bureaucrat	ceo("CEO", 1);
	Bureaucrat	stagiaire("STAGIAIRE", 50);

	try
	{
		AForm	form = ShrubberyCreationForm("Home");

		form.beSigned(ceo);
		ceo.executeForm(form);
//		form.execute(stagiaire);
		std::cout << form << std::endl;
	}	
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		AForm	form2 = ShrubberyCreationForm("Home2");

		form2.beSigned(ceo);
		form2.execute(ceo);
		std::cout << form2 << std::endl;
	}
		catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return ;
}

static void	RobotomyTest()
{
	Bureaucrat	ceo("CEO", 1);
	Bureaucrat	stagiaire("STAGIAIRE", 50);

	try
	{
		AForm	form = RobotomyRequestForm("Home");

		form.beSigned(ceo);
		ceo.executeForm(form);
//		form.execute(stagiaire);
		std::cout << form << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		AForm	form2 = RobotomyRequestForm("Home");

		form2.beSigned(ceo);
		form2.execute(ceo);
		std::cout << form2 << std::endl;
	}
		catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return ;
}

static void	PresidentTest()
{
	Bureaucrat	ceo("CEO", 1);
	Bureaucrat	stagiaire("STAGIAIRE", 50);

	try
	{
		AForm		form = PresidentialPardonForm("Home");

		form.beSigned(ceo);
		form.execute(stagiaire);
		std::cout << form << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		AForm		form2 = PresidentialPardonForm("Home");

		form2.beSigned(ceo);
		form2.execute(ceo);
		std::cout << form2 << std::endl;
	}
		catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return ;
}

int	main()
{
	checkInitialisation();
	ShrubberyTest();
	RobotomyTest();
	PresidentTest();

	return (0);
}