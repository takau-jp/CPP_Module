/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 23:52:09 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/24 13:14:58 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// INT_MAX / 2^8 = 8388607.99609375
const double Fixed::_max_value = \
	static_cast<double>(std::numeric_limits<int>::max()) / (1 << Fixed::_fractional_bits);
// INT_MIN / 2^8 = -8388608.0
const double Fixed::_min_value = \
	static_cast<double>(std::numeric_limits<int>::min()) / (1 << Fixed::_fractional_bits);

Fixed::Fixed() : _raw_bits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	if (static_cast<double>(num) > Fixed::_max_value)
	{
		throw std::overflow_error("overflow");
	}
	if (static_cast<double>(num) < Fixed::_min_value)
	{
		throw std::overflow_error("overflow");
	}
	this->setRawBits(num * (1 << Fixed::_fractional_bits));
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;

	if (num != num)
	{
		throw std::invalid_argument("Not a number");
	}
	if (num == std::numeric_limits<float>::infinity())
	{
		throw std::overflow_error("Infinity");
	}
	if (num == -std::numeric_limits<float>::infinity())
	{
		throw std::overflow_error("-Infinity");
	}

	if (static_cast<double>(num) > Fixed::_max_value ||
		static_cast<double>(num) < Fixed::_min_value)
	{
		throw std::overflow_error("overflow");
	}

	float scaled = roundf(num * (1 << Fixed::_fractional_bits));
	if (scaled > static_cast<float>(std::numeric_limits<int>::max()) ||
		scaled < static_cast<float>(std::numeric_limits<int>::min()))
	{
		throw std::overflow_error("overflow");
	}

	this->setRawBits(static_cast<int>(scaled));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

bool	Fixed::isNegative() const
{
	return (this->getRawBits() < 0);
}

unsigned long	Fixed::getAbsRawBits() const
{
	return (static_cast<unsigned long>(this->isNegative() ? -(static_cast<long>(this->getRawBits())) : this->getRawBits()));
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->setRawBits(other.getRawBits());
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}

int Fixed::getRawBits(void) const
{
	return (this->_raw_bits);
}

void Fixed::setRawBits(const int raw)
{
	this->_raw_bits = raw;
}

int Fixed::toInt() const
{
	unsigned long abs_raw = this->getAbsRawBits();
	long raw = static_cast<long>(abs_raw >> Fixed::_fractional_bits);
	if (this->isNegative())
		raw = -raw;
	return static_cast<int>(raw);
}

int Fixed::toIntRounded() const
{
	unsigned long abs_raw = this->getAbsRawBits();
	long raw = static_cast<long>(abs_raw >> Fixed::_fractional_bits);
	if ((abs_raw >> (Fixed::_fractional_bits - 1)) & 1)
		++raw;
	if (this->isNegative())
		raw = -raw;
	return static_cast<int>(raw);
}

float Fixed::toFloat() const
{
	double value =
		static_cast<double>(this->getRawBits()) / (1 << Fixed::_fractional_bits);
	return (static_cast<float>(value));
}
