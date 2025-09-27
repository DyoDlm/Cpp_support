#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>
# include <vector>
# include <list>
# include <map>

template <typename T>
class EasyFind
{
    public:
        EasyFind();
        EasyFind(const EasyFind &);
        ~EasyFind();

        EasyFind    &operator=(const EasyFind &);

        int   easyfind(T in, int find);
};

#endif