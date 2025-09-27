#pragma once

# include <iostream>
# include <string>
# include <functional>

# define COMPLAINTS 4

enum actions
{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	OTHER
};

class Harl
{
	void		debug(void);
	void		info(void);
	void		warning(void);
	void		error(void);
	std::string levels[COMPLAINTS];
	void 		(Harl::*complaints[COMPLAINTS])(void);
	void		setLevels();
	void		setComplaints();
	public:
		Harl();
		~Harl();
		void	complain(std::string level);
};
