#include "Zombie.hpp"

Zombie::Zombie()
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

std::string	Zombie::getName() const
{
	return (name);
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}

void	Zombie::annouce(void) {
	std::cout << name << " : BraiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::die(void)
{
	std::cout << name << " : Aaargghhhh" << std::endl;
}
