#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ref)
    : AForm(ref), _target(ref._target)
{}

PresidentialPardonForm&
PresidentialPardonForm::operator=(const PresidentialPardonForm& /*ref*/)
{
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

const char*
PresidentialPardonForm::GradeNotExcusedException::what() const throw()
{
    return "Grade not accepted, Zaphod Beeblebrox will never forgive you!";
}

std::string PresidentialPardonForm::getTarget() const
{
    return _target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (this->getSign() && executor.getGrade() <= this->getGradeExe())
        std::cout << this->getTarget()
                  << " has been pardoned by Zaphod Beeblebrox."
                  << std::endl;
    else
        throw GradeNotExcusedException();
}
