/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 21:00:04 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/16 10:39:09 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(0), y(0)
{	
}

Point::Point(const float x, const float y): x(x), y(y)
{	
}

Point::Point(const Point &other): x(other.x), y(other.y)
{
}

Point::~Point()
{	
}

Point &Point::operator=(const Point &other)
{
	if (this != &other)
	{
		this->~Point();
		new (this) Point(other);
	}
	return (*this);
}

const Fixed	&Point::getX() const
{
	return (this->x);
}

const Fixed	&Point::getY() const
{
	return (this->y);
}
