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
	std::string commands[COMPLAINTS];
	void 		(Harl::*complaints[COMPLAINTS])(void);
	public:
		Harl();
		~Harl();
		int		findComplain(std::string complaint) const;
		void	harlFilter(std::string input);
		void	setLevels();
		void	setComplaints();
};
