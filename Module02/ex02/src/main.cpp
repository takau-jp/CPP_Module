/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 20:41:56 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/29 22:05:11 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <exception>
#include <cfloat>
#include <iostream>

// Default Test
int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.425f ) * Fixed( 1 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b - Fixed( 5 ) << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}


// // Original Test

// #include "Test.h"
// #include <iomanip>

// void testConstructor();
// void testComparisonOperators();
// void testArithmeticOperators();
// void testIncrementDecrementOperators();
// void testCompoundAssignmentOperators();
// void testMinMax();
// void testRounding();

// int main(void)
// {
// 	std::cout << MAGENTA << "===== Original Test =====" << std::endl << DEF_COLOR;
// 	std::cout << std::fixed << std::setprecision(9);
// 	testConstructor();
// 	testComparisonOperators();
// 	testArithmeticOperators();
// 	testIncrementDecrementOperators();
// 	testCompoundAssignmentOperators();
// 	testMinMax();
// 	testRounding();
// 	std::cout << MAGENTA << "===== END =====" << std::endl << DEF_COLOR;
// 	return 0;
// }

// void testConstructor()
// {
// 		{
// 			std::cout << GREEN << "===== default constructor =====" << std::endl << DEF_COLOR;
// 			Fixed defaultFixed;
// 			std::cout << "getRowBits(): " << defaultFixed.getRawBits() << std::endl;
// 		}
// 		{
// 			std::cout << GREEN << "===== copy constructor =====" << std::endl << DEF_COLOR;
// 			Fixed original;
// 			original.setRawBits(2147483647);
// 			std::cout << BLUE << "===== 2147483647 =====" << std::endl << DEF_COLOR;
// 			Fixed copy(original);
// 			std::cout << "getRowBits(): " << original.getRawBits() << std::endl;
// 		}
// 		{
// 			std::cout << GREEN << "===== int constructor =====" << std::endl << DEF_COLOR;
// 			std::cout << BLUE << "===== 42 =====" << std::endl << DEF_COLOR;
// 			Fixed pos42(42);
// 			std::cout << "toInt(): " << pos42.toInt() << std::endl;
// 			std::cout << BLUE << "===== -42 =====" << std::endl << DEF_COLOR;
// 			Fixed neg42(-42);
// 			std::cout << "toInt(): " << neg42.toInt() << std::endl;
// 			std::cout << BLUE << "===== 0 =====" << std::endl << DEF_COLOR;
// 			Fixed zero(0);
// 			std::cout << "toInt(): " << zero.toInt() << std::endl;
// 			std::cout << BLUE << "===== 8388607 =====" << std::endl << DEF_COLOR;
// 			Fixed maxInt(8388607);
// 			std::cout << "toInt(): " << maxInt.toInt() << std::endl;
// 			std::cout << BLUE << "===== -8388608 =====" << std::endl << DEF_COLOR;
// 			Fixed minInt(-8388608);
// 			std::cout << "toInt(): " << minInt.toInt() << std::endl;
// 			try
// 			{
// 				std::cout << BLUE << "===== 8388608 =====" << std::endl << DEF_COLOR;
// 				Fixed overMax(8388608);
// 				std::cout << "toInt(): " << overMax.toInt() << std::endl;
// 			}
// 			catch(const std::exception& err)
// 			{
// 				std::cerr << "Error: " << err.what() << std::endl;
// 			}
// 			try
// 			{
// 				std::cout << BLUE << "===== -8388609 =====" << std::endl << DEF_COLOR;
// 				Fixed underMin(-8388609);
// 				std::cout << "toInt(): " << underMin.toInt() << std::endl;
// 			}
// 			catch(const std::exception& err)
// 			{
// 				std::cerr << "Error: " << err.what() << std::endl;
// 			}
// 		}
// 		{
// 			std::cout << GREEN << "===== float constructor =====" << std::endl << DEF_COLOR;

// 			std::cout << BLUE << "===== 42.42f =====" << std::endl << DEF_COLOR;
// 			Fixed pos42f(42.42f);
// 			std::cout << "toFloat(): " << pos42f.toFloat() << std::endl;
// 			std::cout << BLUE << "===== -42.42f =====" << std::endl << DEF_COLOR;
// 			Fixed neg42f(-42.42f);
// 			std::cout << "toFloat(): " << neg42f.toFloat() << std::endl;
// 			std::cout << BLUE << "===== 0.0f =====" << std::endl << DEF_COLOR;
// 			Fixed zeroF(0.0f);
// 			std::cout << "toFloat(): " << zeroF.toFloat() << std::endl;
// 			std::cout << BLUE << "===== 8388607.42f =====" << std::endl << DEF_COLOR;
// 			Fixed nearMaxF(8388607.42f);
// 			std::cout << "toFloat(): " << nearMaxF.toFloat() << std::endl;
// 			std::cout << BLUE << "===== -8388608.0f =====" << std::endl << DEF_COLOR;
// 			Fixed minF(-8388608.0f);
// 			std::cout << "toFloat(): " << minF.toFloat() << std::endl;
// 			try
// 			{
// 				std::cout << BLUE << "===== 8388607.999f =====" << std::endl << DEF_COLOR;
// 				Fixed overMaxF(8388607.999f);
// 				std::cout << "toFloat(): " << overMaxF.toFloat() << std::endl;
// 			}
// 			catch(const std::exception& err)
// 			{
// 				std::cerr << "Error: " << err.what() << std::endl;
// 			}
// 			try
// 			{
// 				std::cout << BLUE << "===== -8388608.51f =====" << std::endl << DEF_COLOR;
// 				Fixed underMinF(-8388608.51f);
// 				std::cout << "toFloat(): " << underMinF.toFloat() << std::endl;
// 			}
// 			catch(const std::exception& err)
// 			{
// 				std::cerr << "Error: " << err.what() << std::endl;
// 			}

