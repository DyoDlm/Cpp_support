#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "Colors.hpp"
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class ShrubberyCreationForm : virtual public AForm
{
	std::string	_target;
	public:
		ShrubberyCreationForm(std::string target = "UnknownTarget");
		ShrubberyCreationForm(const ShrubberyCreationForm &form);
		~ShrubberyCreationForm();

		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &);

		void					execute(Bureaucrat const &executor);
};

#endif