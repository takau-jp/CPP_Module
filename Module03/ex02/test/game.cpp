/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 18:30:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/14 18:44:46 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

#include "Game.hpp"

static int getTeamSize(const std::string &team_name);
static std::string hpBar(unsigned int hp, unsigned int max_hp);

void game(void)
{
	try
	{
		int scav_count = getTeamSize("Scav");
		if (scav_count < 0)
		{
			std::cout << std::endl;
			return;
		}
		int frag_count = getTeamSize("Frag");
		if (frag_count < 0)
		{
			std::cout << std::endl;
			return;
		}
		Game g(scav_count, frag_count);
		g.run();
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

static int getTeamSize(const std::string &team_name)
{
	std::string input;
	while (true)
	{
		std::cout << "Team " << team_name
				  << " size? (1-5, Enter for default=1): ";
		if (!std::getline(std::cin, input))
		{
			if (std::cin.eof())
				return (-1);
			else
				throw std::ios_base::failure("Failed to input.");
		}
		if (input.empty() || input == "1")
			return (1);
		else if (input == "2")
			return (2);
		else if (input == "3")
			return (3);
		else if (input == "4")
			return (4);
		else if (input == "5")
			return (5);
	}
}

Game::Game(int scav_count, int frag_count)
	: _scavs(NULL), _frags(NULL), _scav_count(scav_count), _frag_count(frag_count)
{
	try
	{
		_scavs = new ScavTrap*[scav_count];
		for (int i = 0; i < scav_count; ++i)
			_scavs[i] = NULL;

		_frags = new FragTrap*[frag_count];
		for (int i = 0; i < frag_count; ++i)
			_frags[i] = NULL;

		for (int i = 0; i < scav_count; ++i)
		{
			std::stringstream ss;
			ss << i;
			_scavs[i] = new ScavTrap("Scav" + ss.str());
		}
		for (int i = 0; i < frag_count; ++i)
		{
			std::stringstream ss;
			ss << i;
			_frags[i] = new FragTrap("Frag" + ss.str());
		}
	}
	catch (...)
	{
		if (_scavs != NULL)
		{
			for (int i = 0; i < scav_count; ++i)
				delete _scavs[i];
			delete[] _scavs;
		}
		if (_frags != NULL)
		{
			for (int i = 0; i < frag_count; ++i)
				delete _frags[i];
			delete[] _frags;
		}
		throw;
	}
}

Game::~Game()
{
	for (int i = 0; i < _scav_count; ++i)
		delete _scavs[i];
	delete[] _scavs;
	for (int i = 0; i < _frag_count; ++i)
		delete _frags[i];
	delete[] _frags;
}

void Game::run()
{
	srand(std::time(NULL));

	std::cout << "\n=== Battle Start! ===" << std::endl;
	printStatus();

	int turn = 1;
	while (!isOver())
	{
		std::cout << "======================================== "
				  << "TURN " << turn++
				  << " ========================================" << std::endl;
		if (!scavTurn())
			break;
		std::cout << std::endl;
		printStatus();
		std::cout << std::endl;
		if (!fragTurn())
			break;
		std::cout << std::endl;
		printStatus();
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Game::printStatus() const
{
	std::cout << "========== Team Scav ==========" << std::endl;
	for (int i = 0; i < _scav_count; ++i)
	{
		unsigned int hp = _scavs[i]->getHitPoints();
		std::cout << " " << std::setw(6) << _scavs[i]->getName() << "  HP "
				  << std::setw(3) << hp << " [" << hpBar(hp, 100) << "]"
				  << "  EP " << std::setw(2) << _scavs[i]->getEnergyPoints()
				  << (hp == 0 ? "  [DEAD]" : "") << std::endl;
	}
	std::cout << "========== Team Frag ==========" << std::endl;
	for (int i = 0; i < _frag_count; ++i)
	{
		unsigned int hp = _frags[i]->getHitPoints();
		std::cout << " " << std::setw(6) << _frags[i]->getName() << "  HP "
				  << std::setw(3) << hp << " [" << hpBar(hp, 100) << "]"
				  << "  EP " << std::setw(2) << _frags[i]->getEnergyPoints()
				  << (hp == 0 ? "  [DEAD]" : "") << std::endl;
	}
	std::cout << "=================================" << std::endl;
}

static std::string hpBar(unsigned int hp, unsigned int max_hp)
{
	const unsigned int width = 10;
	std::string bar;

	for (unsigned int i = 0; i < width; i++)
		bar += (i < hp * width / (max_hp ? max_hp : 1)) ? "█" : "-";
	return (bar);
}

bool Game::isOver() const
{
	int alive_team = 0;

	int scav_dead = 0;
	for (int i = 0; i < _scav_count; ++i)
		if (_scavs[i]->getHitPoints() == 0)
			++scav_dead;
	if (scav_dead != _scav_count)
		alive_team++;

	int frag_dead = 0;
	for (int i = 0; i < _frag_count; ++i)
		if (_frags[i]->getHitPoints() == 0)
			++frag_dead;
	if (frag_dead != _frag_count)
		alive_team++;

	return (alive_team <= 1);
}

bool Game::scavTurn(void)
{
	std::string input;
	e_action    action;
	int         actor = rand() % _scav_count;

	std::cout << "[Scav action] Enter: random | 0: attack | 1: beRepaired | 2: "
				 "guardGate | q: exit"
			  << std::endl;
	std::cout << "Scav> ";
	if (!std::cout || !std::getline(std::cin, input))
		return (false);
	std::cout << std::endl;

	if (input == "q")
	{
		std::cout << "EXIT" << std::endl;
		return (false);
	}

	if (input == "0")
		action = ATTACK;
	else if (input == "1")
		action = BE_REPAIRED;
	else if (input == "2")
		action = SPECIAL_ABILITY;
	else
		action = (e_action)(rand() % 3);

	if (action == ATTACK)
	{
		int target = rand() % _frag_count;
		std::cout << _scavs[actor]->getName() << "->attack("
				  << _frags[target]->getName() << ")" << std::endl;
		_scavs[actor]->attack(_frags[target]->getName());
		std::cout << std::endl;
		std::cout << _frags[target]->getName() << "->takeDamage("
				  << _scavs[actor]->getAttackDamage() << ")" << std::endl;
		_frags[target]->takeDamage(_scavs[actor]->getAttackDamage());
	}
	else if (action == BE_REPAIRED)
	{
		unsigned int amount = rand() % 10 + 1;
		std::cout << _scavs[actor]->getName() << "->beRepaired(" << amount << ")"
				  << std::endl;
		_scavs[actor]->beRepaired(amount);
	}
	else
	{
		std::cout << _scavs[actor]->getName() << "->guardGate()" << std::endl;
		_scavs[actor]->guardGate();
	}
	return (true);
}

bool Game::fragTurn(void)
{
	std::string input;
	e_action    action;
	int         actor = rand() % _frag_count;

	std::cout << "[Frag action] Enter: random | 0: attack | 1: beRepaired | 2: "
				 "highFivesGuys | q: exit"
			  << std::endl;
	std::cout << "Frag> ";
	if (!std::cout || !std::getline(std::cin, input))
		return (false);
	std::cout << std::endl;

	if (input == "q")
	{
		std::cout << "EXIT" << std::endl;
		return (false);
	}

	if (input == "0")
		action = ATTACK;
	else if (input == "1")
		action = BE_REPAIRED;
	else if (input == "2")
		action = SPECIAL_ABILITY;
	else
		action = (e_action)(rand() % 3);

	if (action == ATTACK)
	{
		int target = rand() % _scav_count;
		std::cout << _frags[actor]->getName() << "->attack("
				  << _scavs[target]->getName() << ")" << std::endl;
		_frags[actor]->attack(_scavs[target]->getName());
		std::cout << std::endl;
		std::cout << _scavs[target]->getName() << "->takeDamage("
				  << _frags[actor]->getAttackDamage() << ")" << std::endl;
		_scavs[target]->takeDamage(_frags[actor]->getAttackDamage());
	}
	else if (action == BE_REPAIRED)
	{
		unsigned int amount = rand() % 10 + 1;
		std::cout << _frags[actor]->getName() << "->beRepaired(" << amount << ")"
				  << std::endl;
		_frags[actor]->beRepaired(amount);
	}
	else
	{
		std::cout << _frags[actor]->getName() << "->highFivesGuys()" << std::endl;
		_frags[actor]->highFivesGuys();
	}
	return (true);
}
