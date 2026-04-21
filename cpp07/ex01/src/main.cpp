#include "../inc/iter.hpp"

int main()
{
	int	arr[] = { 5, 4, 3, 2, 1 };
	int size = 5;
	iter(arr, size, info);
	std::cout << std::endl;
	std::cout << "another test" << std::endl;
	std::string str[] ={"five", "four", "three", "two", "one"};
	int s = 5;
	iter(str, s, info);
	return 0;
}