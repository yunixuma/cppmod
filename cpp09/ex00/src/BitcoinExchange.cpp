/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/12 21:56:12 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& filepath) \
	: monthly_data_() {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<BitcoinExchange> Constructor called" \
		<< "\033[m" << std::endl;
	(void)filepath;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) \
	: monthly_data_(src.monthly_data_) {
	std::clog << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<BitcoinExchange> Copy constructor called" \
		<< "\033[m" << std::endl;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& rhs) {
	std::clog << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<BitcoinExchange> Copy assignment operator called" \
		<< "\033[m" << std::endl;
	if (this != &rhs)
	{
		this->monthly_data_ = rhs.monthly_data_;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void) {
	std::clog << "\033[31;2;3m[" << this \
		<< "]<BitcoinExchange> Destructor called\033[m" << std::endl;
}

void	BitcoinExchange::exchange(int date, float amount) const {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<BitcoinExchange> exchange(" \
		<< date << ", " << amount << ") called\033[m" << std::endl;
	int		month = DateConverter::yyyymmdd2yyyymm(date);
	int		day = DateConverter::yyyymmdd2dd(date);
	float	price = getPrice(month, day);
	std::cout << month / 100 << "-" << month % 100 << "-" << day << " => ";
	if (price == INVALID_AMOUNT)
		std::cout << "No data" << std::endl;
	else
		std::cout << amount << " = " << price * amount << std::endl;
	// throw NotPositiveException();
	// throw std::invalid_argument("Error: not a positive number.");
}

float	BitcoinExchange::getPrice(int month, int day) const {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<BitcoinExchange> getPrice(" \
		<< month << ", " << day << ") called\033[m" << std::endl;
	float	price = INVALID_AMOUNT;
	while (month > 0 && price == INVALID_AMOUNT) {
		price = this->monthly_data_.find(month)->second.getPrice(day);
		month = DateConverter::getPrevMonth(month);
	}
	return (price);
}

// When an exception thrown
// const char*	BitcoinExchange::InvalidFormatException::what(void) const throw() {
const char*	BitcoinExchange::InvalidFormatException::invalid_argument(std::string& line) const throw() {
/*	std::clog << "\033[35;3m[" << this \
		<< "]<BitcoinExchange::InvalidFormatException> what() called\033[m" \
		<< std::endl;*/
	return ((std::string("Error: bad data => ") + line).c_str());
}

const char*	BitcoinExchange::InvalidDateException::invalid_argument(std::string& s_date) const throw() {
/*	std::clog << "\033[35;3m[" << this \
		<< "]<BitcoinExchange::InvalidDateException> what() called\033[m" \
		<< std::endl;*/
	return ((std::string("Error: bad data =>) ") + s_date).c_str());
}

const char*	BitcoinExchange::NotPositiveException::what(void) const throw() {
/*	std::clog << "\033[35;3m[" << this \
		<< "]<BitcoinExchange::InvalidFormatException> what() called\033[m" \
		<< std::endl;*/
	return ("Error: not a positive number.");
}

const char*	BitcoinExchange::TooLargeException::what(void) const throw() {
/*	std::clog << "\033[35;3m[" << this \
		<< "]<BitcoinExchange::InvalidFormatException> what() called\033[m" \
		<< std::endl;*/
	return ("Error: too large a number.");
}
