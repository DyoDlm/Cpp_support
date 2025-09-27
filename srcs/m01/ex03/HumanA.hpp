#pragma once

#include "Weapon.hpp"

class HumanA
{
	std::string	name;
	Weapon		&weapon;
	public:
		HumanA(std::string h_name, Weapon &w);
		~HumanA();
		void	attack();
};

