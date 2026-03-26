#include "../inc/Array.hpp"
#include <cstdlib>
#include <ctime>
#include <string>
#define MAX_VAL 750

int main(int, char**)
{
	std::cout << "=== Test 1: int array with random values ===" << std::endl;
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			delete[] mirror;
			return 1;
		}
	}
	std::cout << "Original array integrity: OK" << std::endl;

	std::cout << "\n=== Test 2: deep copy (operator=) ===" << std::endl;
	{
		Array<int> tmp = numbers;
		tmp[0] = -9999;
		if (tmp[0] == numbers[0])
		{
			std::cerr << "deep copy failed, modifying copy affected original!" << std::endl;
			delete[] mirror;
			return 1;
		}
		std::cout << "Modifying copy did not affect original: OK" << std::endl;
	}

	std::cout << "\n=== Test 3: deep copy (copy constructor) ===" << std::endl;
	{
		Array<int> tmp(numbers);
		tmp[0] = -8888;
		if (tmp[0] == numbers[0])
		{
			std::cerr << "copy constructor failed!" << std::endl;
			delete[] mirror;
			return 1;
		}
		std::cout << "Copy constructor independent from original: OK" << std::endl;
	}

	std::cout << "\n=== Test 4: out of bounds exceptions ===" << std::endl;
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Negative index: " << e.what() << std::endl;
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Index too large: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: string array ===" << std::endl;
	{
		Array<std::string> words(3);
		words[0] = "hello";
		words[1] = "from";
		words[2] = "Array";
		for (int i = 0; i < 3; i++)
			std::cout << words[i] << " ";
		std::cout << std::endl;
		try
		{
			words[3] = "oob";
		}
		catch(const std::exception& e)
		{
			std::cerr << "String array out of bounds: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== Test 6: empty array ===" << std::endl;
	{
		Array<int> empty;
		std::cout << "Empty array size: " << empty.size() << std::endl;
		try
		{
			empty[0] = 1;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Empty array access: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== Test 7: size() ===" << std::endl;
	std::cout << "numbers.size() = " << numbers.size() << " (expected " << MAX_VAL << ")" << std::endl;

	delete[] mirror;
	std::cout << "\nall good" << std::endl;
	return 0;
}