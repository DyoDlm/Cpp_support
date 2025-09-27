#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include <iomanip>
# include <iostream>
# include "Colors.hpp"
# include "Claptrap.hpp"
# include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	protected:
		int	_status;
	public:
		FragTrap(std::string name = "UNAMED");
		FragTrap(const FragTrap &obj);
		~FragTrap();
	
		FragTrap	&operator=(const FragTrap &obj);

		void		attack(const std::string &target);
		void		highFiveGuys(void);
};

#endif