// 			std::cout << BLUE << "===== 0.42f =====" << std::endl << DEF_COLOR;
// 			Fixed fracPos(0.42f);
// 			std::cout << "toFloat(): " << fracPos.toFloat() << std::endl;
// 			std::cout << BLUE << "===== -0.42f =====" << std::endl << DEF_COLOR;
// 			Fixed fracNeg(-0.42f);
// 			std::cout << "toFloat(): " << fracNeg.toFloat() << std::endl;
// 			std::cout << BLUE << "===== 0.42f =====" << std::endl << DEF_COLOR;
// 			Fixed fracPos2(0.42f);
// 			std::cout << "toFloat(): " << fracPos2.toFloat() << std::endl;
// 			std::cout << BLUE << "===== (+-)1.0f / 2 =====" << std::endl << DEF_COLOR;
// 			Fixed half(1.0f / 2);
// 			std::cout << "toFloat(): " << half.toFloat() << std::endl;
// 			Fixed negHalf(-1.0f / 2);
// 			std::cout << "toFloat(): " << negHalf.toFloat() << std::endl;
// 			std::cout << BLUE << "===== (+-)1.0f / 4 =====" << std::endl << DEF_COLOR;
// 			Fixed quarter(1.0f / 4);
// 			std::cout << "toFloat(): " << quarter.toFloat() << std::endl;
// 			Fixed negQuarter(-1.0f / 4);
// 			std::cout << "toFloat(): " << negQuarter.toFloat() << std::endl;
// 			std::cout << BLUE << "===== (+-)1.0f / 8 =====" << std::endl << DEF_COLOR;
// 			Fixed eighth(1.0f / 8);
// 			std::cout << "toFloat(): " << eighth.toFloat() << std::endl;
// 			Fixed negEighth(-1.0f / 8);
// 			std::cout << "toFloat(): " << negEighth.toFloat() << std::endl;
// 			std::cout << BLUE << "===== (+-)1.0f / 16 =====" << std::endl << DEF_COLOR;
// 			Fixed sixteenth(1.0f / 16);
// 			std::cout << "toFloat(): " << sixteenth.toFloat() << std::endl;
// 			Fixed negSixteenth(-1.0f / 16);
// 			std::cout << "toFloat(): " << negSixteenth.toFloat() << std::endl;
// 			std::cout << BLUE << "===== (+-)1.0f / 32 =====" << std::endl << DEF_COLOR;
// 			Fixed thirtysecond(1.0f / 32);
// 			std::cout << "toFloat(): " << thirtysecond.toFloat() << std::endl;
// 			Fixed negThirtysecond(-1.0f / 32);
// 			std::cout << "toFloat(): " << negThirtysecond.toFloat() << std::endl;
// 			std::cout << BLUE << "===== (+-)1.0f / 64 =====" << std::endl << DEF_COLOR;
// 			Fixed sixtyfourth(1.0f / 64);
// 			std::cout << "toFloat(): " << sixtyfourth.toFloat() << std::endl;
// 			Fixed negSixtyfourth(-1.0f / 64);
// 			std::cout << "toFloat(): " << negSixtyfourth.toFloat() << std::endl;
// 			std::cout << BLUE << "===== (+-)1.0f / 128 =====" << std::endl << DEF_COLOR;
// 			Fixed oneTwentyEighth(1.0f / 128);
// 			std::cout << "toFloat(): " << oneTwentyEighth.toFloat() << std::endl;
// 			Fixed negOneTwentyEighth(-1.0f / 128);
// 			std::cout << "toFloat(): " << negOneTwentyEighth.toFloat() << std::endl;
// 			std::cout << BLUE << "===== (+-)1.0f / 256 =====" << std::endl << DEF_COLOR;
// 			Fixed oneTwoFiftySixth(1.0f / 256);
// 			std::cout << "toFloat(): " << oneTwoFiftySixth.toFloat() << std::endl;
// 			Fixed negOneTwoFiftySixth(-1.0f / 256);
// 			std::cout << "toFloat(): " << negOneTwoFiftySixth.toFloat() << std::endl;
// 			std::cout << BLUE << "===== (+-)1.0f / 512 =====" << std::endl << DEF_COLOR;
// 			Fixed oneFiveHundredTwelfth(1.0f / 512);
// 			std::cout << "toFloat(): " << oneFiveHundredTwelfth.toFloat() << std::endl;
// 			Fixed negOneFiveHundredTwelfth(-1.0f / 512);
// 			std::cout << "toFloat(): " << negOneFiveHundredTwelfth.toFloat() << std::endl;
// 			std::cout << BLUE << "===== (+-)1.0f / 1024 =====" << std::endl << DEF_COLOR;
// 			Fixed oneThousandTwentyFourth(1.0f / 1024);
// 			std::cout << "toFloat(): " << oneThousandTwentyFourth.toFloat() << std::endl;
// 			Fixed negOneThousandTwentyFourth(-1.0f / 1024);
// 			std::cout << "toFloat(): " << negOneThousandTwentyFourth.toFloat() << std::endl;
// 			try
// 			{
// 				std::cout << BLUE << "===== infinity =====" << std::endl << DEF_COLOR;
// 				Fixed posInf(std::numeric_limits<float>::infinity());
// 				std::cout << "toFloat(): " << posInf.toFloat() << std::endl;
// 			}
// 			catch(const std::exception& err)
// 			{
// 				std::cerr << "Error: " << err.what() << std::endl;
// 			}
// 			try
// 			{
// 				std::cout << BLUE << "===== -infinity =====" << std::endl << DEF_COLOR;
// 				Fixed negInf(-std::numeric_limits<float>::infinity());
// 				std::cout << "toFloat(): " << negInf.toFloat() << std::endl;
// 			}
// 			catch(const std::exception& err)
// 			{
// 				std::cerr << "Error: " << err.what() << std::endl;
// 			}
// 			try
// 			{
// 				std::cout << BLUE << "===== quiet NaN =====" << std::endl << DEF_COLOR;
// 				Fixed quietNaN(std::numeric_limits<float>::quiet_NaN());
// 				std::cout << "toFloat(): " << quietNaN.toFloat() << std::endl;
// 			}
// 			catch(const std::exception& err)
// 			{
// 				std::cerr << "Error: " << err.what() << std::endl;
// 			}
// 			try
// 			{
// 				std::cout << BLUE << "===== signaling NaN =====" << std::endl << DEF_COLOR;
// 				Fixed signalingNaN(std::numeric_limits<float>::signaling_NaN());
// 				std::cout << "toFloat(): " << signalingNaN.toFloat() << std::endl;
// 			}
// 			catch(const std::exception& err)
// 			{
// 				std::cerr << "Error: " << err.what() << std::endl;
// 			}
// 			try
// 			{
// 				std::cout << BLUE << "===== 1.0 / 0.0 =====" << std::endl << DEF_COLOR;
// 				Fixed divByZeroPos(1.0f / 0.0f);
// 				std::cout << "toFloat(): " << divByZeroPos.toFloat() << std::endl;
// 			}
// 			catch(const std::exception& err)
// 			{
// 				std::cerr << "Error: " << err.what() << std::endl;
// 			}
// 			try
// 			{
// 				std::cout << BLUE << "===== -1.0 / 0.0 =====" << std::endl << DEF_COLOR;
// 				Fixed divByZeroNeg(-1.0f / 0.0f);
// 				std::cout << "toFloat(): " << divByZeroNeg.toFloat() << std::endl;
// 			}
// 			catch(const std::exception& err)
// 			{
// 				std::cerr << "Error: " << err.what() << std::endl;
// 			}
// 			try
// 			{
// 				std::cout << BLUE << "===== 0.0 / 0.0 =====" << std::endl << DEF_COLOR;
// 				Fixed zeroDivZero(0.0f / 0.0f);
// 				std::cout << "toFloat(): " << zeroDivZero.toFloat() << std::endl;
// 			}
// 			catch(const std::exception& err)
// 			{
// 				std::cerr << "Error: " << err.what() << std::endl;
// 			}
// 		}
// }

