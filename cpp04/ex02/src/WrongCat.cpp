#include "../inc/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    _type = "WrongCat";
    std::cout << "A wild weird Cat appeared!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& ref) : WrongAnimal(ref)
{
    _type = ref._type;
    std::cout << "A wild weird Cat appeared! (copy constructor)"  << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &ref)
{
    if (this != &ref)
    {
        WrongAnimal::operator=(ref); // copy base class members
        _type = ref._type;
        std::cout << "A wild weird Cat appeared! (operator overload=)"  << std::endl;
    }
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "Weird Cat ran away!" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "WOOF (the weird cat is probably confused)" << std::endl;
}
