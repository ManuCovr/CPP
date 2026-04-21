#include "../inc/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref)
    : AForm(ref), _target(ref._target)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& /*ref*/)
{
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const char* ShrubberyCreationForm::GradeTooLowException::what() const throw()
{
    return "Grade too low to create shrubbery";
}

std::string ShrubberyCreationForm::getTarget() const
{
    return _target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (this->getSign() && executor.getGrade() <= this->getGradeExe())
    {
        std::ofstream out((this->getTarget() + "_shrubbery").c_str());
        out << "     .{{}}}}}}}." << std::endl
            << "    {{{{{{(``)}}}." << std::endl
            << "   {{{{(``)}}}}}}}}}" << std::endl
            << "  }}}}}}}}}{{(`){{{{" << std::endl
            << "  }}}}{{{{(``)}}{{{{{" << std::endl
            << " {{{{(``)}}}}}}}}}}" << std::endl
            << "{{{{{{{{(``)}}}}}}}}}}" << std::endl
            << "{{{{{{{{{{{(``)}}}}}}}}" << std::endl
            << " {{{{{(``)   {{{{(``)}'" << std::endl
            << "        |   |      " << std::endl
            << "  ( )  /     \\" << std::endl
            << " ~~~~~~~~~~~~~~~~~~~" << std::endl;
        out.close();
        std::cout << "file created with a shrubbery inside" << std::endl;
    }
    else
        throw GradeTooLowException();
}
