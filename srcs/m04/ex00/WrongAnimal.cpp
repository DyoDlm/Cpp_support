#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << WHITE << "In Default WrongAnimal constructor\n" << RESET;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
	this->_type = obj._type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << WHITE << "In WrongAnimal destructor\n" << RESET;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &obj)
{
	std::cout << WHITE << "In WrongAnimal assigment operator '='\n" << RESET;
	if (this != &obj)
		*this = obj;
	return (*this);
}

void	WrongAnimal::makeSound() const
{
	std::cout << RED << "I like euh... something\n" << RESET;
}

std::string	WrongAnimal::getType() const
{
	return (_type);
}
