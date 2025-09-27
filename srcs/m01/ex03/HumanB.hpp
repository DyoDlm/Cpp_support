#pragma once

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
    std::string	name;
    Weapon		*weapon;
	public:
    	HumanB(std::string h_name);
	  	~HumanB();
    	void attack();
    	void setWeapon(Weapon &w);
};
