#include "../inc/easyfind.hpp"

int main()
{
	std::vector<int> vt;
	std::vector<int>::iterator ite;
	std::list<int> vt2;
	std::list<int>::iterator ite2;
	
	for (int i = 0; i < 10; i++)
		vt.push_back(i);
	for (int i = 10; i < 20; i++)
		vt2.push_back(i);
	try
	{
		ite = easyfind(vt, 2);
		std::cout << "found " << *ite << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		ite2 = easyfind(vt2, 1);
		std::cout << "found " << *ite2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
