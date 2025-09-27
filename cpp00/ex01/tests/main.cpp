#include "PhoneBook.hpp"
#include <limits.h>

#define IN 0
#define OUT 1

static void	clean_stream()
{
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
	std::cout << "EOF CATCHED BITCH\n";
}

int call_command(PhoneBook *book)
{
	std::string incoming_cmd;

	std::cout << "Waiting for a new command ('ADD', 'SEARCH', 'EXIT') : " << std::endl;
	std::getline(std::cin, incoming_cmd);
	if (!std::cin.good())
		return (clean_stream(), 0);
	if (incoming_cmd.empty())
	{
		std::cout << "Empty input. Please Retry\n" << std::endl;
		return (1);
	}
	book->setActiveCmd(incoming_cmd);
	return (1);
}

int main()
{
	std::string interaction[2] = {"HELLO", "BYE"};
	PhoneBook 	book("ADD", "SEARCH", "EXIT");

	std::cout << interaction[IN] << std::endl;
	while (book.parse_command())
		if (!call_command(&book))
			break ;
	std::cout << interaction[OUT] << std::endl;
	return (0);
}
