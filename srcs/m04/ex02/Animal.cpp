#include "Animal.hpp"

Animal::Animal(std::string type) : _type(type)
{
	std::cout << WHITE << "In Default Animal constructor\n" << RESET;
}

Animal::Animal(const Animal &obj)
{
	this->_type = obj._type;
}

Animal::~Animal()
{
	std::cout << WHITE << "In Animal destructor\n" << RESET;
}

Animal	&Animal::operator=(const Animal &obj)
{
	std::cout << WHITE << "In Animal assigment operator '='\n" << RESET;
	if (this != &obj)
		*this = obj;
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << WHITE << "I like euh... something\n" << RESET;
}

std::string	Animal::getType() const
{
	return (_type);
}
