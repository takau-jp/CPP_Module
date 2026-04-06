/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 23:57:23 by stanaka2          #+#    #+#             */
/*   Updated: 2026/03/27 20:40:28 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

// Default Test
int main(void)
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d(  b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}

// // Original Test

// #include "Test.h"

// int main(void)
// {
// 	std::cout << MAGENTA << "===== Original Test =====" << std::endl << DEF_COLOR;
// 	Fixed a;
// 	Fixed const b( 10 );
// 	Fixed const c( 42.42f );
// 	Fixed const d( b );

// 	a = Fixed( 1234.4321f );

// 	std::cout << GREEN << "===== toFloat Test =====" << std::endl << DEF_COLOR;
// 	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
// 	std::cout << "b is " << b.toFloat() << " as float" << std::endl;
// 	std::cout << "c is " << c.toFloat() << " as float" << std::endl;
// 	std::cout << "d is " << d.toFloat() << " as float" << std::endl;

// 	std::cout << GREEN << "===== operator << Test =====" << std::endl << DEF_COLOR;
// 	std::cout << "a is " << a << " as float" << std::endl;
// 	std::cout << "b is " << b << " as float" << std::endl;
// 	std::cout << "c is " << c << " as float" << std::endl;
// 	std::cout << "d is " << d << " as float" << std::endl;

// 	std::cout << MAGENTA << "===== END =====" << std::endl << DEF_COLOR;

// 	return 0;
// }
