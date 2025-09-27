#include "Character.hpp"

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_slots[i] = NULL;
	for (int i = 0; i < VIRTUAL_POCKET; i++)
		_unused[i] = NULL;
	std::cout << "Character constructor" << std::endl;
}

Character::Character(const Character &obj)
{
	this->_name = obj._name;
	for (int i = 0; i < 4; i++)
		_slots[i] = obj._slots[i] ? obj._slots[i]->clone() : NULL;
	for (int i = 0; i < VIRTUAL_POCKET; i++)
		_unused[i] = obj._unused[i];

	std::cout << "Character copy constructor" << std::endl;
}

Character::~Character()
{
	int	i = 0;
	for (; i < 4; i++)
	{
		if (i < 4 && this->_slots[i])
		{
			delete this->_slots[i];
			this->_slots[i] = NULL;
		}
	//	else if (this->_unused[i])
	//	{
	//		delete this->_unused[i];
	//		this->_unused[i] = NULL;
	//	}
	}
	i = 0;
	while (i < VIRTUAL_POCKET)
	{
		if (this->_unused[i])
		{
			delete this->_unused[i];
			this->_unused[i] = NULL;
		}
		i++;
	}
	std::cout << "Character destructor" << std::endl;
}

Character	&Character::operator=(const Character &obj)
{
	std::cout << std::endl;
	if (this != &obj)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_slots[i])
				delete _slots[i];
			this->_slots[i] = obj._slots[i]->clone();
		}
		this->_name = obj._name;
	}
	std::cout << "Into Character assignment operator=\n";
	return (*this);
}

std::string const	&Character::getName() const
{
	return _name;
}

void	Character::equip(AMateria *m)
{
	if (!m)
	{
		std::cout << RED << "No materia to equip\n" << RESET;
		return ;
	}

	int	i = 0;

	while (_slots[i])
		i++;
	std::cout << "New materia's index : " << i << std::endl;
	if (i < 4)
	{
		_slots[i] = m->clone();
		std::cout << GREEN << m->getType() << " equiped to " << _name << RESET << std::endl;
	}
	else
	{
		stackFloor(m);
		std::cout << RED << "Full inventory" << RESET << std::endl;
	}
}

void	Character::stackFloor(AMateria *m)
{
	int	i = 0;
	
	while (i < VIRTUAL_POCKET && _unused[i])
		i++;
	if (i != VIRTUAL_POCKET)
		_unused[i] = m;
	std::cout << ROSE << m->getType() << " stacked at : " << i << std::endl << RESET;
}

void	Character::unequip(int idx)
{
	if (idx < 4 && idx > -1)
	{
		if (_slots[idx])
		{
			std::cout << GREEN <<_slots[idx]->getType() << "Unequiped\n" << RESET;
			stackFloor(_slots[idx]);
		}
		else
			std::cout << RED << "Nothing to unequip\n" << RESET;
		_slots[idx] = NULL;
	}
	else
		std::cout << RED << "Bad idx" << RESET << std::endl;
}

void	Character::use(int idx, ICharacter &target)
{
	std::cout << _name << std::endl;
	if (idx > 3 || idx < 0)
	{
		std::cout << RED << "Bad idx" << RESET << std::endl;
		return ;
	}
	if (_slots[idx])
	{
		_slots[idx]->use(target);
	}
	else
		std::cout << RED << "* Do something weird to " << target.getName() << " *"
		<< RESET << std::endl;
}
