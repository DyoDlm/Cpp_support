#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << GREEN << "In WrongCat's default constructor\n" << RESET;
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj)
{
	std::cout << GREEN << "Into WrongCat's copy constructor\n" << RESET;
}
WrongCat::~WrongCat()
{
	std::cout << GREEN << "Into WrongCat's destructor\n" << RESET;
}

WrongCat	&WrongCat::operator=(const WrongCat &obj)
{
	std::cout << GREEN << "Into WrongCat's assignment operator '='\n" << RESET;
	if (this != &obj)
		*this = obj;
	return *this;
}

void	WrongCat::makeSound() const
{
		std::cout << GREEN << "\nI like MIAOUWLENCE\n" << RESET;
}
