#include "RPN.hpp"


int main(int ac , char **av){
    try{
        if(ac == 2){
            RPN rpn(av[1]);
            std::cout << rpn << std::endl;
        }else
            throw std::exception();
    } catch(std::exception &e){
        std::cerr << "Error"<< std::endl;
    }
}