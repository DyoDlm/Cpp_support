#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << CYAN << "In Dog default constructor\n" << RESET;
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
	std::cout << CYAN << "In Dog Copy constructor\n" << RESET;
}

Dog::~Dog()
{
	std::cout << CYAN << "In Dog destructor\n" << RESET;
}

Dog	&Dog::operator=(const Dog &obj)
{
	std::cout << CYAN << "In Dog assignment operator '='\n" << RESET;
	if (this != &obj)
		*this = obj;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << CYAN << "\nI like WAFFle WAFFle" << std::endl << RESET;
}
