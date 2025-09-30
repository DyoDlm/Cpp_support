#include "Zombie.hpp"
#include <iostream>

int	main()
{
	std::string	n;
	std::string	name;
	Zombie		*horde = NULL;
	int			n_zombies;

	n = 10;
	name = "jacques";
	n_zombies = atoi(n.c_str());
	horde = zombieHorde(n_zombies, name);
	for (int i = 0; i < n_zombies; i++)
		horde[i].annouce();
	delete []horde;
	return (0);
}
