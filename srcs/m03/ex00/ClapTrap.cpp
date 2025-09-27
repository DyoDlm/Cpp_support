#include "Claptrap.hpp"

ClapTrap::ClapTrap(std::string name) : _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << WHITE << "In Default Constructor creating : " << name << std::endl;
	this->_name = name;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	this->_name = obj._name;
	this->_HitPoints = obj._HitPoints;
	this->_EnergyPoints = obj._EnergyPoints;
	this->_AttackDamage = obj._AttackDamage;
}

ClapTrap::~ClapTrap()
{
	std::cout << "In Default Destructor" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &obj)
{
	if (this != &obj)
		*this = obj;
	return *this;
}

void	displayMissAction(std::string name, std::string action)
{
	std::cout << "ClapTrap " << name << " can't do " << "'"
	<< action << "' " << "\nPlayer dead or missing Energy points" << std::endl;
}

void	ClapTrap::displayPlayerStatus(void)
{
	std::cout << YELLOW << "\nREPORTING PLAYER STATUS \n";
	if (_HitPoints)
		std::cout << GREEN;
	else
		std::cout << RED;
	std::cout << _name << " : \n\n" << CYAN
	<< "ATTACK DAMAGE : " << _AttackDamage << "\n"
	<< "ENERGY POINTS : " << _EnergyPoints << "\n"
	<< "HIT POINTS    : " << _HitPoints << RESET << "\n\n";
}

void	ClapTrap::attack(const std::string &target)
{
	if (_EnergyPoints && _HitPoints)
	{
		std::cout << "ClapTrap " << _name << " attacks : " << target
		<< ", causing : " << _AttackDamage << " points of damage." << std::endl;
		_EnergyPoints--;
	}
	else
		displayMissAction(_name, "Attack");
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " take " << amount
	<< " points of damage" << std::endl;
	_HitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_EnergyPoints && _HitPoints)
	{
		std::cout << "ClapTrap " << _name << " is repaired by :" << amount << std::endl;
		_HitPoints += amount;
		_EnergyPoints--;
	}
	else
		displayMissAction(_name, "Reparation");
}
