#include "Zombie.hpp"
#include <iostream>

bool	inputOk(std::string s)
{
	for (int i = 0; s[i]; i++)
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (false);
	return (true);
}

int	main()
{
	std::string	n;
	std::string	name;
	Zombie		*horde = NULL;
	int			n_zombies;

	std::cout << "Define Hord's size\n";
	std::getline(std::cin, n);
	if (n.empty() || !inputOk(n))
	{
		std::cout << "Not a number\n";
		return (1);
	}
	std::cout << "Define now their name\n";
	std::getline(std::cin, name);
	n_zombies = atoi(n.c_str());
	horde = zombieHorde(n_zombies, name);
	for (int i = 0; i < n_zombies; i++)
		horde[i].annouce();
	delete []horde;
	return (0);
}
