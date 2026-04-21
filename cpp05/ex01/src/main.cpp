#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main()
{
    try
    {
        Bureaucrat  john("John", 50);
        Bureaucrat  mike("Mike", 120);

        Form        easy("EasyForm", 120, 100);
        Form        hard("HardForm", 40, 30);

        std::cout << john << std::endl;
        std::cout << mike << std::endl;
        std::cout << easy << std::endl;
        std::cout << hard << std::endl << std::endl;

        john.signForm(easy);   // should succeed
        john.signForm(hard);   // may fail (too low)
        mike.signForm(easy);   // already signed
        mike.signForm(hard);   // should fail (too low)

        std::cout << std::endl;
        std::cout << easy << std::endl;
        std::cout << hard << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception in main: " << e.what() << std::endl;
    }
}
