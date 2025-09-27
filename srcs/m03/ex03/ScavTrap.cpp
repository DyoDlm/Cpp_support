#include "ScavTrap.hpp"

static void	displayMissAction(std::string name, std::string action)
{
	std::cout << ROSE << "ScavTrap " << RESET << name << " can't do " << "'"
	<< action << "' " << "\nPlayer dead or missing Energy points" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
	std::cout << ROSE << "Into ScavTrap Default Constructor"
	<< " Creating : " << name << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
{
	std::cout  << ROSE << "Into ScavTrap Copy Constructor"
	<< " Crearing : " << obj._name << RESET <<std::endl;
	this->_gateMod = obj._gateMod;
}

ScavTrap::~ScavTrap()
{
//	displayPlayerStatus();
	std::cout << ROSE << "Into ScavTrap Default Destructor" << RESET << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &obj)
{
	if (this != &obj)
		this->_gateMod = obj._gateMod;
	return *this;
}

void	ScavTrap::attack(const std::string &target)
{
	if (_EnergyPoints && _HitPoints)
	{
		std::cout << ROSE << "ScavTrap " << RESET << this->_name << " attacks : " << target
		<< ", causing : " << _AttackDamage << " points of damage." << std::endl;
		_EnergyPoints--;
	}
	else
		displayMissAction(_name, "Attack");
}

void	ScavTrap::guardGate()
{
	std::cout << "Guarding the gate. GIVE ME MY MONEY !\n";
}
