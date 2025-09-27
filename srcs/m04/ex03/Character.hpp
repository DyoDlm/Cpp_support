#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"

# define VIRTUAL_POCKET 100

class Character : public ICharacter
{
	std::string	_name;
	AMateria	*_slots[4];
	AMateria	*_unused[VIRTUAL_POCKET];
	public:
		Character(std::string name = "Unamed");
		Character(const Character &obj);
		~Character();

		Character	&operator=(const Character &obj);

		std::string const	&getName() const;
	
		virtual void		equip(AMateria *m);
		virtual void		unequip(int idx);
		virtual void		use(int idx, ICharacter &target);
		void				stackFloor(AMateria *m);
};

#endif