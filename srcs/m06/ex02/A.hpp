#ifndef A_HPP
# define A_HPP

# include <time.h>
# include "Base.hpp"

class A : public Base
{
	public:
		A() {}
//		A(const A &);
		~A() {}

//		A	&operator=(const A &);
};

//A::A() : Base()
//{
//	return ;
//}
//
//A::A(const A &obj) : Base(obj)
//{
//	(void)obj;
//}
//
//A::~A() {}
//
//A	&A::operator=(const A &a)
//{
//	if (this != &a)
//		*this = a;
//	return *this;
//}

#endif