#include "../inc/exec.hpp"

Base*	generate()
{
	int	t;
	srand(time(NULL));
	t = rand() % 3;
	switch (t)
	{
	case 0:
		return new A();
	case 1:
		return new B();
	case 2:
		return new C();
	default:
		break;
	}
	return NULL;
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "this is an A object" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "this is a B object" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "this is a C object" << std::endl;
	else
		std::cout << "Error, no object created" << std::endl;	
}

void	identify(Base& p)
{
	try
	{
		Base a = dynamic_cast<A&>(p);
		std::cout << "this is an A object" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			Base b = dynamic_cast<B&>(p);
			std::cout << "this is an B object" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				Base c = dynamic_cast<C&>(p);
				std::cout << "this is an C object" << std::endl;
			}
			catch(const std::exception& e)
			{
			std::cerr << "Error, " << e.what() << '\n';
			}
		}
	}
}