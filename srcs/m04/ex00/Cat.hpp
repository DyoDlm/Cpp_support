#ifndef CAT_HPP
# define CAT_HPP

# include <iomanip>
# include <iostream>
# include <string>
# include "Colors.hpp"
# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &obj);
		~Cat();

		Cat				&operator=(const Cat &obj);
		virtual void	makeSound() const;
};

#endif
