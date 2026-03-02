#include "../inc/exec.hpp"

int main()
{
	Base* p = generate();
	std::cout << "identifying with pointer..." << std::endl;
	identify(*p);
	std::cout << "identifying without pointer..." << std::endl;
	identify(p);
	delete p;
}