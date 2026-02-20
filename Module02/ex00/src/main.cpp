/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:48:50 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/19 23:42:45 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

int main( void ) {
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	// Original TEST
	// std::cout << "=====TEST=====" << std::endl;
	// Fixed d;
	// std::cout << d.getRawBits() << std::endl;
	// d.setRawBits(42);
	// Fixed e(d);
	// Fixed f;
	// f = e;
	// std::cout << d.getRawBits() << std::endl;
	// std::cout << e.getRawBits() << std::endl;
	// std::cout << f.getRawBits() << std::endl;
	return 0;
}
