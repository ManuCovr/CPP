#include "../inc/AAnimal.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongCat.hpp"
#include "../inc/Brain.hpp"

int main()
{
	std::cout << "Animal array test" << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	const AAnimal* Zoo[20];
	for (int i = 0; i < 10; i++)
	{
		Zoo[i] = new Cat();
		std::cout << std::endl;
	}
	for (int i = 10; i < 20; i++)
	{
		Zoo[i] = new Dog();
		std::cout << std::endl;
	}
	for (int i = 0; i < 20; i++)
	{
		Zoo[i]->makeSound();
		std::cout << std::endl;
	}
	for (int i = 0; i < 20; i++)
	{
		delete Zoo[i];
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Deep copy test" << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	Dog basic;
	{
		std::cout << std::endl;
		Dog tmp = basic;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Ideas test" << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	Cat	a;
	Dog	b;
	a.setCatIdea(0, "fish");
	b.setDogIdea(0, "ball");
	{
		Cat c = a;
		std::cout << std::endl;
		std::cout << "The Cat's thinking about: " << c.getCatIdea(0) << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "The Cat's thinking about: " << a.getCatIdea(0) << std::endl;
	std::cout << std::endl;
	std::cout << "The Dog's thinking about: " << b.getDogIdea(0) << std::endl;
	std::cout << std::endl;
	return 0;
}