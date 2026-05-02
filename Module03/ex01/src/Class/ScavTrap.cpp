/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 01:20:19 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/02 19:47:47 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap() : ClapTrap("Unknown", 100, 50, 20)
{
	std::cout << "ScavTrap: " << this->getName()
			  << ": Default constructor has been called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap: " << this->getName()
			  << ": Constructor has been called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap: " << this->getName()
			  << ": Copy constructor has been called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}

	std::cout << "ScavTrap: " << this->getName()
			  << ": Copy assignment operator has been called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: " << this->getName()
			  << ": Destructor has been called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (!isAlive())
	{
		printDead();
		return;
	}
	if (!useEnergyPoints())
	{
		printNoEnergy();
		return;
	}

	std::cout << std::endl;
	std::cout << "   /\\_/\\          /\\_/\\" << std::endl;
	std::cout << "  ( >`ω´<)ﾉ <<*  ( ;ω; )" << std::endl;
	std::cout << "  /|    \\        /|  |\\" << std::endl;
	std::cout << " (_|    _)      (_|  |_)" << std::endl;
	std::cout << std::endl;

	std::cout << "ScavTrap: " << this->getName() << " attacks " << target
			  << ", causing " << this->getAttackDamage()
			  << (this->getAttackDamage() <= 1 ? " point" : " points")
			  << " of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	if (!isAlive())
	{
		printDead();
		return;
	}

	std::cout << std::endl;
	std::cout << "   /\\_/\\" << std::endl;
	std::cout << "  ( -ω- )  Guard Gate!!" << std::endl;
	std::cout << "  /|   |\\" << std::endl;
	std::cout << " (_|___|_)" << std::endl;
	std::cout << std::endl;

	std::cout << "ScavTrap: " << this->getName()
			  << " change to [Guard Gate] mode." << std::endl;
}

void ScavTrap::printDead(void) const
{
	std::cout << std::endl;
	std::cout << "   |\\ _,,,---,,_" << std::endl;
	std::cout << "   /,`.-'`'    -.  ;-;;,_" << std::endl;
	std::cout << "  |,4-  ) )-,_..; \\ (  `'-'" << std::endl;
	std::cout << " '---''(_/--'  `-'\\_)" << std::endl;
	std::cout << std::endl;

	std::cout << "ScavTrap: " << this->getName() << " is dead!" << std::endl;
}

void ScavTrap::printNoEnergy(void) const
{
	std::cout << std::endl;
	std::cout << "   /\\_/\\" << std::endl;
	std::cout << "  ( -ω-)  zzz..." << std::endl;
	std::cout << "  /|   |\\" << std::endl;
	std::cout << " (_|   |_)" << std::endl;
	std::cout << std::endl;

	std::cout << "ScavTrap: " << this->getName()
			  << " doesn't have any energy point!" << std::endl;
}
