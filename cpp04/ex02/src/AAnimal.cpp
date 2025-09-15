#include "../inc/AAnimal.hpp"

AAnimal::AAnimal()
{
	_type = "Animal";
	std::cout << "A wild Animal appeared!" << std::endl;
}

AAnimal::AAnimal(const AAnimal& ref)
{
	*this = ref;
	std::cout << "A wild Animal appeared! (copy constructor)" << std::endl;
}

AAnimal	&AAnimal::operator=(const AAnimal &ref)
{
	if (this != &ref)
	{
		this->_type = ref.getType();
		std::cout << "A wild Animal appeared! (operator overload=)" << std::endl;
	}
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "Animal ran away!" << std::endl;
}

std::string	AAnimal::getType() const
{
	return _type;
}

void	AAnimal::makeSound() const
{
	std::cout << " * Random animal sound * " << std::endl;
}