#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

# include <iostream>
# include <string>
# include <time.h>
# include "Colors.hpp"
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class RobotomyRequestForm : virtual public AForm
{
	std::string	_target;
	public:
		RobotomyRequestForm(std::string name = "UnamedTarget");
		RobotomyRequestForm(const RobotomyRequestForm &form);
		~RobotomyRequestForm();
	
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &);
	
		void				execute(Bureaucrat const &executor);
};

#endif