/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 22:41:42 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/02 20:40:37 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
  private:
	void printDead(void) const;
	void printNoEnergy(void) const;

  protected:
	static const unsigned int default_hit_points = 100;
	static const unsigned int default_energy_points = 50;
	static const unsigned int default_attack_damage = 20;

  public:
	ScavTrap();
	explicit ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &other);
	ScavTrap &operator=(const ScavTrap &other);
	virtual ~ScavTrap();

	void attack(const std::string &target);
	void guardGate();
};

#endif
