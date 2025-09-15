#include "../inc/ClapTrap.hpp"

int main() {
    std::cout << "\n--- Basic Constructor Tests ---" << std::endl;
    ClapTrap clap1;
    ClapTrap clap2("Vorp");
    ClapTrap clap3(clap2);  // copy constructor
    ClapTrap clap4;
    clap4 = clap2;          // assignment operator

    std::cout << "\n--- Action Tests ---" << std::endl;
    clap2.attack("Stupid Moron");
    clap2.takeDamage(5);
    clap2.beRepaired(3);

    std::cout << "\n--- Energy Exhaustion Test ---" << std::endl;
    ClapTrap clap5("Exhausted");
    for (int i = 0; i < 11; i++) 
    {
        clap5.attack("Another Moron");
    }

    std::cout << "\n--- Destroyed ClapTrap Test ---" << std::endl;
    ClapTrap clap6("Fragile");
    clap6.takeDamage(15);
    clap6.attack("Cool Guy");
    clap6.beRepaired(5);
    return 0;
}
