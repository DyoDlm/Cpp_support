#include "Filter.hpp"

void	Filter::replace()
{
	size_t	pos;
	int		iter = 0;

	while (((pos = content.find(search_to)) || iter++ == 0) && pos < content.length())
	{
		content.erase(pos, search_to.length());
		content.insert(pos, replace_with);
	}
	trimed_content = content;
}

Filter::Filter(std::string par1, std::string par2, std::string par3)
{
	content = par1; search_to = par2; replace_with = par3;
}

Filter::~Filter() {}

std::string	Filter::getTrimmed()
{
	return (trimed_content);
}
