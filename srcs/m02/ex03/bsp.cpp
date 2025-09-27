#include "Point.hpp"
#include "Colors.hpp"
#define I 0
#define J 1

static float	getNorm(float a, float b)
{
	return (sqrt(a * a + b * b));
}

static float	*unitVector(const Point &a, const Point &b)
{
	float	*vector = new float[2];

	vector[I] = b.getX() - a.getX();
	vector[J] = b.getY() - a.getY();
	return (vector);
}

static float	*cross(float ab[2], float ac[2])
{
	float	*crossVector = new float[2];
	
	crossVector[0] = 0;
	crossVector[1] = ab[0] * ac[1] - ab[1] * ac[0];
	return (crossVector);
}

static float	getArea(const Point &a, const Point &b, const Point &c)
{
	float	*abVector = unitVector(a, b);
	float	*acVector = unitVector(a, c);
	float	*crossVector = cross(abVector, acVector);
	float	res = getNorm(crossVector[0], crossVector[1]) / 2;
	
	delete []abVector;
	delete []acVector;
	delete []crossVector;
	return (res);
}

bool	bsp(Point const &a, Point const &b, Point const &c, Point const &point)
{
	float	aireABP = getArea(a, b, point);
	float	aireACP = getArea(a, c, point);
	float	aireBCP = getArea(b, c, point);
	float	aireABC = getArea(a, b, c);

	std::cout << CYAN << "\nABC AREA IS : " << RESET << aireABC << std::endl;
	std::cout << BLUE << "ABP + ACP + BCP AREA : " << RESET << aireABP + aireACP + aireBCP << std::endl;
	if (aireABC < aireABP + aireACP + aireBCP)
		return (out);
	return (in);
}