// void testComparisonOperators()
// {
// 	std::cout << GREEN << "===== comparison operators =====" << std::endl << DEF_COLOR;
// 	std::cout << std::boolalpha;
// 	{
// 		Fixed a(1);
// 		Fixed b(2);
// 		Fixed c(1);
// 		std::cout << BLUE << "===== 1, 2 =====" << std::endl << DEF_COLOR;
// 		std::cout << "1 >  2 : " << (a > b) << std::endl;
// 		std::cout << "2 >  1 : " << (b > a) << std::endl;
// 		std::cout << "1 >  1 : " << (a > c) << std::endl;
// 		std::cout << "1 <  2 : " << (a < b) << std::endl;
// 		std::cout << "2 <  1 : " << (b < a) << std::endl;
// 		std::cout << "1 <  1 : " << (a < c) << std::endl;
// 		std::cout << "1 >= 2 : " << (a >= b) << std::endl;
// 		std::cout << "2 >= 1 : " << (b >= a) << std::endl;
// 		std::cout << "1 >= 1 : " << (a >= c) << std::endl;
// 		std::cout << "1 <= 2 : " << (a <= b) << std::endl;
// 		std::cout << "2 <= 1 : " << (b <= a) << std::endl;
// 		std::cout << "1 <= 1 : " << (a <= c) << std::endl;
// 		std::cout << "1 == 2 : " << (a == b) << std::endl;
// 		std::cout << "1 == 1 : " << (a == c) << std::endl;
// 		std::cout << "1 != 2 : " << (a != b) << std::endl;
// 		std::cout << "1 != 1 : " << (a != c) << std::endl;
// 	}
// 	{
// 		Fixed neg(-1);
// 		Fixed zero(0);
// 		Fixed pos(1);
// 		std::cout << BLUE << "===== -1, 0, 1 =====" << std::endl << DEF_COLOR;
// 		std::cout << "-1 <  0  : " << (neg <  zero) << std::endl;
// 		std::cout << " 0 <  1  : " << (zero < pos)  << std::endl;
// 		std::cout << "-1 <  1  : " << (neg <  pos)  << std::endl;
// 		std::cout << "-1 == -1 : " << (neg == neg)  << std::endl;
// 		std::cout << "-1 >  0  : " << (neg >  zero) << std::endl;
// 		std::cout << " 0 >  1  : " << (zero > pos)  << std::endl;
// 		std::cout << "-1 >  1  : " << (neg >  pos)  << std::endl;
// 		std::cout << " 1 >  -1 : " << (pos >  neg)  << std::endl;
// 		std::cout << " 0 >= -1 : " << (zero >= neg) << std::endl;
// 		std::cout << "-1 <= 0  : " << (neg <=  zero) << std::endl;
// 		std::cout << " 1 != -1 : " << (pos !=  neg) << std::endl;
// 		std::cout << " 0 != -1 : " << (zero != neg) << std::endl;
// 	}
// 	{
// 		Fixed negFrac(-0.5f);
// 		Fixed zero(0.0f);
// 		Fixed posFrac(0.5f);
// 		std::cout << BLUE << "===== -0.5, 0.0, 0.5 =====" << std::endl << DEF_COLOR;
// 		std::cout << "-0.5 <   0.5 : " << (negFrac <  posFrac) << std::endl;
// 		std::cout << " 0.5 <  -0.5 : " << (posFrac <  negFrac) << std::endl;
// 		std::cout << "-0.5 <   0.0 : " << (negFrac <  zero)    << std::endl;
// 		std::cout << " 0.0 <   0.5 : " << (zero    <  posFrac) << std::endl;
// 		std::cout << "-0.5 >   0.5 : " << (negFrac >  posFrac) << std::endl;
// 		std::cout << " 0.5 >  -0.5 : " << (posFrac >  negFrac) << std::endl;
// 		std::cout << "-0.5 >   0.0 : " << (negFrac >  zero)    << std::endl;
// 		std::cout << " 0.0 >  -0.5 : " << (zero    >  negFrac) << std::endl;
// 		std::cout << "-0.5 ==  0.5 : " << (negFrac == posFrac) << std::endl;
// 		std::cout << "-0.5 != 0.5  : " << (negFrac != posFrac) << std::endl;
// 		std::cout << " 0.0 ==  0.0 : " << (zero    == zero)    << std::endl;
// 		std::cout << " 0.0 != -0.5 : " << (zero    != negFrac) << std::endl;
// 	}
// 	std::cout << std::noboolalpha;
// }

