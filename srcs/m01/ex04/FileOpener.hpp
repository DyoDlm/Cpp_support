#ifndef FILEOPENER_HPP
# define FILEOPENER_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <ostream>
# include <sstream>

class FileOpener
{
	std::ifstream		*fileToRead;
	std::stringstream	stream_catch;
	std::string			content;
	public:
		FileOpener(std::ifstream &file, const char *fileName);
		~FileOpener();
		void		setContent();
		std::string	getContent();
};

#endif