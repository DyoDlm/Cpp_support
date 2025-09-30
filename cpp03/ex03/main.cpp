#include "DiamondTrap.hpp"

static void	basicFunc()
{
	std::cout << WHITE
	<< "\n///////////////////////////////////"
	<< "\n//Creating 4 objects, one of each//.\n//Testing member functions\t //\n"
	<< "//and attributes actualisations//\n" 
	<< "/////////////////////////////////" << RESET << std::endl;

	ClapTrap	clap_trap("CLAP_TRAP");
	ScavTrap	scav_trap("SCAV_TRAP");
	FragTrap	frag_trap("FRAG_TRAP");
	DiamondTrap	diam_trap("DIAM_TRAP");

	clap_trap.displayPlayerStatus();
	scav_trap.displayPlayerStatus();
	frag_trap.displayPlayerStatus();
	diam_trap.displayPlayerStatus();

	clap_trap.attack("MICHEL_CLAP");
	scav_trap.attack("MICHEL_SCAV");
	frag_trap.attack("MICHEL_FRAG");
	diam_trap.attack("MICHEL_DIAM");
	
	clap_trap.takeDamage(1);
	scav_trap.takeDamage(2);
	frag_trap.takeDamage(3);
	diam_trap.takeDamage(4);

	clap_trap.displayPlayerStatus();
	scav_trap.displayPlayerStatus();
	frag_trap.displayPlayerStatus();
	diam_trap.displayPlayerStatus();

	clap_trap.beRepaired(1);
	scav_trap.beRepaired(2);
	frag_trap.beRepaired(3);
	diam_trap.beRepaired(4);

//	diam_trap.ClapTrap::attack("MICHEL_DIAM");

	clap_trap.displayPlayerStatus();
	scav_trap.displayPlayerStatus();
	frag_trap.displayPlayerStatus();
	diam_trap.displayPlayerStatus();

	diam_trap.whoAmI();
}

static void	copyConstructor()
{
	std::cout << WHITE
	<< "\n//////////////////////////"
	<< "\n//Testing copyConstructors//\n"
	<< "///////////////////////////"<< std::endl;

	ScavTrap	scav_trap("SCAV_TRAP");
	FragTrap	frag_trap("FRAG_TRAP");
	DiamondTrap	diam_trap("DIAM_TRAP");

	diam_trap.takeDamage(10);

	DiamondTrap	diam_trap2(diam_trap);

	diam_trap2.takeDamage(10);

	diam_trap.attack("Random");
	diam_trap2.attack("Random");

	diam_trap.displayPlayerStatus();
	diam_trap2.displayPlayerStatus();
}

int	main()
{
	basicFunc();
	copyConstructor();
	return (0);
}
