/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 20:32:55 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/14 19:31:31 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <string>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
  private:
	std::string _name;
	void printDead(void) const;
	void printNoEnergy(void) const;

	static const unsigned int default_hit_points = FragTrap::default_hit_points;
	static const unsigned int default_energy_points =
		ScavTrap::default_energy_points;
	static const unsigned int default_attack_damage =
		FragTrap::default_attack_damage;

  public:
	DiamondTrap();
	explicit DiamondTrap(const std::string &name);
	DiamondTrap(const DiamondTrap &other);
	DiamondTrap &operator=(const DiamondTrap &other);
	virtual ~DiamondTrap();

	using ScavTrap::attack;
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void whoAmI();
	const std::string &getName(void) const;
};

#endif
