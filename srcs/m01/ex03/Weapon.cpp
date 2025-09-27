#include "Weapon.hpp"

Weapon::Weapon(std::string name) { type = name; }

Weapon::~Weapon() {}

std::string	Weapon::getType() const
{
	return (type);
}

void		Weapon::setType(std::string ntype) { type = ntype; }
