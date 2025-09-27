#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < NB_IDEAS; i++)
		ideas[i] = "NO IDEA";
	std::cout << std::endl;
}

Brain::Brain(const Brain &obj)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = obj.ideas[i];
	std::cout << std::endl;
}

Brain::~Brain()
{
	std::cout << std::endl;
}

Brain	&Brain::operator=(const Brain &obj)
{
	if (this != &obj)
		for (int i = 0; i < 100; i++)
			ideas[i] = obj.ideas[i];
	return *this;
}
