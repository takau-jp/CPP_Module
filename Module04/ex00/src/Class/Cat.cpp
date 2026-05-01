/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 23:18:53 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/17 14:46:25 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat: Default constructor has been called." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other.type)
{
	std::cout << "Cat: Copy constructor has been called." << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat: Copy assignment operator has been called." << std::endl;

	if (this != &other)
	{
		this->Animal::operator=(other);
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat: Destructor has been called." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "meow!!" << std::endl;
}
