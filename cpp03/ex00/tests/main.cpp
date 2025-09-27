#include "Claptrap.hpp"

int	main()
{
	ClapTrap	ja("Joueur 1");
	ClapTrap	jb("Joueur 2");
	ClapTrap	jc("Joueur 3");
	ClapTrap	jd("Joueur 4");

	ja.displayPlayerStatus();
	ja.attack("BOBOBBY");
	ja.beRepaired(5);
	ja.takeDamage(2);
	ja.displayPlayerStatus();
	return (0);
}