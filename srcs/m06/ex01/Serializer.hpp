#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include "Colors.hpp"
# include <inttypes.h>
# include "DataStruct.h"

class Serializer
{
	Serializer();
	Serializer(const Serializer &);
	public:
		~Serializer();

		Serializer	&operator=(const Serializer &);
		static uintptr_t	serialize(Data *ptr);

		static Data	*deserialize(uintptr_t raw);
};

#endif