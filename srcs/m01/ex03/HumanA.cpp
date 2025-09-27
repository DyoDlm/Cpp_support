#include "HumanA.hpp"

HumanA::HumanA(std::string h_name, Weapon &w) : name(h_name), weapon(w) {}

void	HumanA::attack()
{
	std::cout << name << "attacks with their " << weapon.getType() << std::endl;
}

HumanA::~HumanA() {}
