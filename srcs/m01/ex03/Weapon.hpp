#pragma once

#include <iostream>
#include <string>

class Weapon
{
	std::string	type;
	public:
		Weapon(std::string name);
		~Weapon();
		std::string	getType() const;
		void		setType(std::string ntype);
};

