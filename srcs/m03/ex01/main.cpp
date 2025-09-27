#include "ScavTrap.hpp"

int	main()
{
	ClapTrap	clap_trap("ClapA");
	ScavTrap	jaHeritage("ScavA");
	ScavTrap	scav_clap(jaHeritage);

	clap_trap.attack("ScavA");
	scav_clap.takeDamage(clap_trap.getAPdamage());
	scav_clap.attack("ClapA");
	clap_trap.takeDamage(scav_clap.getAPdamage());
	clap_trap.beRepaired(10);
	scav_clap.beRepaired(10);
	clap_trap.displayPlayerStatus();
	scav_clap.displayPlayerStatus();
	return (0);
}
