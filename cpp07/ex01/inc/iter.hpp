#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>
# include <string>

template <typename T> void info(T i)
{
	std::cout << i << " has a size of data of " << sizeof(i) << std::endl;
}

template <typename I> void iter(I arr[], int size, void (*Funct)(const I& x))
{
	for (int i = 0; i < size; i++)
		Funct(arr[i]);
}

#endif	