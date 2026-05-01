/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 23:18:55 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/18 17:11:58 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Brain.hpp"
#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog: Default constructor has been called." << std::endl;

	this->_brain = new Brain;
}

Dog::Dog(const Dog &other) : Animal(other.type)
{
	std::cout << "Dog: Copy constructor has been called." << std::endl;

	this->_brain = new Brain(*(other._brain));
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog: Copy assignment operator has been called." << std::endl;

	if (this != &other)
	{
		this->Animal::operator=(other);
		*(this->_brain) = *(other._brain);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog: Destructor has been called." << std::endl;

	delete this->_brain;
}

void Dog::makeSound() const
{
	std::cout << "bowwow!!" << std::endl;
}

void Dog::speak(unsigned int ideas_ago) const
{
	const std::string *idea = this->_brain->think(ideas_ago);

	if (idea == NULL)
	{
		std::cout << "I have no idea....." << std::endl;
		return;
	}
	std::cout << *idea << std::endl;
}

void Dog::memorize(const std::string &idea)
{
	this->_brain->memorize(idea);
}
