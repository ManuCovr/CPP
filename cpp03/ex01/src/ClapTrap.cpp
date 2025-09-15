#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), _hp(10), _ep(10), _ad(0) {
    std::cout << "ClapTrap " << name << " created with default constructor." << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : name(name), _hp(10), _ep(10), _ad(0) {
    std::cout << "ClapTrap " << name << " created with parameterized constructor." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : name(other.name), _hp(other._hp), 
                                             _ep(other._ep), _ad(other._ad) {
    std::cout << "ClapTrap " << name << " created with copy constructor." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    if (this != &other) {
        name = other.name;
        _hp = other._hp;
        _ep = other._ep;
        _ad = other._ad;
        std::cout << "ClapTrap " << name << " assigned with copy assignment operator." << std::endl;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " destroyed." << std::endl;
}

void ClapTrap::attack(const std::string &target) {
    if (_ep > 0 && _hp > 0) {
        std::cout << "ClapTrap " << name << " attacks " << target 
                  << ", causing " << _ad << " points of damage!" << std::endl;
        _ep--;
    } else {
        std::cout << "ClapTrap " << name << " cannot attack!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hp > amount) {
        _hp -= amount;
        std::cout << "ClapTrap " << name << " takes " << amount 
                  << " points of damage! Remaining hit points: " << _hp << std::endl;
    } else {
        _hp = 0;
        std::cout << "ClapTrap " << name << " has been destroyed!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_ep > 0 && _hp > 0) {
        _hp += amount;
        _ep--;
        std::cout << "ClapTrap " << name << " repairs itself for " << amount 
                  << " points! Current hit points: " << _hp << std::endl;
    } else {
        std::cout << "ClapTrap " << name << " cannot be repaired!" << std::endl;
    }
}
