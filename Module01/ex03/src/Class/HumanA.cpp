/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:08:22 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/16 16:57:33 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string &name, Weapon &weapon)
	: name(name), weapon(weapon)
{
	std::cout << "Human A[" << this->name << "] has " << this->weapon.getType()
			  << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "Human A[" << this->name << "] has been destroyed"
			  << std::endl;
}

void HumanA::attack() const
{
	std::cout << this->name << " attacks with their " << this->weapon.getType()
			  << std::endl;
}
