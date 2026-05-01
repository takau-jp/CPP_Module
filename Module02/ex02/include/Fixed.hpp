/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 17:48:55 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/29 22:05:04 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>
#include <limits>

// Only for LP64 data model (Sorry Windows User....)
class Fixed
{
  private:
	// Fixed class requires int(32bit), long(64bit), float(32bit), double(64bit). (otherwise compilation error)
	typedef char _assert_type_size[(sizeof(int) == 4 \
								&& sizeof(long) == 8 \
								&& sizeof(float) == 4 \
								&& sizeof(double) == 8) \
								? 1: -1];
	// Fixed class requires IEEE754 standard(iec559==IEEE754). (otherwise compilation error) 
	typedef char _assert_ieee754[(std::numeric_limits<float>::is_iec559 \
								&& std::numeric_limits<double>::is_iec559) \
								? 1 : -1];

	static const int _fractional_bits = 8;
	int _raw_bits;

	static const double _max_value;
	static const double _min_value;
	bool isNegative() const;
	unsigned long getAbsRawBits() const;

  public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed(const int);
	Fixed(const float);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
	int toInt() const;
	int toIntRounded() const;
	float toFloat() const;

	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);

	Fixed &operator=(const Fixed &other);
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;
	Fixed &operator++(void);
	Fixed operator++(int);
	Fixed &operator--(void);
	Fixed operator--(int);

	Fixed &operator+=(const Fixed &other);
	Fixed &operator-=(const Fixed &other);
	Fixed &operator*=(const Fixed &other);
	Fixed &operator/=(const Fixed &other);

};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

std::istream &operator>>(std::istream &is, Fixed &fixed);

bool operator>(const int num, const Fixed &fixed);
bool operator<(const int num, const Fixed &fixed);
bool operator>=(const int num, const Fixed &fixed);
bool operator<=(const int num, const Fixed &fixed);
bool operator==(const int num, const Fixed &fixed);
bool operator!=(const int num, const Fixed &fixed);
Fixed operator+(const int num, const Fixed &fixed);
Fixed operator-(const int num, const Fixed &fixed);
Fixed operator*(const int num, const Fixed &fixed);
Fixed operator/(const int num, const Fixed &fixed);
bool operator>(const float num, const Fixed &fixed);
bool operator<(const float num, const Fixed &fixed);
bool operator>=(const float num, const Fixed &fixed);
bool operator<=(const float num, const Fixed &fixed);
bool operator==(const float num, const Fixed &fixed);
bool operator!=(const float num, const Fixed &fixed);
Fixed operator+(const float num, const Fixed &fixed);
Fixed operator-(const float num, const Fixed &fixed);
Fixed operator*(const float num, const Fixed &fixed);
Fixed operator/(const float num, const Fixed &fixed);

#endif
