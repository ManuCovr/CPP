#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>
# include <vector>
# include <algorithm>
# include <stack>
# include <list>

template <typename T>
class MutantStack: public std::stack<T>
{
private:

public:

	typedef	typename std::stack<T>::container_type::iterator	iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator	reverse_iterator;
	MutantStack(){}
	MutantStack(const MutantStack& ref){*this = ref;}
	MutantStack& operator=(const MutantStack& ref)
	{
		this->c = ref.c;
		return *this;
	}
	~MutantStack(){}
	iterator begin(){return(this->c.begin());}
	iterator end(){return this->c.end();}
	reverse_iterator rbegin(){return this->c.rbegin();}
	reverse_iterator rend(){return this->c.rend();}
};

#endif