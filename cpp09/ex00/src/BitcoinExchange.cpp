/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/08 18:00:11 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& filepath) \
	: monthlyData_() {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<BitcoinExchange> Constructor called" \
		<< "\033[m" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) \
	: monthlyData_(src.monthlyData_) {
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
		this->monthlyData_ = rhs.name_;
		this->grade_ = rhs.grade_;
	}
	if (this->grade_ > 150)
		throw BitcoinExchange::GradeTooLowException();
	else if (this->grade_ < 1)
		throw BitcoinExchange::GradeTooHighException();
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void) {
	std::clog << "\033[31;2;3m[" << this \
		<< "]<BitcoinExchange> Destructor called (" \
		<< this->name_ << ")\033[m" << std::endl;
}

const std::string&	BitcoinExchange::getName(void) const {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<BitcoinExchange> getName() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	return (this->name_);
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
