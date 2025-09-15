#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"
class FragTrap : public ClapTrap {
private:
    static const unsigned int default_hp = 100;
    static const unsigned int default_ep = 100;
    static const unsigned int default_ad = 30;
public:
    FragTrap();
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &other);
    FragTrap &operator=(const FragTrap &other);
    ~FragTrap();
    void attack(const std::string& target);
    void highFivesGuys();
};

#endif