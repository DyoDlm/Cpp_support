#include "Contacts.hpp"

void	format(std::string s)
{
	std::string	to_print = s;

	if (to_print.length() >= 10)
	{
		to_print.replace(9, 1, ".");
		to_print.resize(10);
	}
	std::cout << std::setw(10) << to_print << "|";
}

void	Contacts::show_data(Contacts data, int id)
{
	std::cout << "\t" << id << "|";
	for (int i = 0; i < NICK_NAME; i++)
		format(data._contactInfos[i]);
	std::cout << "\n";
}

void	Contacts::show_contact(Contacts data, int id)
{
	std::cout << "Contact data\n" << "ID : " << id << std::endl;
	std::cout << "NAME : " << data._contactInfos[FIRST_NAME - 1] << std::endl;
	std::cout << "LAST NAME : " << data._contactInfos[LAST_NAME - 1] << std::endl;
	std::cout << "NICKNAME : " << data._contactInfos[NICK_NAME - 1] << std::endl;
	std::cout << "SECRET : " << data._contactInfos[SECRET - 1] << std::endl;
	std::cout << "NUMBER : " << data._contactInfos[NUMBER - 1] << std::endl;
	std::cout << "\n\n\n";
}

void	Contacts::set_data(std::string data[5])
{
	for (int i = 0; i < ATTRIBUTS_SIZE; i++)
		_contactInfos[i] = data[i];
	std::cout << "NEW CONTACT SAVED\n";
}
