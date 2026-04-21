#include "../inc/AForm.hpp"

AForm::AForm(): _gradeSign(0), _gradeExe(0){}

AForm::AForm(std::string name, int gradeSign, int gradeExe): _name(name), _gradeSign(gradeSign), _gradeExe(gradeExe)
{
	if (gradeSign > 150 || gradeExe > 150)
		throw GradeTooLowException();
	else if (gradeSign < 1 || gradeSign < 1)
		throw GradeTooHighException();
	_sign = false;
}

AForm::AForm(const AForm& ref): _name(ref._name), _gradeSign(ref._gradeSign), _gradeExe(ref._gradeExe)
{
	*this = ref;
}

AForm&	AForm::operator=(const AForm& ref)
{
	if (this != &ref)
		this->_sign = ref._sign;
	return *this;
}

AForm::~AForm(){}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

void	AForm::beSigned(const Bureaucrat &dude)
{
	if (this->getGradeSign() < dude.getGrade())
		throw GradeTooLowException();
	else
		this->_sign = true;
}

std::string	AForm::getName() const
{
	return _name;
}

bool	AForm::getSign() const
{
	return _sign;
}

int	AForm::getGradeSign() const
{
	return _gradeSign;
}

int	AForm::getGradeExe() const
{
	return _gradeExe;
}

std::ostream&	operator<<(std::ostream& out, const AForm& ref)
{
	return out << " Form name - " << ref.getName() << ", Form is signed - " << ref.getSign() << ", Grade to sign - " << ref.getGradeSign() << ", Grade to execute - " << ref.getGradeExe();
}