// void testArithmeticOperators()
// {
// 	std::cout << GREEN << "===== arithmetic operators =====" << std::endl << DEF_COLOR;
// 	// Fixed op Fixed
// 	{
// 		std::cout << BLUE << "===== Fixed + Fixed =====" << std::endl << DEF_COLOR;
// 		Fixed a(1.5f);
// 		Fixed b(2.25f);
// 		std::cout << "1.5 + 2.25 = " << (a + b) << std::endl;
// 		Fixed neg(-1.5f);
// 		std::cout << "-1.5 + 2.25 = " << (neg + b) << std::endl;
// 		std::cout << "-1.5 + 1.5 = " << (neg + a) << std::endl;
// 		try
// 		{
// 			Fixed nearMax(8388607.0f);
// 			Fixed one(1.0f);
// 			std::cout << "8388607 + 1 = " << (nearMax + one) << std::endl;
// 		}
// 		catch(const std::exception& err)
// 		{
// 			std::cerr << "Error: " << err.what() << std::endl;
// 		}
// 	}
// 	{
// 		std::cout << BLUE << "===== Fixed - Fixed =====" << std::endl << DEF_COLOR;
// 		Fixed a(3.0f);
// 		Fixed b(1.5f);
// 		std::cout << "3.0 - 1.5 = " << (a - b) << std::endl;
// 		std::cout << "1.5 - 3.0 = " << (b - a) << std::endl;
// 		std::cout << "1.5 - 1.5 = " << (b - b) << std::endl;
// 		try
// 		{
// 			Fixed nearMin(-8388608.0f);
// 			Fixed one(1.0f);
// 			std::cout << "-8388608 - 1 = " << (nearMin - one) << std::endl;
// 		}
// 		catch(const std::exception& err)
// 		{
// 			std::cerr << "Error: " << err.what() << std::endl;
// 		}
// 	}
// 	{
// 		std::cout << BLUE << "===== Fixed * Fixed =====" << std::endl << DEF_COLOR;
// 		Fixed a(2.0f);
// 		Fixed b(3.0f);
// 		std::cout << "2.0 * 3.0 = " << (a * b) << std::endl;
// 		Fixed neg(-2.0f);
// 		std::cout << "-2.0 * 3.0 = " << (neg * b) << std::endl;
// 		std::cout << "-2.0 * -3.0 = " << (neg * Fixed(-3.0f)) << std::endl;
// 		Fixed zero(0.0f);
// 		std::cout << "2.0 * 0.0 = " << (a * zero) << std::endl;
// 		try
// 		{
// 			Fixed large(8388607.0f);
// 			Fixed two(2.0f);
// 			std::cout << "8388607 * 2 = " << (large * two) << std::endl;
// 		}
// 		catch(const std::exception& err)
// 		{
// 			std::cerr << "Error: " << err.what() << std::endl;
// 		}
// 	}
// 	{
// 		std::cout << BLUE << "===== Fixed / Fixed =====" << std::endl << DEF_COLOR;
// 		Fixed a(6.0f);
// 		Fixed b(2.0f);
// 		std::cout << "6.0 / 2.0 = " << (a / b) << std::endl;
// 		Fixed neg(-6.0f);
// 		std::cout << "-6.0 / 2.0 = " << (neg / b) << std::endl;
// 		std::cout << "-6.0 / -2.0 = " << (neg / Fixed(-2.0f)) << std::endl;
// 		std::cout << "1.0 / 3.0 = " << (Fixed(1.0f) / Fixed(3.0f)) << std::endl;
// 		try
// 		{
// 			Fixed numerator(1.0f);
// 			Fixed zero(0.0f);
// 			std::cout << "1.0 / 0.0 = " << (numerator / zero) << std::endl;
// 		}
// 		catch(const std::exception& err)
// 		{
// 			std::cerr << "Error: " << err.what() << std::endl;
// 		}
// 	}
// 	// int op Fixed / Fixed op int (implicit conversion)
// 	{
// 		std::cout << BLUE << "===== int op Fixed =====" << std::endl << DEF_COLOR;
// 		Fixed a(1.5f);
// 		std::cout << "2 + 1.5 = " << (2 + a) << std::endl;
// 		std::cout << "2 - 1.5 = " << (2 - a) << std::endl;
// 		std::cout << "2 * 1.5 = " << (2 * a) << std::endl;
// 		std::cout << "3 / 1.5 = " << (3 / a) << std::endl;
// 	}
// 	{
// 		std::cout << BLUE << "===== Fixed op int =====" << std::endl << DEF_COLOR;
// 		Fixed a(1.5f);
// 		std::cout << "1.5 + 2 = " << (a + 2) << std::endl;
// 		std::cout << "1.5 - 2 = " << (a - 2) << std::endl;
// 		std::cout << "1.5 * 2 = " << (a * 2) << std::endl;
// 		std::cout << "1.5 / 2 = " << (a / 2) << std::endl;
// 	}
// 	// float op Fixed / Fixed op float (implicit conversion)
// 	{
// 		std::cout << BLUE << "===== float op Fixed =====" << std::endl << DEF_COLOR;
// 		Fixed a(2.0f);
// 		std::cout << "1.5f + 2.0 = " << (1.5f + a) << std::endl;
// 		std::cout << "1.5f - 2.0 = " << (1.5f - a) << std::endl;
// 		std::cout << "1.5f * 2.0 = " << (1.5f * a) << std::endl;
// 		std::cout << "3.0f / 2.0 = " << (3.0f / a) << std::endl;
// 	}
// 	{
// 		std::cout << BLUE << "===== Fixed op float =====" << std::endl << DEF_COLOR;
// 		Fixed a(1.5f);
// 		std::cout << "1.5 + 2.0f = " << (a + 2.0f) << std::endl;
// 		std::cout << "1.5 - 2.0f = " << (a - 2.0f) << std::endl;
// 		std::cout << "1.5 * 2.0f = " << (a * 2.0f) << std::endl;
// 		std::cout << "1.5 / 2.0f = " << (a / 2.0f) << std::endl;
// 	}
// }

