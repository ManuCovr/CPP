/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maga <mde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 14:31:38 by mde-maga          #+#    #+#             */
/*   Updated: 2025/08/26 10:33:11 by mde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <iomanip>

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit): \
				_accountIndex(_nbAccounts), \
				_amount(initial_deposit), \
				_nbDeposits(0), \
				_nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << " index:" << this->_nbAccounts - 1 \
	<< ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account()
{
	_nbAccounts--;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex \
	<< ";amount:" << this->_amount << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	int	previous_amount;

	previous_amount = this->_amount;
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_nbDeposits++;
	this->_totalNbDeposits++;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex \
	<< ";p_amount:" << previous_amount \
	<< ";deposit:" << deposit \
	<< ";amount:" << this->_amount \
	<< ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	int previous_amount;

	previous_amount = this->_amount;
	if (this->_amount < withdrawal)
	{
		_displayTimestamp();
		std::cout << " index:" << this->_accountIndex \
		<< ";p_amount:" << previous_amount \
		<< ";withdrawal:refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	this->_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	this->_totalNbWithdrawals++;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex \
		<< ";p_amount:" << previous_amount \
		<< ";withdrawal:" << withdrawal \
		<< ";amount:" << this->_amount \
		<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int Account::checkAmount() const
{
	return (this->_amount);
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex \
	<< ";amount:" << this->_amount \
	<< ";deposits:" << this->_nbDeposits \
	<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts \
	<< ";total:" << _totalAmount \
	<< ";deposits:" << _totalNbDeposits \
	<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::_displayTimestamp()
{
	std::time_t	now;
	std::tm		*timeInfo;

	now = std::time(NULL);
	timeInfo = std::localtime(&now);

	std::cout << "[" << (timeInfo->tm_year + 1900)
			  << std::setw(2) << std::setfill('0') << (timeInfo->tm_mon + 1)
			  << std::setw(2) << std::setfill('0') << timeInfo->tm_mday
			  << "_" << std::setw(2) << std::setfill('0') << timeInfo->tm_hour
			  << std::setw(2) << std::setfill('0') << timeInfo->tm_min
			  << std::setw(2) << std::setfill('0') << timeInfo->tm_sec
			  << "]";
}

int Account::getNbAccounts()
{
	return (_nbAccounts);
}

int Account::getTotalAmount()
{
	return (_totalAmount);
}

int Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}