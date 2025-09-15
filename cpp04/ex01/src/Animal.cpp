#include "../inc/Animal.hpp"

Animal::Animal()
{
	_type = "Animal";
	std::cout << "A wild Animal appeared!" << std::endl;
}

Animal::Animal(const Animal& ref)
{
	*this = ref;
	std::cout << "A wild Animal appeared! (copy constructor)" << std::endl;
}

Animal	&Animal::operator=(const Animal &ref)
{
	if (this != &ref)
	{
		this->_type = ref.getType();
		std::cout << "A wild Animal appeared! (operator overload=)" << std::endl;
	}
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal ran away!" << std::endl;
}

std::string	Animal::getType() const
{
	return _type;
}

void	Animal::makeSound() const
{
	std::cout << " * Random animal sound * " << std::endl;
}