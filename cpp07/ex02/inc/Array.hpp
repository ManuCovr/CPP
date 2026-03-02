#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <stdexcept>

template <typename T> class Array
{
	private:
		T	*_arr;
		unsigned int	_sz;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& ref);
		Array&	operator=(const Array& ref);
		~Array();

		unsigned int	size();
		void			getPos(std::ostream& out) const;
		T&	operator[](int n);
};

template <typename T>
std::ostream&	operator<<(std::ostream& out, const Array<T>& ref);

template <typename T>
Array<T>::Array()
{
	_arr = new T[0];
	_sz = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	T*	init = new T();
	_sz = n;
	_arr = new T[_sz];
	for (int i = 0; i < n; i++)
		_arr[i] = *init;
	delete init;
}

template <typename T>
Array<T>::Array(const Array& ref)
{
	_arr = NULL;
	*this = ref;
}

template <typename T>
Array<T>&		Array<T>::operator=(const Array<T>& ref)
{
	if (this != &ref)
	{
		delete[] this->_arr;
		this->_arr = new T[ref._sz];
		for (int i = 0; i < ref._sz; i++)
			this->_arr[i] = ref._arr[i];
		this->_sz = ref._sz;
	}
	return *this;
}

template <typename T>
void	Array<T>::getPos(std::ostream& out) const
{
	for (int i = 0; i < this->_sz; i++)
		out << this->_arr[i] << std::endl;
}

template <typename T>
unsigned int	Array<T>::size()
{
	return _sz;
}

template <typename T>
T&	Array<T>::operator[](int n)
{
	if (n < 0 || n >= this->_sz)
		throw std::out_of_range("Out of bounds");
	return this->_arr[n];
}

template <typename T>
std::ostream&	operator<<(std::ostream& out, const Array<T>& ref)
{
	ref.getPos(out);
	return out;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _arr;
}

#endif
