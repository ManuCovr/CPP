#include "../inc/RobotomyRequestForm.hpp"
#include <cstdlib>  // srand, rand
#include <ctime>    // time

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref)
    : AForm(ref), _target(ref._target)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& /*ref*/)
{
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

const char* RobotomyRequestForm::GradeTooLowException::what() const throw()
{
    return "Grade too low to be Robotmized";
}

std::string RobotomyRequestForm::getTarget() const
{
    return _target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (this->getSign() && executor.getGrade() <= this->getGradeExe())
    {
        srand(time(NULL));
        if (rand() % 2)
            std::cout << "BZZZBZZZBZZZ robotomy was a success for " << getTarget() << "! No more traumas" << std::endl;
        else
            std::cout << "BZZZZZZZbzzzzz.. oh.. now " << getTarget() << "'s a vegetable" << std::endl;
    }
    else
        throw GradeTooLowException();  // <-- YOUR exception, not AForm's
}
