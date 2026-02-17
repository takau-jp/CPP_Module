/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 00:46:45 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/16 01:21:02 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	this->name = "no_name";
	std::cout << "[" << this->name << "] constructor has called." << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "[" << this->name << "] constructor has called." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "[" << this->name << "] destractor has called." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
