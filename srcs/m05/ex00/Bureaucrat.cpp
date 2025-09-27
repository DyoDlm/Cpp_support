#include "Bureaucrat.hpp"

///////////////////////////////////////////////////////////////////////
////////////////	Debut de rubrique "a ne pas faire"	///////////////
///////////////////////////////////////////////////////////////////////

void	levelUp(Bureaucrat &id)
{
	if (id.getGrade() == 1)
	{
		std::cout << id.getName() << " is already at maximum grade\n"
		<< "His grade hasn't been changed" << std::endl;
	}
	else
	{
		id.setGrade(-1);
		std::cout << id.getName()
		<< " has been leveled Up\tNew grade : " << id.getGrade()
		<< std::endl;
	}
}

void	levelDown(Bureaucrat &id)
{
	if (id.getGrade() == 150)
	{
		std::cout << id.getName() << " is already at minimum grade\n"
		<< "His grade hasn't been changed\n" << std::endl;
	}
	else
	{
		id.setGrade(1);
		std::cout << id.getName()
		<< " has been leveled Down\tNew grade : " << id.getGrade()
		<< std::endl;
	}
}
///////////////////////////////////////////////////////////////////////
////////////////	Fin de rubrique "a ne pas faire"	///////////////
///////////////////////////////////////////////////////////////////////

std::ostream    &operator<<(std::ostream &out, const Bureaucrat &id)
{
	out << id.getName() << ", bureaucrat grade " << id.getGrade() << std::endl;
	return out;
}

Bureaucrat::Bureaucrat(std::string name, short int grade) : _name(name), _grade(grade)
{
	if (grade < MIN_GRADE)
		throw GradeTooHighException();
	if (grade > MAX_GRADE)
		throw GradeTooLowException();
	_grade = grade;
	std::cout << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : _name(obj._name), _grade(obj._grade)
{
	std::cout << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &obj)
{
	std::cout << std::endl;
	if (this != &obj)
		this->_grade = obj._grade;
	return *this;
}

short int	Bureaucrat::getGrade() const
{
	return _grade;
}

std::string	Bureaucrat::getName() const
{
	return _name;
}

void	Bureaucrat::setGrade(short int value)
{
	_grade += value;
}

void	Bureaucrat::incrementGrade()
{
	if (_grade - 1 < MIN_GRADE)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade + 1 > MAX_GRADE)
		throw GradeTooLowException();
	_grade++;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

