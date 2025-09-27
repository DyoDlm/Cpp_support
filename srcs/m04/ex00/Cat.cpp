#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << GREEN << "In Cat's default constructor\n" << RESET;
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
	std::cout << GREEN << "Into Cat's copy constructor\n" << RESET;
}

Cat::~Cat()
{
	std::cout << GREEN << "Into Cat's destructor\n" << RESET;
}

Cat	&Cat::operator=(const Cat &obj)
{
	std::cout << GREEN << "Into Cat's assignment operator '='\n" << RESET;
	if (this != &obj)
		*this = obj;
	return *this;
}

void	Cat::makeSound() const
{
		std::cout << GREEN << "\nI like MIAOUWLENCE\n" << RESET;
}
