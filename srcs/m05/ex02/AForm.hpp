#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Colors.hpp"

class Bureaucrat;

class AForm
{
	const std::string	_name;
	bool				_signed;
	const short int		_gradeToSign;
	const short int		_gradeToExec;
	public:
		AForm(std::string name = "no name", short int gradeE = 150, short int gradeS = 150);
		AForm(const AForm &obj);
		virtual	~AForm();

		AForm	&operator=(const AForm &obj);

		std::string	getName() const;
		bool		getDocStatus() const;
		short int	getSignGrade() const;
		short int	getExecGrade() const;

		void			beSigned(const Bureaucrat &id);
		virtual void	execute(Bureaucrat const &executor);

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
		class UnsignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const AForm &obj);

#endif