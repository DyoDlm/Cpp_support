#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Colors.hpp"

# define MAX_GRADE 150
# define MIN_GRADE 1

class Bureaucrat
{
	const std::string	_name;
	short int			_grade;
	public:
		Bureaucrat(std::string name = "no name", short int grade = 150);
		Bureaucrat(const Bureaucrat &obj);
		~Bureaucrat();
		
		Bureaucrat	&operator=(const Bureaucrat &obj);
		short int	getGrade() const;
		std::string	getName() const;

		void		setGrade(short int value);
		void		incrementGrade();
		void		decrementGrade();

	class GradeTooHighException : public std::exception
	{
		public:
			const char	*what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char	*what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &obj);

void		levelUp(Bureaucrat &id);	//	SHLAG PROGRAMMING
void		levelDown(Bureaucrat &id);	//	SHLAG PROGRAMMING

#endif