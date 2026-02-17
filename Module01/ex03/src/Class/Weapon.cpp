/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:08:30 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/16 16:45:30 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(const std::string &type) : type(type)
{
	std::cout << "Weapon[" << this->type << "] has been created" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Weapon[" << this->type << "] has been destroyed" << std::endl;
}

const std::string &Weapon::getType() const
{
	return (this->type);
}

void Weapon::setType(const std::string &type)
{
	this->type = type;
	std::cout << "Weapon[" << this->type << "] has been set" << std::endl;
}
