#include "Cure.hpp"

Cure::Cure() : AMateria()
{
	_type = "cure";
	return ;
}

Cure::Cure(const Cure &obj) : AMateria(obj)
{
	_type = "cure";
}

Cure::~Cure()
{
	return ;
}

Cure	&Cure::operator=(const Cure &obj)
{
	(void)obj;
	return *this;
}

Cure	*Cure::clone() const
{
	return new Cure(*this);
}

void	Cure::use(ICharacter &target)
{
	std::cout << CYAN << "* heals " << target.getName() << "'s wounds"
	<< " *\n" << std::endl << RESET;
}
