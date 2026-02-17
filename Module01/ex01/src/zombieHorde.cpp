/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 00:46:55 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/16 01:29:24 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0)
	{
		throw std::invalid_argument("N must be positive");
	}
	Zombie *zombie_horde = new Zombie[N];
	for (int i = 0; i < N; ++i)
	{
		zombie_horde[i].setName(name);
	}
	return (zombie_horde);
}
