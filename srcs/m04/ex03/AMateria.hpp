#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "Colors.hpp"
# include "ICharacter.hpp"
# include "MateriaSource.hpp"

class ICharacter;
class MateriaSource;

class AMateria
{
	protected:
		std::string		_type;
	public:
		AMateria(std::string const &type = "No type");
		AMateria(const AMateria &obj);
		virtual	~AMateria();

		AMateria	&operator=(const AMateria &obj);

		const std::string	&getType() const;
		
		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target);
};

#endif