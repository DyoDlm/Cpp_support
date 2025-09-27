#include "Point.hpp"

void	Point::setX(Fixed x)
{
	x.setRawBits(this->x.getRawBits());
}

void	Point::setY(Fixed y)
{
	y.setRawBits(this->y.getRawBits());
}

float	Point::getX() const
{
	return (x.getRawBits());
}

float	Point::getY() const
{
	return (y.getRawBits());
}

void	Point::setPoints(Fixed x, Fixed y)
{
	x = this->x;
	y = this->y;
}

Point::Point() : x(0), y(0) {}

Point::Point(const float f1, const float f2) : x(f1), y(f2) {}

Point::Point(const Point &other)
{
	*this = other;
}

Point	&Point::operator=(const Point &obj)
{
	(void)obj;
	return (*this);
}

Point::~Point() {}

bool	bsp(Point const a, Point const b, Point const c, Point const point);

