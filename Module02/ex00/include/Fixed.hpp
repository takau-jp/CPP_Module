/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:45:59 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/19 23:19:11 by stanaka2         ###   ########.fr       */
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
		~Fixed();

		Fixed &operator=(const Fixed &other);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif
