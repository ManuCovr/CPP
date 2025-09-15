#include "../inc/FragTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include "../inc/ClapTrap.hpp"

int main() {
    std::cout << "\n=== FragTrap Tests ===" << std::endl;

    std::cout << "\n--- Basic Construction ---" << std::endl;
    FragTrap frag1("WarBot");

    std::cout << "\n--- Copy & Assignment ---" << std::endl;
    FragTrap frag2(frag1);      // copy constructor
    FragTrap frag3("Temp");
    frag3 = frag1;              // assignment operator

    std::cout << "\n--- Attack & Inherited Functions ---" << std::endl;
    frag1.attack("Enemy");
    frag1.takeDamage(40);
    frag1.beRepaired(20);

    std::cout << "\n--- Special Ability ---" << std::endl;
    frag1.highFivesGuys();

    std::cout << "\n--- Destroyed FragTrap ---" << std::endl;
    FragTrap deadBot("DeadBot");
    deadBot.highFivesGuys();
    deadBot.takeDamage(200);   // destroy it
    deadBot.attack("Target");
    deadBot.highFivesGuys();

    std::cout << "\n--- Class Comparison ---" << std::endl;
    ClapTrap clap("BasicBot");
    ScavTrap scav("GuardBot");
    FragTrap frag("SuperBot");

    clap.attack("Target");
    scav.attack("Target");
    frag.attack("Target");

    std::cout << "\n--- Stats Summary ---" << std::endl;
    std::cout << "ClapTrap: HP(10), Energy(10), Attack(0)" << std::endl;
    std::cout << "ScavTrap: HP(100), Energy(50), Attack(20)" << std::endl;
    std::cout << "FragTrap: HP(100), Energy(100), Attack(30)" << std::endl;

    return 0;
}
