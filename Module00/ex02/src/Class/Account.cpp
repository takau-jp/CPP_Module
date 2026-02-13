/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 00:09:37 by stanaka2          #+#    #+#             */
/*   Updated: 2026/02/13 11:21:20 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <limits>

const int INVALID_ACCOUNT = -1;
const int LIMIT = std::numeric_limits<int>::max();

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
	std::time_t now = std::time(NULL);
	std::tm *lt = std::localtime(&now);
	char buf[30];
	std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", lt);
	std::cout << buf;
}

Account::Account(void)
	: _accountIndex(_nbAccounts), _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
	if (_nbAccounts == LIMIT)
	{
		_accountIndex = INVALID_ACCOUNT;
		_amount = 0;
		_displayTimestamp();
		std::cout << "index:" << "INVALID_ACCOUNT" << ";"
				  << "created" << std::endl;
		return;
	}

	++_nbAccounts;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << checkAmount() << ";"
			  << "created" << std::endl;
}

Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0),
	  _nbWithdrawals(0)
{
	if (_nbAccounts == LIMIT || checkAmount() < 0 ||
		LIMIT - _totalAmount < checkAmount())
	{
		_accountIndex = INVALID_ACCOUNT;
		_amount = 0;
		_displayTimestamp();
		std::cout << "index:" << "INVALID_ACCOUNT" << ";"
				  << "created" << std::endl;
		return;
	}

	++_nbAccounts;
	_totalAmount += checkAmount();

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << checkAmount() << ";"
			  << "created" << std::endl;
}

Account::~Account(void)
{
	if (_accountIndex == INVALID_ACCOUNT)
	{
		_displayTimestamp();
		std::cout << "index:" << "INVALID_ACCOUNT" << ";"
				  << "closed" << std::endl;
		return;
	}

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << checkAmount() << ";"
			  << "closed" << std::endl;

	--_nbAccounts;
	_totalAmount -= checkAmount();
}

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
			  << "total:" << getTotalAmount() << ";"
			  << "deposits:" << getNbDeposits() << ";"
			  << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit)
{
	if (_accountIndex == INVALID_ACCOUNT)
	{
		_displayTimestamp();
		std::cout << "index:" << "INVALID_ACCOUNT" << ";"
				  << "deposit:" << "refused" << std::endl;
		return;
	}

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "p_amount:" << _amount << ";";

	if (LIMIT - _totalAmount < deposit || LIMIT == _totalNbDeposits ||
		deposit <= 0)
	{
		std::cout << "deposit:" << "refused" << std::endl;
		return;
	}

	_amount += deposit;
	_totalAmount += deposit;
	++_nbDeposits;
	++_totalNbDeposits;

	std::cout << "deposit:" << deposit << ";"
			  << "amount:" << _amount << ";"
			  << "nb_deposits:" << _nbDeposits << std::endl;

	return;
}

bool Account::makeWithdrawal(int withdrawal)
{
	if (_accountIndex == INVALID_ACCOUNT)
	{
		_displayTimestamp();
		std::cout << "index:" << "INVALID_ACCOUNT" << ";"
				  << "withdrawal:" << "refused" << std::endl;
		return (false);
	}

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "p_amount:" << _amount << ";";

	if (_amount < withdrawal || LIMIT == _totalNbWithdrawals || withdrawal <= 0)
	{
		std::cout << "withdrawal:" << "refused" << std::endl;
		return (false);
	}

	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	++_nbWithdrawals;
	++_totalNbWithdrawals;

	std::cout << "withdrawal:" << withdrawal << ";"
			  << "amount:" << _amount << ";"
			  << "nb_withdrawals:" << _nbWithdrawals << std::endl;

	return (true);
}

int Account::checkAmount(void) const
{
	if (_accountIndex == INVALID_ACCOUNT)
		return (0);

	return (_amount);
}

void Account::displayStatus(void) const
{
	if (_accountIndex == INVALID_ACCOUNT)
	{
		_displayTimestamp();
		std::cout << "index:" << "INVALID_ACCOUNT" << ";"
				  << "display:" << "refused" << std::endl;
		return;
	}

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << checkAmount() << ";"
			  << "deposits:" << _nbDeposits << ";"
			  << "withdrawals:" << _nbWithdrawals << std::endl;
}
