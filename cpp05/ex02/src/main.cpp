#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

int main()
{
    try
    {
        Bureaucrat john("John", 1);
        Bureaucrat mike("Mike", 149);
        
        std::cout << "=== John (grade 1) tests all forms ===" << std::endl;
        std::cout << john << std::endl;
        
        PresidentialPardonForm pres("homeworld");
        RobotomyRequestForm robot("Bender");
        ShrubberyCreationForm shrub("garden");
        
        john.signForm(pres);
        john.signForm(robot);
        john.signForm(shrub);
        
        john.executeForm(pres);  // success
        john.executeForm(robot); // 50/50
        john.executeForm(shrub); // success (creates file)
        
        std::cout << "\n=== Mike (grade 149) tests ===" << std::endl;
        std::cout << mike << std::endl;
        
        mike.signForm(shrub);    // only shrubbery is signable
        mike.executeForm(pres);  // fails (not signed + too low)
        mike.executeForm(shrub); // fails (too low grade)
        
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
