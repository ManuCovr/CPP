#include "../inc/Dog.hpp"

Dog::Dog() : Animal() {
	_type = "Dog";
	std::cout << "A wild Dog appeared!" << std::endl;
}

Dog::Dog(const Dog& ref) : Animal(ref) { // base copy constructor
	*this = ref;
	std::cout << "A wild Dog appeared (copied)!" << std::endl;
}

Dog &Dog::operator=(const Dog &ref) {
	if (this != &ref) {
		this->_type = ref._type; // copy Animal part
		// copy Dog-specific fields here if any
	}
	std::cout << "Dog copied with assignment!" << std::endl;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog ran away!" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "BARK BARK WOOF" << std::endl;
}
