/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 23:18:51 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/18 20:06:04 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal: Default constructor has been called." << std::endl;
}

Animal::Animal(const std::string &type) : type(type)
{
	std::cout << "Animal: Constructor has been called." << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << "Animal: Copy constructor has been called." << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << "Animal: Copy assignment operator has been called."
			  << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal: Destructor has been called." << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Animaaaaaaaaaaaaaal!!" << std::endl;
}

const std::string &Animal::getType() const
{
	return (this->type);
}
