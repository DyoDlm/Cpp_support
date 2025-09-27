#include "easyfind.hpp"

int main()
{
    std::vector<int>    vec;

    for (int i = 0; i < 10; i++)
        vec.push_back(i * 10);
    int find = EasyFind::easyfind(vec, 20);
    return (0);
}