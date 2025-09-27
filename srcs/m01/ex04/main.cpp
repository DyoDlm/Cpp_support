#include "Filter.hpp"
#include "FileOpener.hpp"

int	main(int ac, char **av)
{
	if (ac < 4)
	{
		std::cout << "Bad arguments. Try : ./exec [file] [s1] [s2]\n";
		return (1);
	}
	std::ifstream	file;
	std::string		fileName = av[1];
	std::string		newFileName = av[1];
	FileOpener		opener(file, av[1]);

	newFileName.append(".replace");
	std::cout << "File Content : \n" << opener.getContent() << std::endl;
	if (opener.getContent() == "No content in file")
		return (1);
	std::cout << "Filtering File" << std::endl;
	Filter	obj(opener.getContent(), av[2], av[3]);
	obj.replace();
	std::ofstream	newFile(newFileName.c_str());
	newFile << obj.getTrimmed();
	return (0);
}
