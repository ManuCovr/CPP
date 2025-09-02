#include "../inc/Zombie.hpp"

int main()
{
    randomChump("Walker");
    Zombie* p = newZombie("Muncher");
    p->announce();
    delete p;
    return 0;
}
