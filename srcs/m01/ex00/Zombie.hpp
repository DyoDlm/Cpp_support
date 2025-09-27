#pragma once

#include <iostream>
#include <string>

class Zombie
{
	std::string	name;
	public:
		Zombie(std::string name);
		~Zombie();
		void		annouce(void);
		void		die(void);
		std::string	getName() const;
};

Zombie		*newZombie(std::string name);
void		randomChump(std::string name);
void		zombie_zombying(Zombie *z);

