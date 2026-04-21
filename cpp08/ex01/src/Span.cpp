#include "../inc/Span.hpp"

Span::Span(unsigned int N): _N(N){}

Span::Span(const Span& ref)
{
	*this = ref;
}

Span&	Span::operator=(const Span& ref)
{
	if (this != &ref)
	{
		_N = ref._N;
		_vec.assign(ref._vec.begin(), ref._vec.end());
	}
	return *this;
}

void	Span::addNumber(int nb)
{
	if (_vec.size() < _N)
		_vec.push_back(nb);
	else
		throw std::out_of_range("Span is already full!");
}

int		Span::shortestSpan()
{
	if (_vec.size() < 2)
		throw std::out_of_range("Span has less than 2 values, can't give you a span");
	std::vector<int>	tmp = _vec;
	std::sort(tmp.begin(), tmp.end());
	std::vector<int>::iterator	i = tmp.begin();
	int	min = std::numeric_limits<int>::max();
	int	tempmin;
	for (; (i + 1) < tmp.end(); i++)
	{
		tempmin = *(i + 1) - *i;
		if (tempmin < min)
			min = tempmin; 
	}
	return min;
}

int		Span::longestSpan()
{
	if (_vec.size() < 2 || _vec.empty())
		throw std::out_of_range("Span has less than 2 values, can't give you a span");
	std::vector<int>	tmp = _vec;
	std::sort(tmp.begin(), tmp.end());
	return tmp.back() - tmp.front();
}

void	Span::fillSpan()
{
	srand(time(NULL));
	while (_vec.size() < _N)
		_vec.push_back(rand());
}

Span::~Span(){}