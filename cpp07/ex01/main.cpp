#include "iter.hpp"
#include "string.h"

#define ARR_SIZE 3

class prout
{
	public:
		prout() { std::cout << "Waw a class !\n"; }
		~prout() {}
};

void	printstr(std::string obj)
{
	std::cout << obj << std::endl;
}

int	print(int i)
{
	static int	iter = 0;

	iter++;
	i += iter;
	std::cout << i << std::endl;
	return (0);
}

int	yow(prout p)
{
	if (typeid(p) == typeid(prout()))
		std::cout << "'Printing' prout class\n";
	else
		std::cout << "Printing some type of class\n";
	return (0);
}

int	main()
{
	{
		int	intArr[ARR_SIZE];

		memset(&intArr, 0, sizeof(intArr));
		iter(intArr, ARR_SIZE, print);
	}
	{
		prout	p[ARR_SIZE] = {prout(), prout(), prout()};
		iter(p, ARR_SIZE, yow);
	}
	{
		std::string	strArr[ARR_SIZE] = {
			"1", "123", "123456"
		};

		iter(strArr, ARR_SIZE, printstr);
	}
	return (0);
}
