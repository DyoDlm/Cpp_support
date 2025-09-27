#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"
# include "Colors.hpp"
# include "AMateria.hpp"

# define FLOOR_SIZE 10

class MateriaSource : public IMateriaSource
{
	AMateria	*_lastMateria;
	AMateria	*_floor[FLOOR_SIZE];
	AMateria	*_invetory[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &obj);
		virtual	~MateriaSource();

		MateriaSource	&operator=(const MateriaSource &obj);

		const AMateria	*getMateria() const;

		virtual void		learnMateria(AMateria *materia);
		virtual AMateria	*createMateria(std::string const &type);

};

#endif