#include "FragTrap.hpp"

static void	displayMissAction(std::string name, std::string action)
{
	std::cout << ROSE << "FragTrap " << RESET << name << " can't do " << "'"
	<< action << "' " << "\nPlayer dead or missing Energy points" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << BLUE << "In FragTrap Default Constructor"
	<< " Creating : " << name << RESET << std::endl;
	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
	this->_status = obj._status;
}

FragTrap::~FragTrap()
{
	std::cout << BLUE << "In FragTrap destructor" << RESET << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &obj)
{
	if (this != &obj)
		this->_status = obj._status;
	return (*this);
}

void	FragTrap::attack(const std::string &target)
{
	if (_EnergyPoints && _HitPoints)
	{
		std::cout << YELLOW << "ClapTrap " << RESET << _name << " attacks : " << target
		<< ", causing : " << _AttackDamage << " points of damage." << std::endl;
		_EnergyPoints--;
	}
	else
		displayMissAction(_name, "Attack");
}

void	FragTrap::highFiveGuys(void)
{
	std::cout << std::endl;
}
