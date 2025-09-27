#include "Form.hpp"
#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	ceo("CEO", 1);
	Bureaucrat	stagiaire("STAGIAIRE", 150);
	Form		docCeo("CEO_DOC", 2, 2);

	std::cout << ceo << std::endl;
	std::cout << stagiaire << std::endl;

	try 
	{
		ceo.incrementGrade();
		stagiaire.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << ceo << std::endl;
	std::cout << stagiaire << std::endl;

	try
	{
		std::cout << docCeo << std::endl;
		docCeo.beSigned(ceo);
		std::cout << docCeo << std::endl;
		
		Form	newDocCeo("newDoc", 2, 2);
		newDocCeo.beSigned(stagiaire);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}