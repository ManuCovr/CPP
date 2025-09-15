#include "../inc/ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap() : ClapTrap() {
    this->_hp = default_hp;
    this->_ep = default_ep;
    this->_ad = default_ad;
    std::cout << "ScavTrap " << this->name 
              << " created with default constructor." << std::endl;
}

// Parameterized constructor
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    this->_hp = default_hp;
    this->_ep = default_ep;
    this->_ad = default_ad;
    std::cout << "ScavTrap " << this->name 
              << " created with parameterized constructor." << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    std::cout << "ScavTrap " << this->name 
              << " created with copy constructor." << std::endl;
}

// Copy assignment operator
ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other); // copies name, _hp, _ep, _ad
        std::cout << "ScavTrap " << this->name 
                  << " assigned with copy assignment operator." << std::endl;
    }
    return *this;
}

// Destructor
ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << this->name << " destroyed." << std::endl;
}

// Overridden attack
void ScavTrap::attack(const std::string& target) {
    if (this->_hp == 0) {
        std::cout << "ScavTrap " << this->name 
                  << " cannot attack because it is destroyed!" << std::endl;
        return;
    }
    if (this->_ep == 0) {
        std::cout << "ScavTrap " << this->name 
                  << " cannot attack because it has no energy!" << std::endl;
        return;
    }
    this->_ep--;
    std::cout << "ScavTrap " << this->name 
              << " ferociously attacks " << target 
              << ", causing " << this->_ad << " points of damage!" << std::endl;
}

// Special ability
void ScavTrap::guardGate() {
    if (this->_hp == 0) {
        std::cout << "ScavTrap " << this->name 
                  << " cannot enter Gate keeper mode because it is destroyed!" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << this->name 
              << " is now in Gate keeper mode!" << std::endl;
}
