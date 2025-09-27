#include "Zombie.hpp"

void	zombie_zombying(Zombie *z)
{
	std::cout << z->getName() << ": Waterpolo is so fun !" << std::endl;
}

void		Zombie::annouce(void)
{
	std::cout << name << " : BraiiiiiinnnzzzZ..." << std::endl;
}

void		Zombie::die(void)
{
	std::cout << name << " : Aaargghhhh" << std::endl;
}

std::string	Zombie::getName() const
{
	return (name);
}

Zombie::Zombie(std::string name) : name(name)
{
	std::cout << "Building" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Destroying" << std::endl;
	if (!name.length())
		return ;
	die();
}

