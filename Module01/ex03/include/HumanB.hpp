/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:08:16 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/16 17:15:53 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB
{
  private:
	const std::string name;
	Weapon *weapon;

  public:
	HumanB(const std::string &name);
	~HumanB();
	void setWeapon(Weapon &weapon);
	void attack() const;
};

#endif
