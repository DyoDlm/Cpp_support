#include "Colors.hpp"
int	main()
{
	Color	c;

	std::cout << GREEN << "CA FONCTIONNE !" << std::endl;

	std::cout << "OUPS C'EST ENCORE VERT... " << std::endl;

	std::cout << RESET << "On est bon !" << std::endl;

	std::string	str = c.red() + "A red string" + c.reset();

	std::cout << "Look at my string : " << str << std::endl;
	
	return 0;
}
