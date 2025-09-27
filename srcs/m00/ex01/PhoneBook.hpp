#pragma once

#include "Contacts.hpp"

# define CONTACTS 8
# define COMMANDS 4
# define DATA_STR 5

enum cmds
{
	ADD,
	SEARCH,
	EXIT,
	OTHER,
	DEFAULT
};

class PhoneBook
{
	int			_olderUser;
	int			_activeCmd;
	Contacts	_id[CONTACTS];
	std::string	_commands[COMMANDS];
	public:
		PhoneBook(std::string c1, std::string c2, std::string c3);
		void		show_commands();
		int			getActiveCmd() const;
    	void		setActiveCmd(std::string cmd);
		void		show_contact_list();
		int			parse_command();
		void		pb_add();
		void		pb_search();
};

