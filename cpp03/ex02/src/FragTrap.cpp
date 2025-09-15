#include "../inc/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    this->_hp = default_hp;
    this->_ep = default_ep;
    this->_ad = default_ad;
    std::cout << "FragTrap " << this->name << " created with default constructor." << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
    this->_hp = default_hp;
    this->_ep = default_ep;
    this->_ad = default_ad;
    std::cout << "FragTrap " << this->name << " created with parameterized constructor." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    std::cout << "FragTrap " << this->name << " created with copy constructor." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << "FragTrap " << this->name << " assigned using assignment operator." << std::endl;
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << this->name << " destroyed." << std::endl;
}

void FragTrap::attack(const std::string& target) {
    if (this->_ep > 0 && this->_hp > 0) {
        std::cout << "FragTrap " << this->name << " attacks " << target 
                  << ", causing " << this->_ad << " points of damage!" << std::endl;
        this->_ep--;
    } else {
        std::cout << "FragTrap " << this->name << " cannot attack, either out of energy or destroyed." << std::endl;
    }
}

void FragTrap::highFivesGuys() {
    if (this->_hp > 0) {
        std::cout << "FragTrap " << this->name << " requests a high five!" << std::endl;
    } else {
        std::cout << "FragTrap " << this->name << " is destroyed and cannot request a high five." << std::endl;
    }
}