// void testIncrementDecrementOperators()
// {
// 	std::cout << GREEN << "===== increment/decrement operators =====" << std::endl << DEF_COLOR;
// 	// pre-increment: returns reference to incremented value
// 	{
// 		std::cout << BLUE << "===== pre-increment =====" << std::endl << DEF_COLOR;
// 		Fixed a(0.0f);
// 		std::cout << "a=0.0, ++a = " << (++a) << std::endl;
// 		std::cout << "a after ++a: " << a << std::endl;
// 		Fixed b(1.0f);
// 		std::cout << "b=1.0, ++b = " << (++b) << std::endl;
// 		std::cout << "b after ++b: " << b << std::endl;
// 		Fixed neg(-1.0f);
// 		std::cout << "neg=-1.0, ++neg = " << (++neg) << std::endl;
// 		std::cout << "neg after ++neg: " << neg << std::endl;
// 		// 1 ulp below zero -> crosses zero
// 		Fixed belowZero;
// 		belowZero.setRawBits(-1);
// 		std::cout << "belowZero(-1ulp), ++belowZero = " << (++belowZero) << std::endl;
// 		try
// 		{
// 			Fixed atMax;
// 			atMax.setRawBits(std::numeric_limits<int>::max());
// 			std::cout << "++atMax = " << (++atMax) << std::endl;
// 		}
// 		catch(const std::exception& err)
// 		{
// 			std::cerr << "Error: " << err.what() << std::endl;
// 		}
// 	}
// 	// post-increment: returns copy of value before increment
// 	{
// 		std::cout << BLUE << "===== post-increment =====" << std::endl << DEF_COLOR;
// 		Fixed a(0.0f);
// 		std::cout << "a=0.0, a++ = " << (a++) << std::endl;
// 		std::cout << "a after a++: " << a << std::endl;
// 		Fixed b(1.0f);
// 		std::cout << "b=1.0, b++ = " << (b++) << std::endl;
// 		std::cout << "b after b++: " << b << std::endl;
// 		Fixed neg(-1.0f);
// 		std::cout << "neg=-1.0, neg++ = " << (neg++) << std::endl;
// 		std::cout << "neg after neg++: " << neg << std::endl;
// 		Fixed belowZero;
// 		belowZero.setRawBits(-1);
// 		std::cout << "belowZero(-1ulp), belowZero++ = " << (belowZero++) << std::endl;
// 		std::cout << "belowZero after belowZero++: " << belowZero << std::endl;
// 		try
// 		{
// 			Fixed atMax;
// 			atMax.setRawBits(std::numeric_limits<int>::max());
// 			std::cout << "atMax++ = " << (atMax++) << std::endl;
// 		}
// 		catch(const std::exception& err)
// 		{
// 			std::cerr << "Error: " << err.what() << std::endl;
// 		}
// 	}
// 	// pre-decrement: returns reference to decremented value
// 	{
// 		std::cout << BLUE << "===== pre-decrement =====" << std::endl << DEF_COLOR;
// 		Fixed a(0.0f);
// 		std::cout << "a=0.0, --a = " << (--a) << std::endl;
// 		std::cout << "a after --a: " << a << std::endl;
// 		Fixed b(1.0f);
// 		std::cout << "b=1.0, --b = " << (--b) << std::endl;
// 		std::cout << "b after --b: " << b << std::endl;
// 		Fixed neg(-1.0f);
// 		std::cout << "neg=-1.0, --neg = " << (--neg) << std::endl;
// 		std::cout << "neg after --neg: " << neg << std::endl;
// 		// 1 ulp above zero -> crosses zero
// 		Fixed aboveZero;
// 		aboveZero.setRawBits(1);
// 		std::cout << "aboveZero(1ulp), --aboveZero = " << (--aboveZero) << std::endl;
// 		try
// 		{
// 			Fixed atMin;
// 			atMin.setRawBits(std::numeric_limits<int>::min());
// 			std::cout << "--atMin = " << (--atMin) << std::endl;
// 		}
// 		catch(const std::exception& err)
// 		{
// 			std::cerr << "Error: " << err.what() << std::endl;
// 		}
// 	}
// 	// post-decrement: returns copy of value before decrement
// 	{
// 		std::cout << BLUE << "===== post-decrement =====" << std::endl << DEF_COLOR;
// 		Fixed a(0.0f);
// 		std::cout << "a=0.0, a-- = " << (a--) << std::endl;
// 		std::cout << "a after a--: " << a << std::endl;
// 		Fixed b(1.0f);
// 		std::cout << "b=1.0, b-- = " << (b--) << std::endl;
// 		std::cout << "b after b--: " << b << std::endl;
// 		Fixed neg(-1.0f);
// 		std::cout << "neg=-1.0, neg-- = " << (neg--) << std::endl;
// 		std::cout << "neg after neg--: " << neg << std::endl;
// 		Fixed aboveZero;
// 		aboveZero.setRawBits(1);
// 		std::cout << "aboveZero(1ulp), aboveZero-- = " << (aboveZero--) << std::endl;
// 		std::cout << "aboveZero after aboveZero--: " << aboveZero << std::endl;
// 		try
// 		{
// 			Fixed atMin;
// 			atMin.setRawBits(std::numeric_limits<int>::min());
// 			std::cout << "atMin-- = " << (atMin--) << std::endl;
// 		}
// 		catch(const std::exception& err)
// 		{
// 			std::cerr << "Error: " << err.what() << std::endl;
// 		}
// 	}
// }

