/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 23:18:55 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/16 22:15:20 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog: Default constructor has been called." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other.type)
{
	std::cout << "Dog: Copy constructor has been called." << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog: Copy assignment operator has been called." << std::endl;

	if (this != &other)
	{
		this->Animal::operator=(other);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog: Destructor has been called." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "bowwow!!" << std::endl;
}
