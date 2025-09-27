#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	_ideas = new Brain();
	std::cout << GREEN << "In Cat's default constructor\n" << RESET;
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
	_ideas = new Brain(*obj._ideas);
	std::cout << GREEN << "Into Cat's copy constructor\n" << RESET;
}

Cat::~Cat()
{
	delete _ideas;
	std::cout << GREEN << "Into Cat's destructor\n" << RESET;
}

Cat	&Cat::operator=(const Cat &obj)
{
	std::cout << GREEN << "Into Cat's assignment operator '='\n" << RESET;
	if (this != &obj)
	{
		Animal::operator=(obj);
		delete _ideas;
		_ideas = new Brain(*obj._ideas);
	}
	return *this;
}

void	Cat::makeSound() const
{
		std::cout << GREEN << "\nI like MIAOUWLENCE\n" << RESET;
}
