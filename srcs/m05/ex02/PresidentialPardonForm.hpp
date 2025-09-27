#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

# include <iostream>
# include <string>
# include "Colors.hpp"
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class PresidentialPardonForm : virtual public AForm
{
	std::string	_target;
	public:
		PresidentialPardonForm(std::string target = "UnamedTarget");
		PresidentialPardonForm(const PresidentialPardonForm &form);
		~PresidentialPardonForm();

		PresidentialPardonForm	&operator=(const PresidentialPardonForm &);
		
		void					execute(Bureaucrat const &executor);
};


#endif