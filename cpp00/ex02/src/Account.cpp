/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2024/11/02 21:36:48 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <climits>
#include <ctime>
#define AMMOUNT_MAX	INT_MAX

Account::Account(void) {
	_nbAccounts = 0;
	_totalAmount = 0;
	_totalNbDeposits = 0;
	_totalNbWithdrawals = 0;
	// std::cout << "\033[36;2;3m[" << this 
		// << "]<Account> Constructor called (" << this->_amount << ")\033[m" << std::endl;
}

Account::Account(int initial_deposit) {
	// std::cout << "\033[36;2;3m[" << this 
		// << "]<Account> Constructor called (" << this->_amount << ")\033[m" << std::endl;
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	if (initial_deposit > AMMOUNT_MAX - _totalAmount) {
		this->_amount = AMMOUNT_MAX - _totalAmount;
		_totalAmount = AMMOUNT_MAX;
	}
	else {
		this->_amount = initial_deposit;
		_totalAmount += initial_deposit;
	}
}

Account::~Account(void) {
	// std::cout << "\033[31;2;3m[" << this 
		// << "]<Account> Destructor called (" << this->_amount << ")\033[m" << std::endl;
	// _nbAccounts--;
	// _totalAmount -= this->_amount;
}

int	Account::getNbAccounts(void) {
	return (_nbAccounts);
}

int	Account::getTotalAmount(void) {
	return (_totalAmount);
}

int	Account::getNbDeposits(void) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void) {
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << \
		";total:" << _totalAmount << \
		";deposits:" << _totalNbDeposits << \
		";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void) {
	time_t	timer;
	time(&timer);
	std::cout << "[" << ctime(&timer) << "]" << std::endl;
}

void	Account::makeDeposit(int deposit) {
	if (this->_amount > AMMOUNT_MAX - deposit)
		return ;
	this->_amount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal) {
	if (this->_amount < withdrawal)
		return (false);
	this->_amount -= withdrawal;
	_totalNbWithdrawals++;
	return (true);
}

int		Account::checkAmount(void) const {
	return (1234);
}

void	Account::displayStatus(void) const {
	std::cout << "Account " << this->_accountIndex << \
		" : " << this->_amount << std::endl;
}
