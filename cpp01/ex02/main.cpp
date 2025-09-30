#include <iostream>
#include <string>

int	main()
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*sptr = &string;
	std::string	&sref = string;

	std::cout << "(MEMORY ADDRESS) The string is :" << &string << std::endl;
	std::cout << "(MEMORY ADDRESS) The string's pointer is :" << sptr << std::endl;
	std::cout << "(MEMORY ADDRESS) The string's ref is :" << &sref << std::endl;

	std::cout << "The string is :" << string << std::endl;
	std::cout << "The string's pointer is :" << *sptr << std::endl;
	std::cout << "The string's ref is :" << sref << std::endl;
	return (0);
}
