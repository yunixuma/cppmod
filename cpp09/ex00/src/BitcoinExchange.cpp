/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/16 10:53:40 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) \
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
	int			month;
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
		if (pair.second < 0) {
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
		month = DateConverter::yyyymmdd2yyyymm(pair.first);
		if (monthly_data_.find(month) == monthly_data_.end())
			monthly_data_.insert(std::make_pair(month, MonthlyData(month)));
		if (monthly_data_.find(month)->second.addData(pair) == false) {
			throw DuplicateDataException();
			// std::cout << "\033[31m!!! Error: Bad data format !!!\033[m" << std::endl;
			// return (false);
		}
	}
	if (this->monthly_data_.empty())
		throw EmptyDataException();
	// return (true);
}

void	BitcoinExchange::exchange(int date, float amount) const {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<BitcoinExchange> exchange(" \
		<< date << ", " << amount << ") called\033[m" << std::endl;
	if (!DateConverter::valid(date))
		throw std::invalid_argument(std::string("Error: bad input => ") + DateConverter::yyyymmdd2iso(date));
	else if (amount < 0)
		throw NotPositiveException();
	else if (amount > TOO_LARGE_AMOUNT)
		throw TooLargeException();
	int		month = DateConverter::yyyymmdd2yyyymm(date);
	int		day = DateConverter::yyyymmdd2dd(date);
	float	price = getPrice(month, day);
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

float	BitcoinExchange::getPrice(int month, int day) const {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<BitcoinExchange> getPrice(" \
		<< month << ", " << day << ") called\033[m" << std::endl;
	float	price = INVALID_AMOUNT;
	while (month > 0 && price == INVALID_AMOUNT) {
		if (this->monthly_data_.find(month) != this->monthly_data_.end())
			price = this->monthly_data_.find(month)->second.getPrice(day);
		month = DateConverter::getPrevMonth(month);
		day = 31;
	}
	return (price);
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
	return ("Error: No price data.");
}

const char*	BitcoinExchange::OtherException::what(void) const throw() {
/*	std::clog << "\033[35;3m[" << this \
		<< "]<BitcoinExchange::OtherException> what() called\033[m" \
		<< std::endl;*/
	return (NULL);
}
