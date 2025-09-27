#ifndef POINT_HPP
# define POINT_HPP

# include <iomanip>
# include "Fixed.hpp"

const bool in = 1;
const bool out = 0;

class Point
{
	const Fixed	x;
	const Fixed	y;
	public:
		Point();
		Point(const float f1, const float f2);
		Point(const Point &other);
		~Point();
		Point	&operator=(const Point &obj);
		float	getX() const;
		float	getY() const;
		void	setX(Fixed x);
		void	setY(Fixed y);
		void	setPoints(Fixed x, Fixed y);
};

#endif