// void testCompoundAssignmentOperators()
// {
// 	std::cout << GREEN << "===== compound assignment operators =====" << std::endl << DEF_COLOR;
// 	// Fixed op= Fixed
// 	{
// 		std::cout << BLUE << "===== Fixed += Fixed =====" << std::endl << DEF_COLOR;
// 		Fixed a(1.5f);
// 		a += Fixed(2.25f);
// 		std::cout << "1.5 += 2.25 -> " << a << std::endl;
// 	}
// 	{
// 		std::cout << BLUE << "===== Fixed -= Fixed =====" << std::endl << DEF_COLOR;
// 		Fixed a(3.0f);
// 		a -= Fixed(1.5f);
// 		std::cout << "3.0 -= 1.5 -> " << a << std::endl;
// 	}
// 	{
// 		std::cout << BLUE << "===== Fixed *= Fixed =====" << std::endl << DEF_COLOR;
// 		Fixed a(2.0f);
// 		a *= Fixed(3.0f);
// 		std::cout << "2.0 *= 3.0 -> " << a << std::endl;
// 	}
// 	{
// 		std::cout << BLUE << "===== Fixed /= Fixed =====" << std::endl << DEF_COLOR;
// 		Fixed a(6.0f);
// 		a /= Fixed(2.0f);
// 		std::cout << "6.0 /= 2.0 -> " << a << std::endl;
// 	}
// 	// Fixed op= int (implicit conversion)
// 	{
// 		std::cout << BLUE << "===== Fixed += int =====" << std::endl << DEF_COLOR;
// 		Fixed a(1.5f);
// 		a += 2;
// 		std::cout << "1.5 += 2 -> " << a << std::endl;
// 	}
// 	{
// 		std::cout << BLUE << "===== Fixed -= int =====" << std::endl << DEF_COLOR;
// 		Fixed a(3.0f);
// 		a -= 1;
// 		std::cout << "3.0 -= 1 -> " << a << std::endl;
// 	}
// 	{
// 		std::cout << BLUE << "===== Fixed *= int =====" << std::endl << DEF_COLOR;
// 		Fixed a(2.0f);
// 		a *= 3;
// 		std::cout << "2.0 *= 3 -> " << a << std::endl;
// 	}
// 	{
// 		std::cout << BLUE << "===== Fixed /= int =====" << std::endl << DEF_COLOR;
// 		Fixed a(6.0f);
// 		a /= 2;
// 		std::cout << "6.0 /= 2 -> " << a << std::endl;
// 	}
// 	// Fixed op= float (implicit conversion)
// 	{
// 		std::cout << BLUE << "===== Fixed += float =====" << std::endl << DEF_COLOR;
// 		Fixed a(1.5f);
// 		a += 2.25f;
// 		std::cout << "1.5 += 2.25f -> " << a << std::endl;
// 	}
// 	{
// 		std::cout << BLUE << "===== Fixed -= float =====" << std::endl << DEF_COLOR;
// 		Fixed a(3.0f);
// 		a -= 1.5f;
// 		std::cout << "3.0 -= 1.5f -> " << a << std::endl;
// 	}
// 	{
// 		std::cout << BLUE << "===== Fixed *= float =====" << std::endl << DEF_COLOR;
// 		Fixed a(2.0f);
// 		a *= 3.0f;
// 		std::cout << "2.0 *= 3.0f -> " << a << std::endl;
// 	}
// 	{
// 		std::cout << BLUE << "===== Fixed /= float =====" << std::endl << DEF_COLOR;
// 		Fixed a(6.0f);
// 		a /= 2.0f;
// 		std::cout << "6.0 /= 2.0f -> " << a << std::endl;
// 	}
// }

