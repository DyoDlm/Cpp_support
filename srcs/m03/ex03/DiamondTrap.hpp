#ifndef DIAMOND_TRAP
# define DIAMOND_TRAP

# include <iomanip>
# include <iostream>
# include <string>
# include "Claptrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include "Colors.hpp"

class DiamondTrap : virtual public FragTrap, virtual public ScavTrap
{
	std::string	_name;
	public:
		DiamondTrap(std::string name = "UNAMED");
		DiamondTrap(const DiamondTrap &obj);
		~DiamondTrap();

		DiamondTrap	&operator=(const DiamondTrap &obj);
		
//		using	FragTrap::_HitPoints;
//		using	ScavTrap::_EnergyPoints;
//		using	FragTrap::_AttackDamage;
//		using	ClapTrap::beRepaired;
//		using	ClapTrap::takeDamage;
		using	ScavTrap::attack;
		void	whoAmI();
};

#endif