#include "Array.hpp"

template <typename T>
const char	*Array<T>::OutOfBoundsException::what() const throw()
{
	return "You're out of bounds buddy\n";
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	if (!n)
		_elements = new T[0];
	else
		_elements = new T[n];
	_size = static_cast<int>(n);
	std::cout << "\nNew array created in the constructor\n" << std::endl;
}

template <typename T>
Array<T>::Array(const Array &arr)
{
	_elements = arr._elements;
	_size = arr.size();
//	_elements = new arr._elements;
	std::cout << "\nNew array created in the copy constructor\n" << std::endl;
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "\nIn destructor" << std::endl;
	delete []_elements;
}

template <typename T>
int	Array<T>::size() const
{
	return _size;
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array &arr)
{
	if (this != &arr)
	{
		this->_size = arr._size;
	    _elements = new T[this->_size];
		for (int i = 0; i < this->_size; i++)
			this->_elements[i] = arr._elements[i];
	}
	return *this;
}

template <typename T>
T	&Array<T>::operator[](int pos)
{
	if (pos < 0 || pos >= _size)
		throw std::exception();
	return (_elements[pos]);
}

template <typename T>
const T	&Array<T>::operator[](int pos) const
{
	if (pos < 0 || pos >= _size)
		throw std::exception();
	return (_elements[pos]);
}

template <typename T>
std::ostream	&operator<<(std::ostream &stream, const Array<T> &a)
{
	for (int i = 0; i < a.size(); i++)
	{
		const int element = a[i];
		stream << element << "\n";
	}
	stream << '\n';
    return stream;
}
