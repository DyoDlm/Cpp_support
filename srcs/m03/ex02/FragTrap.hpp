#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include <iomanip>
# include <iostream>
# include "Colors.hpp"
# include "Claptrap.hpp"
# include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
	int	_HighFiveStatus;
	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap &obj);
		~FragTrap();
	
		FragTrap	&operator=(const FragTrap &obj);

		void		highFiveGuys(void);
};

#endif