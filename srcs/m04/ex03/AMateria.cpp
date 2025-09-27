#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) :
	_type(type)
{
	std::cout << "AMateria constructor" << std::endl;
}

AMateria::AMateria(const AMateria &obj) :
	_type(obj._type)
{
	std::cout << "AMateria copy constructor" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor" << std::endl;
}

AMateria	&AMateria::operator=(const AMateria &obj)
{
	if (this != &obj)
	{
		_type = obj._type;
	}
	std::cout << "AMateria assignment operator" << std::endl;
	return *this;
}

std::string const	&AMateria::getType() const
{
	return _type;
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "AMateria use\n";
	std::cout << "Use materia on " << target.getName() << std::endl;
	return ;
}
