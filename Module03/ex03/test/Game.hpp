/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 00:00:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/14 00:00:00 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

# include "DiamondTrap.hpp"

enum e_action
{
	ATTACK,
	BE_REPAIRED,
	WHO_AM_I,
	GUARD_GATE,
	HIGH_FIVES,
	RANDOM
};

class Game
{
  private:
	DiamondTrap **_diamonds;
	int           _count;

	void printStatus() const;
	bool isOver() const;
	bool doTurn(void);

  public:
	Game(int count);
	~Game();
	void run();
};

void game(void);

#endif
