#pragma once

#include <iostream>
#include <string>
#include <cstdlib>

class Zombie
{
	std::string	name;
	public:
		Zombie();
		~Zombie();
		std::string		getName() const;
		void			setName(std::string name);
		void			annouce(void);
		void			die(void);
};

Zombie	*zombieHorde(int N, std::string name);

