#include "../inc/Cat.hpp"

// Default constructor
Cat::Cat() : Animal() {
    _type = "Cat";
    std::cout << "A wild Cat appeared!" << std::endl;
}

// Copy constructor
Cat::Cat(const Cat& ref) : Animal(ref) { // Call base copy constructor
    *this = ref;
    std::cout << "A wild Cat appeared (copied)!" << std::endl;
}

// Assignment operator
Cat& Cat::operator=(const Cat& ref) {
    if (this != &ref) {
        this->_type = ref._type;  // copy base attributes
    }
    std::cout << "Cat copied with assignment!" << std::endl;
    return *this;
}

// Destructor
Cat::~Cat() {
    std::cout << "Cat ran away!" << std::endl;
}

// makeSound
void Cat::makeSound() const {
    std::cout << "MEOWW" << std::endl;
}
