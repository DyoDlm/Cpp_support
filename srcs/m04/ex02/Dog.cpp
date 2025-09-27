#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	_ideas = new Brain();
	std::cout << GREEN << "In Dog's default constructor\n" << RESET;
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
	_ideas = new Brain(*obj._ideas);
	std::cout << CYAN << "In Dog Copy constructor\n" << RESET;
}

Dog::~Dog()
{
	delete _ideas;
	std::cout << CYAN << "In Dog destructor\n" << RESET;
}

Dog	&Dog::operator=(const Dog &obj)
{
	std::cout << CYAN << "In Dog assignment operator '='\n" << RESET;
	if (this != &obj)
	{
		Animal::operator=(obj);
		delete _ideas;
		_ideas = new Brain(*obj._ideas);
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << CYAN << "\nI like WAFFle WAFFle" << std::endl << RESET;
}

