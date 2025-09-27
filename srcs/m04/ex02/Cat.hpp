#ifndef CAT_HPP
# define CAT_HPP

# include <iomanip>
# include <iostream>
# include <string>
# include "Colors.hpp"
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	Brain	*_ideas;
	public:
		Cat();
		Cat(const Cat &obj);
		~Cat();

		Cat				&operator=(const Cat &obj);
		virtual void	makeSound() const;
};

#endif
