/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 21:56:05 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/18 16:25:09 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Brain.hpp"

Brain::Brain() : _idea_count(0), _newest(0), _oldest(0)
{
	std::cout << "Brain: Default constructor has been called." << std::endl;
}

Brain::Brain(const Brain &other)
	: _idea_count(other._idea_count), _newest(other._newest),
	  _oldest(other._oldest)
{
	std::cout << "Brain: Copy constructor has been called." << std::endl;

	for (unsigned int i = 0; i < this->_idea_count; ++i)
	{
		this->_ideas[i] = other._ideas[i];
	}
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain: Copy assignment operator has been called."
			  << std::endl;
	if (this != &other)
	{
		this->_idea_count = other._idea_count;
		this->_newest = other._newest;
		this->_oldest = other._oldest;
		for (unsigned int i = 0; i < this->_idea_count; ++i)
		{
			this->_ideas[i] = other._ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain: Destructor has been called." << std::endl;
}

void Brain::memorize(const std::string &idea)
{
	if (this->_idea_count < Brain::max_memory)
	{
		this->_newest = this->_idea_count++;
		this->_ideas[this->_newest] = idea;
	}
	else
	{
		this->_newest = this->_oldest++;
		this->_ideas[this->_newest] = idea;
		if (this->_oldest == Brain::max_memory)
			this->_oldest = 0;
	}
}

const std::string *Brain::think(unsigned int ideas_ago) const
{
	if (this->_idea_count <= ideas_ago)
	{
		return (NULL);
	}

	if (this->_newest >= ideas_ago)
	{
		return (&(this->_ideas[this->_newest - ideas_ago]));
	}
	else
	{
		return (
			&(this->_ideas[Brain::max_memory - (ideas_ago - this->_newest)]));
	}
}
