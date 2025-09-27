#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : 
	ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap()
{
	this->_name = name;
	this->_HitPoints = FragTrap::_HitPoints;
	this->_EnergyPoints = ScavTrap::_EnergyPoints;
	this->_AttackDamage = FragTrap::_AttackDamage;
	std::cout << OTHER << "Into DiamondTrap default constructor\n" << RESET;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj) : ClapTrap(obj), FragTrap(obj), ScavTrap(obj)
{
	this->_status = obj._status;
	std::cout << OTHER << "Into DiamondTrap Copy Constructor\n" << RESET;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << OTHER << "Into DiamondTrap Destructor" << RESET << std::endl; 
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &obj)
{
	if (this != &obj)
		*this = obj;
	return (*this);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "I am " << this->_name << std::endl
	<< "Also I'm " << ClapTrap::_name << std::endl;
}
