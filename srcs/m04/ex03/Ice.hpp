#ifndef ICE_HPP
# define ICE_HPP

# include <string>
# include <iostream>
# include "Colors.hpp"
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice &obj);
		~Ice();

		Ice	&operator=(const Ice &obj);

		virtual Ice		*clone() const;
		virtual void	use(ICharacter &target);
};

#endif