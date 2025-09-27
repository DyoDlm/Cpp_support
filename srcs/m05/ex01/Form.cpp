#include "Form.hpp"
#include "Bureaucrat.hpp"

std::ostream	&operator<<(std::ostream &out, const Form &obj)
{
	out << obj.getName() << " form\nSigned status " << (obj.getDocStatus() ? "true" : "false");
	out << "\nGrade to be signed : " << obj.getSignGrade()
		<< "\nGrade to be exec   : " << obj.getExecGrade() << '\n';
	return (out);
}

Form::Form(std::string name, short int gradeE, short int gradeS) : 
	_name(name), _signed(0), _gradeToSign(gradeS), _gradeToExec(gradeE)
{
	std::cout << std::endl;
}

Form::Form(const Form &obj) :
	_name(obj._name), _gradeToSign(obj._gradeToSign), _gradeToExec(obj._gradeToExec)
{
	this->_signed = obj._signed;
	std::cout << std::endl;
}

Form::~Form()
{
	std::cout << std::endl;
}
Form	&Form::operator=(const Form &obj)
{
	(void)obj;
	std::cout << std::endl;
	return *this;
}

std::string	Form::getName() const
{
	return _name;
}

bool	Form::getDocStatus() const
{
	return _signed;
}

short int	Form::getSignGrade() const
{
	return _gradeToSign;
}

short int	Form::getExecGrade() const
{
	return _gradeToExec;
}

void	Form::beSigned(const Bureaucrat &id)
{
	if (id.getGrade() > this->getSignGrade())
		throw Form::GradeToLowException();
	this->_signed = true;
}

const char	*Form::GradeToHighException::what() const throw()
{
	return "Grade too High";
}

const char	*Form::GradeToLowException::what() const throw()
{
	return "Grade too Low";
}

