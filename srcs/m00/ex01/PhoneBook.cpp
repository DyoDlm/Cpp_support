#include "PhoneBook.hpp"

PhoneBook::PhoneBook(std::string c1, std::string c2, std::string c3)
{
	_commands[0] = c1;
	_commands[1] = c2;
	_commands[2] = c3;
	_commands[3] = "BACK";
	_activeCmd = -1;
	_olderUser = 0;
}

void	PhoneBook::show_commands()
{
	std::cout << "TRY 'ADD' TO SET A NEW CONTACT\n" << std::endl;
	std::cout << "TRY 'SEARCH TO FIND A CONTACT\n" << std::endl;
	std::cout << "TRY 'EXIT' OR 'q' TO QUIT THE PROGRAM\n" << std::endl;
}

void	PhoneBook::setActiveCmd(std::string cmd)
{
	int	i = 0;

	while (i < COMMANDS && cmd != _commands[i])
		i++;
	_activeCmd = i;
	if (i == COMMANDS && cmd != "default")
		show_commands();
}

int	PhoneBook::getActiveCmd(void) const
{
	return (_activeCmd);
}

void	PhoneBook::show_contact_list()
{
	for (int i = 0; i < CONTACTS; i++)
	{
		_id[i].show_data(_id[i], i);
		std::cout << '\n' << std::endl;
	}
}

void	PhoneBook::pb_add()
{
	std::string	data[5];

	std::cout << "Add a first name :\n" << std::endl;
	std::getline(std::cin, data[0]);
	std::cout << "Add a last name :\n" << std::endl;
	std::getline(std::cin, data[1]);
	std::cout << "Add a nickname :\n" << std::endl;
	std::getline(std::cin, data[2]);
	std::cout << "Add a secret :\n" << std::endl;
	std::getline(std::cin, data[3]);
	std::cout << "Add a number :\n" << std::endl;
	std::getline(std::cin, data[4]);
	for (int i = 0; i < ATTRIBUTS_SIZE; i++)
	{
		if (data[i].empty())
		{
			std::cout << "One of the fields is empty\nContact not saved" << std::endl;
			return ;
		}
	}
	_id[_olderUser++].set_data(data);
	_olderUser %= 8;
}

void	PhoneBook::pb_search()
{
	std::string	contact_id;
	std::string	valid_ids = "01234567";

	show_contact_list();
	std::cout << "Enter contact ID\n" << std::endl;
	while (true)
	{
		if (!std::getline(std::cin, contact_id))
			return ;
		for (int i = 0; i < CONTACTS; i++)
			if (contact_id[0] == valid_ids[i] && contact_id.length() == 1)
				return (_id[i].show_contact(_id[i], contact_id[0] - '0'));
		std::cout << "Id incorrect\nPlease retype ID\n" << std::endl;
	}
}

int	PhoneBook::parse_command()
{
	switch (_activeCmd)
	{
		case ADD:
			pb_add();
			setActiveCmd("default");
			break ;
		case SEARCH:
			pb_search();
			setActiveCmd("default");
			break ;
		case EXIT:
			return (0);
		default:
			break ;
	}
	return (1);
}

