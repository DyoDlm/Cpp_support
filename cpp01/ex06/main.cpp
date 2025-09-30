#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	the_fucker;

	if (ac != 2)
	{
		std::cout << "Bad args\n";
		return (1);
	}
	std::string	level = av[1];
	the_fucker.harlFilter(level);
	return (0);
}
