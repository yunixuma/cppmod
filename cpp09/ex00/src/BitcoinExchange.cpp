/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/09 03:56:38 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& filepath) \
	: monthly_data_() {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<BitcoinExchange> Constructor called" \
		<< "\033[m" << std::endl;
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
		<< date ", " << amount << ") called\033[m" << std::endl;
	int		month = DateConverter.yyyymmdd2yyyymm(date);
	int		day = DateConverter.yyyymmdd2dd(date);
	float	price = getPrice(month, day);
	std::cout << month / 100 << "-" << month % 100 << "-" << day << " => ";
	if (price == INVALID_PRICE) {
		std::cout << "No data" << std::endl;
	else
		std::cout << amount << " = " << price * amount << std::endl;
}

float	BitcoinExchange::getPrice(int month, int day) const {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<BitcoinExchange> getPrice(" \
		<< month ", " << day << ") called\033[m" << std::endl;
	float	price = INVALID_PRICE;
	while (month > 0 && price == INVALID_PRICE) {
		price = this->monthly_data_.find(month)->second.getPrice(day);
		month = DateConverter.prevMonth(month);
	}
	return (price);
}

int	BitcoinExchange::getGrade(void) const {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<BitcoinExchange> getGrade() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	return (this->grade_);
}

void	BitcoinExchange::incrementGrade(void) {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<BitcoinExchange> incrementGrade() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	this->grade_--;
	// if (this->grade_ > 150)
	// 	throw BitcoinExchange::GradeTooLowException();
	if (this->grade_ < 1)
		throw BitcoinExchange::GradeTooHighException();
	// if (this->grade_ > 150)
	// 	throw std::range_error("The grade too low");
	// else if (this->grade_ < 1)
	// 	throw std::range_error("The grade too high");
}

void	BitcoinExchange::decrementGrade(void) {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<BitcoinExchange> decrementGrade() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	this->grade_++;
	if (this->grade_ > 150)
		throw BitcoinExchange::GradeTooLowException();
	// else if (this->grade_ < 1)
	// 	throw BitcoinExchange::GradeTooHighException();
	// if (this->grade_ > 150)
	// 	throw std::range_error("The grade too low");
	// else if (this->grade_ < 1)
	// 	throw std::range_error("The grade too high");
}

// When an exception thrown
const char*	BitcoinExchange::InvalidDateException::what(std::string& s_date) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<BitcoinExchange::InvalidDateException> what() called\033[m" << std::endl;
	return ("Error: bad data => " + s_date);
}

const char*	BitcoinExchange::InvalidFormatException::what(std::string& line) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<BitcoinExchange::InvalidFormatException> what() called\033[m" << std::endl;
	return ("Error: bad data => " + s_date);
}

const char*	BitcoinExchange::NotPositiveException::what(void) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<BitcoinExchange::InvalidFormatException> what() called\033[m" << std::endl;
	return ("Error: not a positive number.");
}

const char*	BitcoinExchange::TooLargeException::what(void) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<BitcoinExchange::InvalidFormatException> what() called\033[m" << std::endl;
	return ("Error: too large a number.");
}
