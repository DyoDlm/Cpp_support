#include "Zombie.hpp"

int	main(int ac, char **av)
{
	std::string	n;
	std::string	name;
	Zombie		*horde = NULL;
	int			n_zombies;

	//	av[1] n_zombies AND av[2] = name
	n = av[1];
	name = av[2];
	n_zombies = atoi(n.c_str());
	horde = zombieHorde(n_zombies, name);
	for (int i = 0; i < n_zombies; i++)
		horde[i].annouce();
	delete []horde;
	return (0);
}
