/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 23:51:35 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/20 00:08:27 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		static const int fractional_bits = 8;
		int _raw_bits;
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed(const int );
		Fixed(const float );
		Fixed(const Fixed &other);
		~Fixed();

		Fixed &operator=(const Fixed &other);
		float operator<<(const Fixed &other);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif
