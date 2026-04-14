/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 19:13:39 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/14 17:25:22 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

enum e_action
{
	ATTACK,
	BE_REPAIRED,
	SPECIAL_ABILITY,
	RANDOM
};

enum e_team_type
{
	CLAP_TEAM,
	SCAV_TEAM
};

class Game
{
  private:
	ClapTrap **_claps;
	ScavTrap **_scavs;
	int       _clap_count;
	int       _scav_count;

	void printStatus() const;
	bool isOver() const;
	bool clapTurn(void);
	bool scavTurn(void);

  public:
	Game(int clap_count, int scav_count);
	~Game();
	void run();
};

#endif
