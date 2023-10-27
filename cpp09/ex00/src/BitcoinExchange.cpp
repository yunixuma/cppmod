/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/27 10:46:31 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) \
	: prices_() {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<BitcoinExchange> Constructor called" \
		<< "\033[m" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) \
	: prices_(src.prices_) {
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
		this->prices_ = rhs.prices_;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void) {
	std::clog << "\033[31;2;3m[" << this \
		<< "]<BitcoinExchange> Destructor called\033[m" << std::endl;
}

void	BitcoinExchange::openData(const std::string& filepath) {
// bool	BitcoinExchange::openData(const std::string& filepath) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<BitcoinExchange> openData called" \
		<< "\033[m" << std::endl;
	std::ifstream 	ifs;
	try {
		ifs.open(filepath.c_str(), std::ios::in | std::ios::binary);
		if (ifs) {
			char	c;
			ifs.read(&c, 1);
			ifs.seekg(0, ifs.beg);
		}
		if (ifs.fail()) {
			throw (std::exception());
		}
	}
	catch (const std::exception& e) {
		// std::cout << "\033[31m" << e.what() << "\033[m" << std::endl;
		// std::cout << "\033[31m!!! Error occurs while opening the data file. !!!\033[m" << std::endl;
		std::cout << "\033[31mError: could not open file.\033[m" << std::endl;
		throw (e);
		// return (false);
	}
	
	try {
		addData(ifs);
	}
	catch (const std::exception& e) {
		ifs.close();
		if (e.what() != NULL)
			std::cout << "\033[31m" << e.what() << "\033[m" << std::endl;
		throw (e);
		// return (false);
	}
	ifs.close();
	// return (status);
}

void	BitcoinExchange::addData(std::ifstream& ifs) {
	char		delim;
	std::string	line;
	t_pair		pair;

	std::getline (ifs, line);
	delim = Parser::searchDelim(line);
	while (std::getline (ifs, line)) {
		try {
			pair = Parser::split2Pair(line, delim);
		}
		catch (std::exception& e) {
			std::cout << "\033[31m" << e.what() << line << "\033[m" << std::endl;
			throw OtherException();
			// return (false);
		}
		if (!DateConverter::valid(pair.first)) {
			std::cout << "\033[31m" << "Error: invalid date => " << line << "\033[m" << std::endl;
			throw (DateConverter::InvalidDateException());
			// return (false);
		}
		if (pair.second < LOWER_LIMIT_AMOUNT) {
			std::cout << "\033[31m" << "Error: invalid price => " << line << "\033[m" << std::endl;
			throw (OtherException());
			// return (false);
		}
		// std::clog << "{" << pair.first << "}, {" << pair.second << "}" << std::endl;
		// if (pair.first < DATE_LOWER_LIMIT || DATE_HIGHER_LIMIT < pair.first) {
		// 	throw DateConverter::InvalidDateException();
		// 	// std::cout << "\033[31m!!! Error: Bad date format !!!\033[m" << std::endl;
		// 	// return (false);
		// }
		if (prices_.insert(std::make_pair<int, float>(pair.first, pair.second)).second \
			== false)
			throw DuplicateDataException();
	}
	if (this->prices_.empty())
		throw EmptyDataException();
	// return (true);
}

void	BitcoinExchange::exchange(int date, float amount) const {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<BitcoinExchange> exchange(" \
		<< date << ", " << amount << ") called\033[m" << std::endl;
	if (!DateConverter::valid(date))
		throw std::invalid_argument(std::string("Error: bad input => ") + DateConverter::yyyymmdd2iso(date));
	else if (amount < LOWER_LIMIT_AMOUNT)
		throw NotPositiveException();
	else if (amount > HIGHER_LIMIT_AMOUNT)
		throw TooLargeException();
	float	price = getPrice(date);
	std::cout << DateConverter::yyyymmdd2iso(date) << " => ";
	if (price == INVALID_AMOUNT)
		std::cout << "No data" << std::endl;
	else
		std::cout << amount << " = " << price * amount << std::endl;
	// throw NotPositiveException();
	// throw std::invalid_argument("Error: not a positive number.");
}

void	BitcoinExchange::exchange(t_pair& pair) const {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<BitcoinExchange> exchange(" \
		<< "pair" << ") called\033[m" << std::endl;
	try {
		exchange(pair.first, pair.second);
	}
	// catch (const std::invalid_argument& e) {
	// 	std::cout << e.what() << std::endl;
	// }
	catch (const std::exception& e) {
		std::cout << "\033[33m" << e.what() << "\033[m" << std::endl;
	}
}

float	BitcoinExchange::getPrice(int date) const {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<BitcoinExchange> getPrice(" \
		<< date << ") called\033[m" << std::endl;
	std::map<int, float>::const_iterator	it = this->prices_.lower_bound(date);
	if (it->first != date) {
		if (it == this->prices_.begin())
			return (INVALID_AMOUNT);
		it--;
	}
	return (it->second);
}

// When an exception thrown
const char*	BitcoinExchange::DuplicateDataException::what(void) const throw() {
/*	std::clog << "\033[35;3m[" << this \
		<< "]<BitcoinExchange::DuplicateDataException> what() called\033[m" \
		<< std::endl;*/
	return ("Error: duplicate data");
}
const char*	BitcoinExchange::NotPositiveException::what(void) const throw() {
/*	std::clog << "\033[35;3m[" << this \
		<< "]<BitcoinExchange::NotPositiveException> what() called\033[m" \
		<< std::endl;*/
	return ("Error: not a positive number.");
}

const char*	BitcoinExchange::TooLargeException::what(void) const throw() {
// const char*	BitcoinExchange::TooLargeException::out_of_range(void) const throw() {
/*	std::clog << "\033[35;3m[" << this \
		<< "]<BitcoinExchange::InvalidFormatException> what() called\033[m" \
		<< std::endl;*/
	return ("Error: too large number.");
}

const char*	BitcoinExchange::EmptyDataException::what(void) const throw() {
/*	std::clog << "\033[35;3m[" << this \
		<< "]<BitcoinExchange::EmptyDataException> what() called\033[m" \
		<< std::endl;*/
	return ("Error: no price data.");
}

const char*	BitcoinExchange::OtherException::what(void) const throw() {
/*	std::clog << "\033[35;3m[" << this \
		<< "]<BitcoinExchange::OtherException> what() called\033[m" \
		<< std::endl;*/
	return (NULL);
}
