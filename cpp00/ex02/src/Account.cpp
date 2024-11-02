/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2024/11/02 23:49:19 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <climits>
#include <ctime>
#define AMMOUNT_MAX	INT_MAX

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(void) {
	// _nbAccounts = 0;
	// _totalAmount = 0;
	// _totalNbDeposits = 0;
	// _totalNbWithdrawals = 0;
	// std::cout << "\033[36;2;3m[" << this 
		// << "]<Account> Constructor called (" << this->_amount << ")\033[m" << std::endl;
}

Account::Account(int initial_deposit) {
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
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex \
		<< ";amount:" << this->_amount \
		<< ";created" << std::endl;
}

Account::~Account(void) {
	// std::cout << "\033[31;2;3m[" << this 
		// << "]<Account> Destructor called (" << this->_amount << ")\033[m" << std::endl;
	// _nbAccounts--;
	// _totalAmount -= this->_amount;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex \
		<< ";amount:" << this->_amount \
		<< ";closed" << std::endl;
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
	std::cout << " accounts:" << _nbAccounts << \
		";total:" << _totalAmount << \
		";deposits:" << _totalNbDeposits << \
		";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void) {
    // Get the current time
    std::time_t now = std::time(0);
    // Convert to local time structure
    std::tm *localTime = std::localtime(&now);
    // Prepare a buffer to hold the formatted time
    char buffer[20]; // Sufficient size for "yyyyMMdd_hhmmss\0"
    // Format the time
    std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", localTime);
    // Output the formatted time
    std::cout << "[" << buffer << "]";
}

void	Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex \
		<< ";p_amount:" << this->_amount \
		<< ";deposit:";
	if (this->_amount > AMMOUNT_MAX - deposit)
		std::cout << "refused" << std::endl;
	else {
		this->_amount += deposit;
		this->_nbDeposits++;
		_totalNbDeposits++;
		_totalAmount += deposit;
		std::cout << deposit \
			<< ";amount:" << this->_amount \
			<< ";nb_deposits:" << this->_nbDeposits << std::endl;
	}
}

bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex \
		<< ";p_amount:" << this->_amount \
		<< ";withdrawal:";
	if (this->_amount < withdrawal)
		std::cout << "refused" << std::endl;
	else {
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		std::cout << withdrawal \
			<< ";amount:" << this->_amount \
			<< ";nb_withdrawals:" << this->_nbDeposits << std::endl;
	}
		return (false);
	this->_amount -= withdrawal;
	_totalNbWithdrawals++;
	return (true);
}

int		Account::checkAmount(void) const {
	return (this->_amount);
}

void	Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex \
		<< ";amount:" << this->_amount \
		<< ";deposits:" << this->_nbDeposits \
		<< ";withdrawals:" << this->_nbWithdrawals \
		<< std::endl;
}
