/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:49:22 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/02 20:44:44 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include <iostream>
#include <limits>

FragTrap::FragTrap()
	: ClapTrap("Unknown", default_hit_points, default_energy_points,
			   default_attack_damage)
{
	std::cout << "FragTrap: " << this->getName()
			  << ": Default constructor has been called" << std::endl;
}

FragTrap::FragTrap(const std::string &name)
	: ClapTrap(name, default_hit_points, default_energy_points,
			   default_attack_damage)
{
	std::cout << "FragTrap: " << this->getName()
			  << ": Constructor has been called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap: " << this->getName()
			  << ": Copy constructor has been called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}

	std::cout << "FragTrap: " << this->getName()
			  << ": Copy assignment operator has been called" << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: " << this->getName()
			  << ": Destructor has been called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (!isAlive())
	{
		printDead();
		return;
	}

	std::cout << std::endl;
	std::cout << "   /\\_/\\    /\\_/\\" << std::endl;
	std::cout << "  ( ^ω^ )人( ^ω^ )  Yeah!!" << std::endl;
	std::cout << "  /|            |\\" << std::endl;
	std::cout << " (_|   _)  (_   |_)" << std::endl;
	std::cout << std::endl;

	std::cout << "FragTrap: " << this->getName() << " requests a High Five!!"
			  << std::endl;
}

void FragTrap::printDead(void) const
{
	std::cout << std::endl;
	std::cout << "   |\\ _,,,---,,_" << std::endl;
	std::cout << "   /,`.-'`'    -.  ;-;;,_" << std::endl;
	std::cout << "  |,4-  ) )-,_..; \\ (  `'-'" << std::endl;
	std::cout << " '---''(_/--'  `-'\\_)" << std::endl;
	std::cout << std::endl;

	std::cout << "FragTrap: " << this->getName() << " is dead!" << std::endl;
}
