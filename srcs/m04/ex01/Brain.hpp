#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>
# include "Colors.hpp"

# define NB_IDEAS 100

class Brain
{
	protected:
		std::string	ideas[NB_IDEAS];
	public:
		Brain();
		Brain(const Brain &obj);

		~Brain();

		Brain	&operator=(const Brain &obj);

};

#endif