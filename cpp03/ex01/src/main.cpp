#include "../inc/ScavTrap.hpp"
#include "../inc/ClapTrap.hpp"

int main() {
    std::cout << "\n--- ScavTrap Basic Tests ---" << std::endl;
    ScavTrap scav1("Guardian");

    std::cout << "\n--- Copy & Assignment ---" << std::endl;
    ScavTrap scav2(scav1);    // copy constructor
    ScavTrap scav3("Temp");
    scav3 = scav1;            // assignment operator

    std::cout << "\n--- Attack & Inherited Functions ---" << std::endl;
    scav1.attack("Enemy");
    scav1.takeDamage(30);
    scav1.beRepaired(15);

    std::cout << "\n--- Special Ability ---" << std::endl;
    scav1.guardGate();

    std::cout << "\n--- Destroyed ScavTrap ---" << std::endl;
    ScavTrap scav5("Fragile");
    scav5.takeDamage(200);   // destroy it
    scav5.attack("Target");
    scav5.guardGate();

    std::cout << "\n--- ClapTrap vs ScavTrap Comparison ---" << std::endl;
    ClapTrap clap("BasicBot");
    ScavTrap scav6("SuperBot");
    clap.attack("Target");
    scav6.attack("Target");
    

    std::cout << "\n--- Stats Summary ---" << std::endl;
    std::cout << "ClapTrap: HP(10), Energy(10), Attack(0)" << std::endl;
    std::cout << "ScavTrap: HP(100), Energy(50), Attack(20)" << std::endl;

    return 0;
}
