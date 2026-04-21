#include "BitcoinExchange.hpp"

int main(int ac , char **av){
    if(ac == 2)
        BitcoinExchange bt(av[1],"./data.csv");
    else
        std::cerr << "Error: could not open file." << std::endl;
    return 0;
}
