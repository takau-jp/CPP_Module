/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 21:27:45 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/05 22:38:18 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed	x;
		Fixed	y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &other);
		~Point();
		Point &operator=(const Point &other);
		const Fixed	&getX() const;
		const Fixed	&getY() const;
};

#endif
