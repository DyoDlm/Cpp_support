#ifndef ITER_HPP
# define ITER_HPP


# include <typeinfo>
# include <stddef.h>
# include <iostream>
# include <string>


template <typename Addr, typename FuncReturn, typename FuncArg>
void	iter(Addr addr, short int len, FuncReturn (*func)(FuncArg))
{
	for (short int i = 0; i < len; i++)
		(void)func(addr[i]);
}

#endif