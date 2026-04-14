/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 18:30:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/14 18:30:00 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

enum e_action
{
	ATTACK,
	BE_REPAIRED,
	SPECIAL_ABILITY,
	RANDOM
};

class Game
{
  private:
	ScavTrap **_scavs;
	FragTrap **_frags;
	int        _scav_count;
	int        _frag_count;

	void printStatus() const;
	bool isOver() const;
	bool scavTurn(void);
	bool fragTurn(void);

  public:
	Game(int scav_count, int frag_count);
	~Game();
	void run();
};

#endif