// void testMinMax()
// {
// 	std::cout << GREEN << "===== min/max =====" << std::endl << DEF_COLOR;
// 	{
// 		Fixed a(1.0f);
// 		Fixed b(2.0f);
// 		std::cout << BLUE << "===== min(1.0, 2.0) =====" << std::endl << DEF_COLOR;
// 		std::cout << "min: " << Fixed::min(a, b) << std::endl;
// 		std::cout << "max: " << Fixed::max(a, b) << std::endl;
// 	}
// 	{
// 		Fixed a(-1.0f);
// 		Fixed b(-2.0f);
// 		std::cout << BLUE << "===== min(-1.0, -2.0) =====" << std::endl << DEF_COLOR;
// 		std::cout << "min: " << Fixed::min(a, b) << std::endl;
// 		std::cout << "max: " << Fixed::max(a, b) << std::endl;
// 	}
// 	{
// 		Fixed a(0.0f);
// 		Fixed b(0.0f);
// 		std::cout << BLUE << "===== min(0.0, 0.0) =====" << std::endl << DEF_COLOR;
// 		std::cout << "min: " << Fixed::min(a, b) << std::endl;
// 		std::cout << "max: " << Fixed::max(a, b) << std::endl;
// 	}
// 	{
// 		const Fixed a(3.0f);
// 		const Fixed b(3.0f);
// 		std::cout << BLUE << "===== const min(3.0, 3.0) =====" << std::endl << DEF_COLOR;
// 		std::cout << "min: " << Fixed::min(a, b) << std::endl;
// 		std::cout << "max: " << Fixed::max(a, b) << std::endl;
// 	}
// }

