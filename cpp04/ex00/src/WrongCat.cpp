#include "../inc/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	_type = "WrongCat";
	std::cout << "A wild weird Cat appeared!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& ref) : WrongAnimal(ref) {
	*this = ref;
	std::cout << "A wild weird Cat appeared (copied)!" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &ref) {
	if (this != &ref) {
		this->_type = ref._type; // copy WrongAnimal part
	}
	std::cout << "Weird Cat copied with assignment!" << std::endl;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "Weird Cat ran away!" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "WOOF (the weird cat is probably confused)" << std::endl;
}
