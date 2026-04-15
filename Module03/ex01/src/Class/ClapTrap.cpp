/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 23:26:43 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/15 23:24:40 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>
#include <limits>

ClapTrap::ClapTrap()
	: _name("Unknown"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap: " << this->_name
			  << ": Default constructor has been called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
	: _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap: " << this->_name << ": Constructor has been called"
			  << std::endl;
}

ClapTrap::ClapTrap(const std::string &name, unsigned int hit_points,
				   unsigned int energy_points, unsigned int attack_damage)
	: _name(name), _hit_points(hit_points), _energy_points(energy_points),
	  _attack_damage(attack_damage)
{
	std::cout << "ClapTrap: " << this->_name << ": Constructor has been called"
			  << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
	: _name(other._name), _hit_points(other._hit_points),
	  _energy_points(other._energy_points), _attack_damage(other._attack_damage)
{
	std::cout << "ClapTrap: " << this->_name
			  << ": Copy constructor has been called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hit_points = other._hit_points;
		this->_energy_points = other._energy_points;
		this->_attack_damage = other._attack_damage;
	}

	std::cout << "ClapTrap: " << this->_name
			  << ": Copy assignment operator has been called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap: " << this->_name << ": Destructor has been called"
			  << std::endl;
}

void ClapTrap::attack(const std::string &target)
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

	std::cout << "ClapTrap: " << this->_name << " attacks " << target
			  << ", causing " << this->_attack_damage;
	if (this->_attack_damage <= 1)
		std::cout << " point of damage!" << std::endl;
	else
		std::cout << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!isAlive())
	{
		printDead();
		return;
	}

	loseHitPoints(amount);

	std::cout << std::endl;
	std::cout << "   /\\_/\\" << std::endl;
	std::cout << "  ( ;ω; )  * OUCH!" << std::endl;
	std::cout << "  /|  |\\" << std::endl;
	std::cout << " (_|  |_)" << std::endl;
	std::cout << std::endl;

	std::cout << "ClapTrap: " << this->_name << " takes " << amount;
	if (amount <= 1)
		std::cout << " point of damage!" << std::endl;
	else
		std::cout << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
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

	gainHitPoints(amount);

	std::cout << std::endl;
	std::cout << "   /\\_/\\" << std::endl;
	std::cout << "  ( ^ω^ )  purr..." << std::endl;
	std::cout << "  /| + |\\" << std::endl;
	std::cout << " (_|   |_)" << std::endl;
	std::cout << std::endl;

	std::cout << "ClapTrap: " << this->_name << " repaires " << amount;
	if (amount <= 1)
		std::cout << " point of hit points!" << std::endl;
	else
		std::cout << " points of hit points!" << std::endl;
}

const std::string &ClapTrap::getName(void) const
{
	return (this->_name);
}

unsigned int ClapTrap::getHitPoints(void) const
{
	return (this->_hit_points);
}

unsigned int ClapTrap::getEnergyPoints(void) const
{
	return (this->_energy_points);
}

unsigned int ClapTrap::getAttackDamage(void) const
{
	return (this->_attack_damage);
}

bool ClapTrap::isAlive(void) const
{
	if (this->_hit_points == 0)
		return (false);
	return (true);
}

void ClapTrap::printDead(void) const
{
	std::cout << std::endl;
	std::cout << "   |\\ _,,,---,,_" << std::endl;
	std::cout << "   /,`.-'`'    -.  ;-;;,_" << std::endl;
	std::cout << "  |,4-  ) )-,_..; \\ (  `'-'" << std::endl;
	std::cout << " '---''(_/--'  `-'\\_)" << std::endl;
	std::cout << std::endl;

	std::cout << "ClapTrap: " << this->_name << " is dead!" << std::endl;
}

bool ClapTrap::useEnergyPoints(void)
{
	if (this->_energy_points == 0)
		return (false);
	this->_energy_points--;
	return (true);
}

void ClapTrap::printNoEnergy(void) const
{
	std::cout << std::endl;
	std::cout << "   /\\_/\\" << std::endl;
	std::cout << "  ( -ω-)  zzz..." << std::endl;
	std::cout << "  /|   |\\" << std::endl;
	std::cout << " (_|   |_)" << std::endl;
	std::cout << std::endl;

	std::cout << "ClapTrap: " << this->_name
			  << " doesn't have any energy point!" << std::endl;
}

void ClapTrap::loseHitPoints(unsigned int amount)
{
	if (this->_hit_points >= amount)
		this->_hit_points -= amount;
	else
		this->_hit_points = 0;
}

void ClapTrap::gainHitPoints(unsigned int amount)
{
	if (std::numeric_limits<unsigned int>::max() - amount >= this->_hit_points)
		this->_hit_points += amount;
	else
		this->_hit_points = std::numeric_limits<unsigned int>::max();
}
