#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iomanip>
# include <iostream>
# include <string>
# include "Colors.hpp"

class ClapTrap
{
	protected:
		std::string	_name;
		int			_HitPoints;
		int			_EnergyPoints;
		int			_AttackDamage;
	public:
		ClapTrap(std::string name = "UNAMED");
		ClapTrap(const ClapTrap &obj);
		~ClapTrap();
		ClapTrap	&operator=(const ClapTrap &obj);
		void		displayPlayerStatus(void);
		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
};

//void	displayMissAction(std::string name, std::string action);

#endif