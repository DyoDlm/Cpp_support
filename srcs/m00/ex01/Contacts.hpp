#pragma once

#include <iomanip>
#include <string>
#include <iostream>

#define ATTRIBUTS_SIZE 5

enum data
{
	ID,
	FIRST_NAME,
	LAST_NAME,
	NICK_NAME,
	SECRET,
	NUMBER
};

class Contacts
{
	std::string	_contactInfos[5];
	public:
		Contacts() {
			for (int i = 0; i < ATTRIBUTS_SIZE; i++)
				_contactInfos[i] = "NONE";
		}
		void	show_contact(Contacts data, int id);
		void	show_data(Contacts data, int id);
		void	set_data(std::string data[5]);
};
