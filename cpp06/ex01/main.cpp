#include "Serializer.hpp"

int	main()
{
	Data		data = {1, 2, 3};
	Data		*ptr = &data;

	uintptr_t	serialized = Serializer::serialize(ptr);
	Data		*deserialized = Serializer::deserialize(serialized);

	std::cout << "Original data\n"
		<< data.a << data.b << data.c << std::endl;

	std::cout << "Ptr on data\n"
		<< ptr->a << ptr->b << ptr->c << std::endl;

	std::cout << "Serialized data\n"
		<< &serialized << std::endl;

	std::cout << "Deserialized data\n"
		<< deserialized << std::endl
		<< "Values are : " << deserialized->a << deserialized->b
		<< deserialized->c << std::endl;

	if (deserialized != ptr)
		std::cout << RED << "VALUES NOT EQUAL";
	else
		std::cout << GREEN << "VALUES EQUAL";

	std::cout << RESET << std::endl;

	return (0);
}
