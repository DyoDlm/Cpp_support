#include "AForm.hpp"
#include "Bureaucrat.hpp"

std::ostream	&operator<<(std::ostream &out, const AForm &obj)
{
	out << obj.getName() << " AForm\nSigned status " << (obj.getDocStatus() ? "true" : "false");
	out << "\nGrade to be signed : " << obj.getSignGrade()
		<< "\nGrade to be exec   : " << obj.getExecGrade() << '\n';
	return (out);
}

AForm::AForm(std::string name, short int gradeE, short int gradeS) : 
	_name(name), _signed(0), _gradeToSign(gradeS), _gradeToExec(gradeE)
{
	std::cout << std::endl;
}

AForm::AForm(const AForm &obj) :
	_name(obj._name), _gradeToSign(obj._gradeToSign), _gradeToExec(obj._gradeToExec)
{
	this->_signed = obj._signed;
	std::cout << std::endl;
}

AForm::~AForm()
{
	std::cout << std::endl;
}
AForm	&AForm::operator=(const AForm &obj)
{
	(void)obj;
	std::cout << std::endl;
	return *this;
}

std::string	AForm::getName() const
{
	return _name;
}

bool	AForm::getDocStatus() const
{
	return _signed;
}

short int	AForm::getSignGrade() const
{
	return _gradeToSign;
}

short int	AForm::getExecGrade() const
{
	return _gradeToExec;
}

void	AForm::beSigned(const Bureaucrat &id)
{
	if (id.getGrade() > this->getSignGrade())
		throw AForm::GradeToLowException();
	this->_signed = true;
}

void	AForm::execute(const Bureaucrat &id)
{
	if (id.getGrade() > _gradeToExec)
		throw GradeToLowException();
	if (!_signed)
		throw UnsignedException();

	std::cout << GREEN << id << " executed" << *this << RESET << std::endl;
}

const char	*AForm::GradeToHighException::what() const throw()
{
	return "Error: Grade too High";
}

const char	*AForm::GradeToLowException::what() const throw()
{
	return "Error: Grade too Low";
}
const char	*AForm::UnsignedException::what() const throw()
{
	return "Error: Document Unsigned";
}

