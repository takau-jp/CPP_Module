/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 21:00:13 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/05 22:33:33 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	cross_ab_ap;
	Fixed	cross_bc_bp;
	Fixed	cross_ca_cp;

	cross_ab_ap = (b.getX() - a.getX()) * (point.getY() - a.getY()) - (b.getY() - a.getY()) * (point.getX() - a.getX());
	cross_bc_bp = (c.getX() - b.getX()) * (point.getY() - b.getY()) - (c.getY() - b.getY()) * (point.getX() - b.getX());
	cross_ca_cp = (a.getX() - c.getX()) * (point.getY() - c.getY()) - (a.getY() - c.getY()) * (point.getX() - c.getX());
	if ((cross_ab_ap > 0 && cross_bc_bp > 0 && cross_ca_cp > 0) \
		|| (cross_ab_ap < 0 && cross_bc_bp < 0 && cross_ca_cp < 0))
	{
		return (true);
	}
	return (false);
}
