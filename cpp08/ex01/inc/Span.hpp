#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <vector>
# include <algorithm>
# include <limits>

class Span
{
private:
	unsigned int		_N;
	std::vector<int>	_vec;
public:
	Span(unsigned int N);
	Span(const Span& ref);
	Span&	operator=(const Span& ref);
	~Span();

	void	addNumber(int nb);
	int		shortestSpan();
	int		longestSpan();
	void	fillSpan();
};

#endif