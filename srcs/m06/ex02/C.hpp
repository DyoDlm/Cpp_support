#ifndef C_HPP
# define C_HPP

# include <time.h>
# include "Base.hpp"

class C : public Base
{
	public:
		C() {}
//		C(const C &);
		~C() {}

//		C	&operCtor=(const C &);
};

//C::C() : BCse()
//{
//	return ;
//}
//
//C::C(const C &obj) : BCse(obj)
//{
//	(void)obj;
//}
//
//C::~C() {}
//
//C	&C::operCtor=(const C &C)
//{
//	if (this != &C)
//		*this = C;
//	return *this;
//}

#endif