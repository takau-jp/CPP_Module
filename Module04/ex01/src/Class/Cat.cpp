/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 23:18:53 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/18 17:12:06 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Brain.hpp"
#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat: Default constructor has been called." << std::endl;

	this->_brain = new Brain;
}

Cat::Cat(const Cat &other) : Animal(other.type)
{
	std::cout << "Cat: Copy constructor has been called." << std::endl;

	this->_brain = new Brain(*(other._brain));
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat: Copy assignment operator has been called." << std::endl;

	if (this != &other)
	{
		this->Animal::operator=(other);
		*(this->_brain) = *(other._brain);
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat: Destructor has been called." << std::endl;

	delete this->_brain;
}

void Cat::makeSound() const
{
	std::cout << "meow!!" << std::endl;
}

void Cat::speak(unsigned int ideas_ago) const
{
	const std::string *idea = this->_brain->think(ideas_ago);

	if (idea == NULL)
	{
		std::cout << "I have no idea....." << std::endl;
		return;
	}
	std::cout << *idea << std::endl;
}

void Cat::memorize(const std::string &idea)
{
	this->_brain->memorize(idea);
}
