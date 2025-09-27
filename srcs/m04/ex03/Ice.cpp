#include "Ice.hpp"

Ice::Ice() : AMateria()
{
	_type = "ice";
	std::cout << "Ice constructor\n";
	return ;
}

Ice::Ice(const Ice &obj) : AMateria(obj)
{
	_type = "ice";
	std::cout << "Ice copy constructor\n";
}

Ice::~Ice()
{
	std::cout << "Ice destructor\n";
}

Ice	&Ice::operator=(const Ice &obj)
{
	if (this != &obj)
		std::cout << "Assign" << std::endl;
	return *this;
}

Ice	*Ice::clone() const
{
	return new Ice(*this);
}

void	Ice::use(ICharacter &target)
{
	std::cout << CYAN << "* shoots an ice bolt at " << target.getName()
	<< " *" << std::endl << RESET;
}
