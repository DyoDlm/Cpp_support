#include "FragTrap.hpp"

int	main()
{
	ClapTrap	clap_trap("ClapA");
	FragTrap	jaHeritage("Willy");
	FragTrap	frag_trap_(jaHeritage);
	FragTrap	frag_trap("Bob");

	clap_trap.displayPlayerStatus();
	clap_trap.attack("Willy");
	jaHeritage.takeDamage(clap_trap.getAPdamage());
	jaHeritage.attack("Bob");
	frag_trap.takeDamage(jaHeritage.getAPdamage());
	frag_trap.attack("Willy");
	jaHeritage.takeDamage(frag_trap.getAPdamage());
	jaHeritage.displayPlayerStatus();
	frag_trap.displayPlayerStatus();
	return (0);
}
