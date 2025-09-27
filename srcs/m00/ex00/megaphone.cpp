#include <iostream>
#include <string>

/*
void	manage_noise(char **av)
{
	int		i = 0;
	std::string	s = *(av + 1);

	while (s[i])
	{
		if (s[i] <= 'z' && s[i] >= 'a')
			s[i] -= 32;
		i++;
	}
	std::cout << s << "\n" << std::endl;
}*/

void	manage_noise(int ac, char **av)
{
	int			i;
	std::string	s;

	while (ac > 1)
	{
		av++;
		s = *av;
		i = -1;
		while (s[++i])
			s[i] = std::toupper(s[i]);
		std::cout << s;
		ac--;
	}
	std::cout << std::endl;
}


int	main(int ac, char **av)
{
	if (ac < 2)
		std::cout << "* LOUND AND UNBERABLE FEEDBACK NOISE *\n" << std::endl;
	else
		manage_noise(ac, av);
	return (0);
}
