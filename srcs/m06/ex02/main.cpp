#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

enum 
{
	Aclass,
	Bclass,
	Cclass
};

Base	*generate()
{
	time_t	randomValue = time(0);
	Base	*newInstance;

	if (randomValue % 4 == 0)
		newInstance = new A();
	else if (randomValue % 3 == 0)
		newInstance = new B();
	else
		newInstance = new C();

	std::cout << "new instance created\n"
		<< "(It was "
		<< (randomValue % 4 ? (randomValue % 3 ? "C)" : "B)") : "A)")
		<< std::endl;

	return (newInstance);
}

void	identify(Base *p)
{
	Base		*activeClasses[] = {
		dynamic_cast<A*>(p), dynamic_cast<B*>(p), dynamic_cast<C*>(p)
	};
	const int	nbActiveClasses = 3;
	int			wich = -1;

	while (++wich < nbActiveClasses)
		if (activeClasses[wich] == p)
			break ;

	std::cout << "First guess\n";

	std::cout << "Identifying Base class...\nBase is : "
		<< (wich != Aclass ? (wich != Bclass ? (wich != Cclass ? "Unknown" : "C") : "B") : "A")
		<< std::endl;
}

void	identify(Base &p)
{
	int	wich = -1;

	try
	{
		wich++;
		(void)dynamic_cast<A&>(p);
	}
	catch (...)
	{
		try
		{
			wich++;
			(void)dynamic_cast<B&>(p);
		}
		catch (...)
		{
			try
			{
				wich++;
				(void)dynamic_cast<C&>(p);
			}
			catch (...)
			{
				wich++;
			}
		}
	}
	std::cout << "Second guess\n";

	std::cout << "Identifying Base class...\nBase is : "
		<< (wich != Aclass ? (wich != Bclass ? (wich != Cclass ? "Unknown" : "C") : "B") : "A")
		<< std::endl;

}

int	main()
{
	Base	*random = generate();

	identify(random);

	identify(*random);

	delete random;

	return (0);
}
