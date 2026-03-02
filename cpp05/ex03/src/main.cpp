#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/Intern.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

int main()
{
    Intern someRandomIntern;
    Bureaucrat john("John", 1);
    Bureaucrat mike("Mike", 75);
    
    std::cout << "=== Intern creates valid forms ===" << std::endl;
    AForm* pres = someRandomIntern.makeForm("presidential pardon", "Zaphod");
    AForm* robot = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm* shrub = someRandomIntern.makeForm("shrubbery creation", "42HQ");
    
    std::cout << "\n=== John (grade 1) tests ===" << std::endl;
    std::cout << john << std::endl;
    
    john.signForm(*pres);
    john.executeForm(*pres);  // success
    
    john.signForm(*robot);
    john.executeForm(*robot); // 50/50
    
    john.signForm(*shrub);
    john.executeForm(*shrub); // creates file
    
    std::cout << "\n=== Mike (grade 75) tests ===" << std::endl;
    std::cout << mike << std::endl;
    
    mike.executeForm(*pres);  // fails (too low)
    mike.executeForm(*shrub); // fails (too low)
    
    std::cout << "\n=== Invalid form ===" << std::endl;
    AForm* invalid = someRandomIntern.makeForm("fake form", "nobody");
    
    delete pres;
    delete robot;
    delete shrub;
    delete invalid;
    
    return 0;
}
