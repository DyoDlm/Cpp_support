#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <string>
# include "Colors.hpp"

class Base
{
	public:
//		Base();
//		Base(const Base &);
		virtual	~Base();

//		Base	&operator=(const Base &);
};

//Base::Base()
//{
//	return ;
//}
//
//Base::Base(const Base &obj)
//{
//	(void)obj;
//}

Base::~Base()
{
	std::cout << std::endl;
}

//Base	&Base::operator=(const Base &obj)
//{
//	if (this != &obj)
		//	pas de membres
//	return *this;
//}

#endif