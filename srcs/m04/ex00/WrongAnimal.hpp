#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iomanip>
# include <iostream>
# include <string>
# include "Colors.hpp"

class WrongAnimal
{
	protected:
		std::string	_type;
	public:
		WrongAnimal(std::string type = "No type");
		WrongAnimal(const WrongAnimal &obj);
		virtual	~WrongAnimal();

		WrongAnimal	&operator=(const WrongAnimal &obj);
		void		makeSound(void) const;
		std::string	getType() const;
};

#endif