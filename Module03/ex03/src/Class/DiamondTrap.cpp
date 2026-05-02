/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 21:09:53 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/02 20:44:06 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#include <iostream>
#include <limits>

DiamondTrap::DiamondTrap()
	: ClapTrap("Unknown_clap_name", default_hit_points, default_energy_points,
			   default_attack_damage),
	  ScavTrap(), FragTrap(), _name("Unknown")
{
	std::cout << "DiamondTrap: " << this->_name
			  << ": Default constructor has been called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name)
	: ClapTrap(name + "_clap_name", default_hit_points, default_energy_points,
			   default_attack_damage),
	  ScavTrap(), FragTrap(), _name(name)
{
	std::cout << "DiamondTrap: " << this->_name
			  << ": Constructor has been called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
	: ClapTrap(other), ScavTrap(), FragTrap(), _name(other._name)
{
	std::cout << "DiamondTrap: " << this->_name
			  << ": Copy constructor has been called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->_name = other._name;
	}

	std::cout << "DiamondTrap: " << this->_name
			  << ": Copy assignment operator has been called" << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap: " << this->_name
			  << ": Destructor has been called" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
	if (!isAlive())
	{
		printDead();
		return;
	}

	std::cout << std::endl;
	std::cout << "   /\\_/\\" << std::endl;
	std::cout << "  ( ÒωÓ )  I'm " << this->getName() << "!!" << std::endl;
	std::cout << "  /| + |\\" << std::endl;
	std::cout << " (_|   |_)" << std::endl;
	std::cout << std::endl;

	std::cout << "DiamondTrap: " << "I'm " << this->_name << ", inherited from "
			  << this->ClapTrap::getName() << "!!" << std::endl;
}

void DiamondTrap::printDead(void) const
{
	std::cout << std::endl;
	std::cout << "   |\\ _,,,---,,_" << std::endl;
	std::cout << "   /,`.-'`'    -.  ;-;;,_" << std::endl;
	std::cout << "  |,4-  ) )-,_..; \\ (  `'-'" << std::endl;
	std::cout << " '---''(_/--'  `-'\\_)" << std::endl;
	std::cout << std::endl;

	std::cout << "DiamondTrap: " << this->_name << " is dead!" << std::endl;
}

const std::string &DiamondTrap::getName(void) const
{
	return (this->_name);
}
