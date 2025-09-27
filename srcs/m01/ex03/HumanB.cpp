#include "HumanB.hpp"

HumanB::HumanB(std::string h_name) : name(h_name), weapon(NULL) {}

void	HumanB::attack()
{
    if (weapon == NULL)
        std::cout << name << " can't attack. He hasn't a weapon\n";
    else
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &w)
{
	weapon = &w;
	std::cout << "weapon set" << std::endl;
}

HumanB::~HumanB() {}