#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& ref): _name(ref._name)
{
	*this = ref;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ref)
{
	if (this != &ref)
		this->_grade = ref._grade;
	return *this;
}

Bureaucrat::~Bureaucrat(){}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

void	Bureaucrat::upGrade()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
	std::cout << "Upgraded " << getName() << "'s grade to " << getGrade() << std::endl;
}

void	Bureaucrat::downGrade()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
	std::cout << "Downgraded " << getName() << "'s grade to " << getGrade() << std::endl;
}

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

std::string	Bureaucrat::getName() const
{
	return _name;
}

int		Bureaucrat::getGrade() const
{
	return _grade;
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& ref)
{
	return out << ref.getName() << ", bureaucrat's grade is " << ref.getGrade();
}