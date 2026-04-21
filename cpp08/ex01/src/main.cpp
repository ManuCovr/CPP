#include "../inc/Span.hpp"

int	main()
{
	try
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "---------------" << std::endl;
	try
	{
		Span oneSpan = Span(1);
		oneSpan.addNumber(2);
		std::cout << oneSpan.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "---------------" << std::endl;
	try
	{
		Span oneSpan2(1);
		oneSpan2.addNumber(1);
		oneSpan2.addNumber(2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "---------------" << std::endl;
	try
	{
		Span fill(10000);
		fill.fillSpan();
		std::cout << fill.shortestSpan() << std::endl;
		std::cout << fill.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}