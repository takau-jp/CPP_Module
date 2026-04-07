/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 23:26:43 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/08 01:17:48 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>
#include <limits>

ClapTrap::ClapTrap()
	: _name("Unknown"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << this->_name << ": Constructor has been called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << this->_name << ": Constructor has been called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << this->_name << ": Destructor has been called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (!isAlive() || !useEnergyPoints())
		return;
	if (this->_attack_damage <= 1)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target
				  << ", causing " << this->_attack_damage << " point of damage!"
				  << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target
				  << ", causing " << this->_attack_damage
				  << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!isAlive())
		return;
	if (this->_hit_points >= amount)
		this->_hit_points -= amount;
	else
		this->_hit_points = 0;
	if (amount <= 1)
	{
		std::cout << "ClapTrap " << this->_name << " takes " << amount
				  << " point of damage!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " takes " << amount
				  << " points of damage!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!isAlive() || !useEnergyPoints())
		return;
	if (std::numeric_limits<unsigned int>::max() - amount >= this->_hit_points)
		this->_hit_points += amount;
	else
		this->_hit_points = std::numeric_limits<unsigned int>::max();
	if (amount <= 1)
	{
		std::cout << "ClapTrap " << this->_name << " repaires " << amount
				  << " point of hit points!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " repaires " << amount
				  << " points of hit points!" << std::endl;
	}
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
	{
		std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
		return (false);
	}
	return (true);
}

bool ClapTrap::useEnergyPoints(void)
{
	if (this->_energy_points == 0)
	{
		std::cout << "ClapTrap " << this->_name
				  << " doesn't have any energy point!" << std::endl;
		return (false);
	}
	this->_energy_points--;
	return (true);
}
