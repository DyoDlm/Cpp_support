#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include <iomanip>
# include <iostream>
# include "Colors.hpp"
# include "Claptrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	protected:
		int	_gateMod;
	public:
		ScavTrap(std::string name = "UNAMED");
		ScavTrap(const ScavTrap &);
		~ScavTrap();
		ScavTrap	&operator=(const ScavTrap &obj);
		void		guardGate();
		void		attack(const std::string &target);
};

#endif