// void testRounding()
// {
// 	// fractional_bits = 8, so 1 ulp(Unit in the Last Place) = 1/256 = 0.00390625
// 	std::cout << GREEN << "===== rounding =====" << std::endl << DEF_COLOR;
// 	{
// 		std::cout << BLUE << "===== float constructor =====" << std::endl << DEF_COLOR;
// 		float f1 = 1.0f / 3.0f;
// 		Fixed oneThird(f1);
// 		std::cout << "Fixed(1/3)    : Fixed=" << oneThird    << " float=" << f1 << std::endl;
// 		float f2 = 2.0f / 3.0f;
// 		Fixed twoThirds(f2);
// 		std::cout << "Fixed(2/3)    : Fixed=" << twoThirds   << " float=" << f2 << std::endl;
// 		float f3 = 0.5f / 256.0f;
// 		Fixed halfUlp(f3);
// 		std::cout << "Fixed(0.5ulp) : Fixed=" << halfUlp     << " float=" << f3 << std::endl;
// 		float f4 = 0.4f / 256.0f;
// 		Fixed belowHalfUlp(f4);
// 		std::cout << "Fixed(0.4ulp) : Fixed=" << belowHalfUlp << " float=" << f4 << std::endl;
// 	}
// 	{
// 		std::cout << BLUE << "===== division =====" << std::endl << DEF_COLOR;
// 		Fixed divOneThird    = Fixed(1.0f) / Fixed(3.0f);
// 		std::cout << " 1 / 3 : Fixed=" << divOneThird    << " float=" << (1.0f / 3.0f) << std::endl;
// 		Fixed divTwoThirds   = Fixed(2.0f) / Fixed(3.0f);
// 		std::cout << " 2 / 3 : Fixed=" << divTwoThirds   << " float=" << (2.0f / 3.0f) << std::endl;
// 		Fixed divOneSixth    = Fixed(1.0f) / Fixed(6.0f);
// 		std::cout << " 1 / 6 : Fixed=" << divOneSixth    << " float=" << (1.0f / 6.0f) << std::endl;
// 		Fixed divNegOneThird = Fixed(-1.0f) / Fixed(3.0f);
// 		std::cout << "-1 / 3 : Fixed=" << divNegOneThird << " float=" << (-1.0f / 3.0f) << std::endl;
// 		Fixed divNegTwoThirds = Fixed(-2.0f) / Fixed(3.0f);
// 		std::cout << "-2 / 3 : Fixed=" << divNegTwoThirds << " float=" << (-2.0f / 3.0f) << std::endl;
// 	}
// 	{
// 		std::cout << BLUE << "===== multiplication =====" << std::endl << DEF_COLOR;
// 		Fixed mulThirdSq    = Fixed(1.0f / 3.0f) * Fixed(1.0f / 3.0f);
// 		std::cout << "(1/3)^2      : Fixed=" << mulThirdSq    << " float=" << (1.0f / 3.0f * (1.0f / 3.0f)) << std::endl;
// 		Fixed mulTwoThirdSq = Fixed(2.0f / 3.0f) * Fixed(2.0f / 3.0f);
// 		std::cout << "(2/3)^2      : Fixed=" << mulTwoThirdSq << " float=" << (2.0f / 3.0f * (2.0f / 3.0f)) << std::endl;
// 		Fixed halfTimesUlp  = Fixed(0.5f) * Fixed(1.0f / 256.0f);
// 		std::cout << "0.5 * (1ulp) : Fixed=" << halfTimesUlp  << " float=" << (0.5f * (1.0f / 256.0f)) << std::endl;
// 	}
// 	{
// 		std::cout << BLUE << "===== toInt vs toIntRounded =====" << std::endl << DEF_COLOR;
// 		Fixed half(0.5f);
// 		std::cout << " 0.5  toInt()=" << half.toInt()        << " toIntRounded()=" << half.toIntRounded() << std::endl;
// 		Fixed belowHalf(0.49609375f);
// 		std::cout << " 0.496 toInt()=" << belowHalf.toInt()  << " toIntRounded()=" << belowHalf.toIntRounded() << std::endl;
// 		Fixed negHalf(-0.5f);
// 		std::cout << "-0.5  toInt()=" << negHalf.toInt()     << " toIntRounded()=" << negHalf.toIntRounded() << std::endl;
// 		Fixed oneHalf(1.5f);
// 		std::cout << " 1.5  toInt()=" << oneHalf.toInt()     << " toIntRounded()=" << oneHalf.toIntRounded() << std::endl;
// 	}
// }
