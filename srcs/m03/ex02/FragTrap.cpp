#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << BLUE << "In FragTrap Default Constructor" << RESET << std::endl;
	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
	this->_HighFiveStatus = 0;
	std::cout << BLUE << "In fragTrap copy constructor\n" << RESET; 
}

FragTrap::~FragTrap()
{
	std::cout << BLUE << "In FragTramp destructor" << RESET << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &obj)
{
	if (this != &obj)
		*this = obj;
	return (*this);
}

void	FragTrap::highFiveGuys(void)
{
	std::cout << std::endl;
}
