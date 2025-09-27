#include "Zombie.hpp"

int	main()
{
	Zombie	*z = NULL;

	z = newZombie("A");
	zombie_zombying(z);
	delete z;
	randomChump("CHARLES");
	return (0);
}
