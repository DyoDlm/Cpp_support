#include "Bureaucrat.hpp"

static void	badWay()
{
	std::cout << "///////////////////////////////////////////////\n"
	<<			 "//Ca marche, mais ce n'est pas la bonne facon//\n"
	<< 			 "///////////////////////////////////////////////\n";

	Bureaucrat	ceo("CEO", 1);
	Bureaucrat	veteran("VETERAN", 50);
	Bureaucrat	stagiaire("STAGIAIRE", 150);

	std::cout << ceo << std::endl;
	std::cout << veteran << std::endl;
	std::cout << stagiaire << std::endl;

	levelUp(ceo);
	levelUp(veteran);
	levelUp(stagiaire);

	std::cout << ceo << std::endl;
	std::cout << veteran << std::endl;
	std::cout << stagiaire << std::endl;

	levelDown(ceo);
	levelDown(veteran);
	levelDown(stagiaire);

	std::cout << ceo << std::endl;
	std::cout << veteran << std::endl;
	std::cout << stagiaire << std::endl;

	levelDown(ceo);
	levelDown(veteran);
	levelDown(stagiaire);

	std::cout << ceo << std::endl;
	std::cout << veteran << std::endl;
	std::cout << stagiaire << std::endl;
}

static void	goodWay_Try()
{
	std::cout << "///////////////////////////////////////////////\n"
	<<			 "//		La c'est la bonne facon			   //\n"
	<< 			 "///////////////////////////////////////////////\n";

	try
	{
		Bureaucrat	ceo("CEO", 1);
		Bureaucrat	stagiaire("STAGIAIRE", 150);

		std::cout << ceo << std::endl;
		std::cout << stagiaire << std::endl;
	
		ceo.decrementGrade();
		stagiaire.incrementGrade();
	
		std::cout << ceo << std::endl;
		std::cout << stagiaire << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

static void	goodWay_Catch()
{
	std::cout << "///////////////////////////////////////////////\n"
	<<			 "//		La c'est la bonne facon			   //\n"
	<< 			 "///////////////////////////////////////////////\n";

	try
	{
		Bureaucrat	ceo("CEO", 0);

		std::cout << ceo << std::endl;

		ceo.decrementGrade();
	
		std::cout << ceo << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		Bureaucrat	stagiaire("STAGIAIRE", 151);

		std::cout << stagiaire << std::endl;
		
		stagiaire.incrementGrade();

		std::cout << stagiaire << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

int	main()
{
	badWay();
	goodWay_Try();
	goodWay_Catch();
	return (0);
}