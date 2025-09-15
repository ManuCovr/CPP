#include "../inc/Animal.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongCat.hpp"
#include "../inc/Brain.hpp"

int main()
{
    std::cout << "=== Animal array test ===\n";
    const Animal* Zoo[20];

    for (int i = 0; i < 10; i++) Zoo[i] = new Cat();
    for (int i = 10; i < 20; i++) Zoo[i] = new Dog();

    for (int i = 0; i < 20; i++) Zoo[i]->makeSound();

    for (int i = 0; i < 20; i++) delete Zoo[i];

    std::cout << "\n=== Deep copy test ===\n";
    Dog basic;
    {
        Dog tmp;
        tmp = basic;
    }

    std::cout << "\n=== Ideas test ===\n";
    Cat a;
    Dog b;
    a.setCatIdea(0, "mhhhhh lasagna");
    b.setDogIdea(0, "mhhhhh bone");

    {
        Cat c;
        c = a;
        std::cout << "Copy Cat thinks: " << c.getCatIdea(0) << "\n";
    }

    std::cout << "Original Cat thinks: " << a.getCatIdea(0) << "\n";
    std::cout << "Dog thinks: " << b.getDogIdea(0) << "\n";

    return 0;
}
