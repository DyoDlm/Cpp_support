#include "Colors.hpp"
#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp(const Point &a, const Point &b, const Point &c, const Point &point);

int	main(int ac, char **av)
{
	if (ac != 9)
	{
		std::cout << "Bad args. Try : ./exec [ax] [ay] [bx] [by] [cx] [cy] [px] [py]" << std::endl;
		return (1);
	}

	Point			a(atof(av[1]) / 256, atof(av[2]) / 256);
	Point			b(atof(av[3]) / 256, atof(av[4]) / 256);
	Point			c(atof(av[5]) / 256, atof(av[6]) / 256);
	Point			p(atof(av[7]) / 256, atof(av[8]) / 256);

	std::cout << "A (x, y) are : " << a.getX() << " and : " << a.getY() << std::endl;
	std::cout << "B (x, y) are : " << b.getX() << " and : " << b.getY() << std::endl;
	std::cout << "C (x, y) are : " << c.getX() << " and : " << c.getY() << std::endl;
	std::cout << "P (x, y) are : " << p.getX() << " and : " << p.getY() << std::endl;

	bool	isIn = bsp(a, b, c, p);
	std::cout << YELLOW << "\n\nThe point is in the triangle :\n";
	if (isIn)
		std::cout << GREEN << "\n\t\t\t\tTRUE\n\n" << RESET;
	else
		std::cout << RED << "\n\t\t\t\tFALSE\n\n" << RESET;
	return (0);
}