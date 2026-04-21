#include "../inc/Form.hpp"

Form::Form(): _gradeSign(0), _gradeExe(0){}

Form::Form(std::string name, int gradeSign, int gradeExe): _name(name), _gradeSign(gradeSign), _gradeExe(gradeExe)
{
	if (gradeSign > 150 || gradeExe > 150)
		throw GradeTooLowException();
	else if (gradeSign < 1 || gradeSign < 1)
		throw GradeTooHighException();
	_sign = false;
}

Form::Form(const Form& ref): _name(ref._name), _gradeSign(ref._gradeSign), _gradeExe(ref._gradeExe)
{
	*this = ref;
}

Form&	Form::operator=(const Form& ref)
{
	if (this != &ref)
		this->_sign = ref._sign;
	return *this;
}

Form::~Form(){}

const char	*Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

void	Form::beSigned(const Bureaucrat &dude)
{
	if (this->getGradeSign() < dude.getGrade())
		throw GradeTooLowException();
	else
		this->_sign = true;
}

std::string	Form::getName() const
{
	return _name;
}

bool	Form::getSign() const
{
	return _sign;
}

int	Form::getGradeSign() const
{
	return _gradeSign;
}

int	Form::getGradeExe() const
{
	return _gradeExe;
}

std::ostream&	operator<<(std::ostream& out, const Form& ref)
{
	return out << " Form name - " << ref.getName() << ", Form is signed - " << ref.getSign() << ", Grade to sign - " << ref.getGradeSign() << ", Grade to execute - " << ref.getGradeExe();
}