#include "Zombie.hpp"

int	main()
{
	Zombie	*z = NULL;

	z = newZombie("A");
	delete z;
	randomChump("CHARLES");
	return (0);
}
