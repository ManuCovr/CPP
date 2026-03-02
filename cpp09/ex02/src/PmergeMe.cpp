#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe():_odd(false){}

PmergeMe::PmergeMe(const PmergeMe& ref)
{
	*this = ref;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& ref)
{
	if (this != &ref)
	{
		_inp = ref._inp;
		_mainVec = ref._mainVec;
		_mainList = ref._mainList;
		_odd = ref._odd;
	}
	return *this;
}

PmergeMe::~PmergeMe(){}

void	PmergeMe::mergeVec()
{
	std::vector<int>::iterator tmp;
	if (_inp.size() % 2 != 0)
	{
		_odd = true;
		_oddNbr = _inp.back();
		_inp.pop_back();
	}
	for (std::vector<int>::iterator it = _inp.begin(); it != _inp.end(); it+= 2)
	{
		tmp = it + 1;
		if (*it < *tmp)
			std::swap(*it, *tmp);
		_bigVec.push_back(*it);
		_smallVec.push_back(*tmp);
	}
	for (std::vector<int>::iterator it = _bigVec.begin(); it != _bigVec.end(); it++)
			std::cout << *it << " ";
	std::cout << std::endl;
	std::vector<int>::iterator itB = _bigVec.begin();
	std::vector<int>::iterator itS = _smallVec.begin();
	std::vector<int>::iterator tempB;
	std::vector<int>::iterator tempS;
	for ( ; itB != _bigVec.end(); itB++)
	{
		tempB = itB + 1;
		tempS = itS + 1;
		if (tempB == _bigVec.end())
			break;
		if (*itB < *tempB)
		{
			std::swap(*itB, *tempB);
			std::swap(*itS, *tempS);
			itB = _bigVec.begin();
			itS = _smallVec.begin();
		}
		else
		{
			itB++;
			itS++;
		}
	}
}

void	PmergeMe::insertVec()
{
	const int	jacob[34] = { 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923,
	21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405,
	11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883,
	1431655765 };
	
}

void	PmergeMe::checkInp(const std::string& inp)
{
	long int	res;
	std::vector<int>::iterator	it = _inp.begin();
	std::vector<int>::iterator ite = _inp.end();
	for (int i = 0; inp[i]; i++)
	{
		if (!isdigit(inp[i]))
			throw std::invalid_argument("Error: Is not a digit");
	}
	res = atol(inp.c_str());
	if (res > INT_MAX || res < 0)
		throw std::invalid_argument("Error: Number invalid");
	if (std::find(it, ite, res) != ite)
		throw std::invalid_argument("Error: Repeated number");
	_inp.push_back(res);
}

void	PmergeMe::startAlg()
{
	std::vector<int>::iterator	inp_it = _inp.begin();
	std::cout << "Before: ";
	while (inp_it != _inp.end())
		std::cout << *inp_it++ << " ";
	std::cout << std::endl;
	mergeVec();
}