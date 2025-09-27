#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iomanip>
# include <iostream>
# include <string>
# include "Colors.hpp"

class Animal
{
	protected:
		std::string	_type;
	public:
		Animal(std::string type = "NO TYPE");
		Animal(const Animal &obj);
		virtual		~Animal();

		Animal			&operator=(const Animal &obj);
		virtual void	makeSound(void) const = 0;
		std::string		getType() const;
};

#endif
