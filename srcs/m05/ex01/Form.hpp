#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Colors.hpp"
//# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	const std::string	_name;
	bool				_signed;
	const short int		_gradeToSign;
	const short int		_gradeToExec;
	public:
		Form(std::string name = "no name", short int gradeE = 150, short int gradeS = 150);
		Form(const Form &obj);
		~Form();

		Form	&operator=(const Form &obj);

		std::string	getName() const;
		bool		getDocStatus() const;
		short int	getSignGrade() const;
		short int	getExecGrade() const;

		void		beSigned(const Bureaucrat &id);

		class GradeToLowException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
		class GradeToHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const Form &obj);

#endif