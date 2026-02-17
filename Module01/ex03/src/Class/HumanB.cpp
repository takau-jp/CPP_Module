/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:08:25 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/16 17:27:22 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string &name) : name(name), weapon(NULL)
{
	std::cout << "Human B[" << this->name << "] has created" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "Human B[" << this->name << "] has been destroyed"
			  << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
	std::cout << "Human B[" << this->name << "] has " << this->weapon->getType()
			  << std::endl;
}

void HumanB::attack() const
{
	if (this->weapon == NULL)
	{
		std::cout << this->name << " attacks with their fist" << std::endl;
		return;
	}
	std::cout << this->name << " attacks with their " << this->weapon->getType()
			  << std::endl;
}
