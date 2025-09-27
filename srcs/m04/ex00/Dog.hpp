#ifndef DOG_HPP
# define DOG_HPP

# include <iomanip>
# include <iostream>
# include <string>
# include "Colors.hpp"
# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &obj);
		~Dog();

		Dog				&operator=(const Dog &obj);
		virtual void	makeSound() const;
};

#endif