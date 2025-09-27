#ifndef FILTER_HPP
# define FILTER_HPP

# include <iostream>
# include <string>
# include <fstream>

class Filter
{
	std::string	content;
	std::string	trimed_content;
	std::string	search_to;
	std::string	replace_with;
	public:
		Filter(std::string par1, std::string par2, std::string par3);
		~Filter();
		void	replace();
		std::string	getTrimmed();

};

#endif