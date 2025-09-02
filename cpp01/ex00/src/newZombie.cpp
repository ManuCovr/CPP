#include "../inc/Zombie.hpp"

Zombie* newZombie(std::string name) // heap
{
    return new Zombie(name);
}
