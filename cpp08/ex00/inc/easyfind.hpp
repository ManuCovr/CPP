#ifndef	EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>
# include <list>

template <typename T>
typename T::iterator	easyfind(T& i, int j)
{
	typename T::iterator	k;

	k = std::find(i.begin(), i.end(), j);
	if (k != i.end())
		return k;
	else
		throw std::out_of_range("Couldn't find that position!");
}

#endif
