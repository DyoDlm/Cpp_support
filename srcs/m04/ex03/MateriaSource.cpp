#include "MateriaSource.hpp"

MateriaSource::MateriaSource() :
	_lastMateria(NULL)
{
	for (int i = 0; i < FLOOR_SIZE; i++)
		_floor[i] = NULL;
	for (int i = 0; i < 4; i++)
		_invetory[i] = NULL;
	std::cout << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < FLOOR_SIZE; i++)
	{
		if (_floor[i])
			delete _floor[i];
		_floor[i] = NULL;
	}
	for (int i = 0; i < 4; i++)
	{
		if (_invetory[i])
			delete _invetory[i];
		_invetory[i] = NULL;
	}
	std::cout << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &obj) :
	_lastMateria(obj._lastMateria)
{
	for (int i = 0; i < FLOOR_SIZE; i++)
		_floor[i] = obj._floor[i];
	for (int i = 0; i < 4; i++)
		_invetory[i] = obj._invetory[i];
	std::cout << std::endl;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &obj)
{
	if (this != &obj)
	{
		for (int i = 0; i < FLOOR_SIZE; i++)
			this->_floor[i] = obj._floor[i];
		for (int i = 0; i < 4; i++)
			this->_invetory[i] = obj._invetory[i];
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria *materia)
{
	if (!materia)
		return ;

	int	i = 0;

	while (i < 4 && _invetory[i])
		i++;
	if (i < 4)
	{
		std::cout << GREEN << "New materia learned : " << materia->getType()
		<< RESET << std::endl;
		_invetory[i] = materia;
		_lastMateria = materia;
	}
	else
	{
		i = 0;
		while (_floor[i] && i < FLOOR_SIZE)
			i++;
		if (i != FLOOR_SIZE)
			_floor[i] = materia;
		else
			std::cout << RED << "Floor full\n";
		std::cout << RED << "Inventory full" << RESET << std::endl;
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	int	i = 0;

	for (; i < 4; i++)
		if (_invetory[i] && _invetory[i]->getType() == type)
		{
			std::cout << GREEN << "New materia created\n" << RESET;
			return (_invetory[i]->clone());
		}
	return NULL;
}
