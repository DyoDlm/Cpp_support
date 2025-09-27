#ifndef B_HPP
# define B_HPP

# include <time.h>
# include "Base.hpp"

class B : public Base
{
	public:
		B() {}
//		B(const B &);
		~B() {}

//		B	&operBtor=(const B &);
};

//B::B() : BBse()
//{
//	return ;
//}
//
//B::B(const B &obj) : BBse(obj)
//{
//	(void)obj;
//}
//
//B::~B() {}
//
//B	&B::operBtor=(const B &B)
//{
//	if (this != &B)
//		*this = B;
//	return *this;
//}

#endif