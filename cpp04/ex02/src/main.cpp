#include "../inc/AAnimal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Brain.hpp"

int main() {
    std::cout << "=== POLYMORPHISM & DEEP COPY TEST ===\n\n";

    // ---- POLYMORPHISM TEST ----
    std::cout << "--- Animal array test ---\n";
    const AAnimal* Zoo[6];  // smaller array for brevity
    for (int i = 0; i < 3; ++i)
        Zoo[i] = new Cat();
    for (int i = 3; i < 6; ++i)
        Zoo[i] = new Dog();

    for (int i = 0; i < 6; ++i) {
        std::cout << Zoo[i]->getType() << " says: ";
        Zoo[i]->makeSound();
    }

    for (int i = 0; i < 6; ++i)
        delete Zoo[i];

    // ---- DEEP COPY TEST ----
    std::cout << "\n--- Deep copy test ---\n";
    Dog basicDog;
    basicDog.setDogIdea(0, "I want a bone");

    Dog copyDog = basicDog;  // copy constructor
    copyDog.setDogIdea(0, "I want TWO bones"); 

    std::cout << "Original Dog thinks: " << basicDog.getDogIdea(0) << "\n";
    std::cout << "Copied Dog thinks: " << copyDog.getDogIdea(0) << "\n";

    Cat basicCat;
    basicCat.setCatIdea(0, "Nap time");

    Cat copyCat;
    copyCat = basicCat;  // assignment operator
    copyCat.setCatIdea(0, "Tuna time");

    std::cout << "Original Cat thinks: " << basicCat.getCatIdea(0) << "\n";
    std::cout << "Copied Cat thinks: " << copyCat.getCatIdea(0) << "\n";

    return 0;
}
