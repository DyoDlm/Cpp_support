#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <stdexcept>

template <typename T> class Array {

	private:
		int	_size;
		T	*_elements;
	public:
		Array(unsigned int n = 0);
		Array(const Array &);
		~Array();

		Array	&operator=(const Array &);
		T		&operator[](int);
		const T	&operator[](int) const;

		int		size() const;
		class OutOfBoundsException {
			public:
				const char	*what() const throw();
		};

};

template <typename T>
std::ostream	&operator<<(std::ostream &stream, const Array<T> &a);

#endif