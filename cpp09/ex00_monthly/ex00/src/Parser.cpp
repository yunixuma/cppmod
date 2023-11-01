/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/15 23:17:34 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"
#include <iostream>

char	Parser::searchDelim(std::string& line) {
	size_t	pos;
	pos = line.find_first_of(CHRS_CHR_DELIM);
	if (pos == std::string::npos)
		return (CHR_DELIM);
	return (line[pos]);
}

t_pair	Parser::split2Pair(std::string& line) {
	return (Parser::split2Pair(line, CHR_DELIM));
}

t_pair	Parser::split2Pair(std::string& line, char delim) {
	int			date;
	std::string	s_date;
	std::string	s_amount;
	size_t	left, right;
	left = line.find_first_not_of(" \t");
	right = line.find(delim);
	if (right == std::string::npos)
		throw InvalidFormatException();
	right = line.find_last_not_of(" \t", right - 1);
	// std::clog << "(" << left << ", " << right << ")" << std::endl;
	s_date = line.substr(left, right - left + 1);
	// std::clog << s_date << std::endl;
	date = DateConverter::iso2yyyymmdd(s_date);
	if (date == DATE_INVALID)
		throw DateConverter::InvalidDateException();
	left = line.find(delim, right + 1);
	left = line.find_first_not_of(" \t", left + 1);
	// std::clog << "(left, length) = (" << left << ", " << line.length() << ")" << std::endl;
	if (left == std::string::npos)
		throw InvalidFormatException();
	// if (left >= line.length() - 1)
	// 	throw InvalidFormatException();
	right = line.find_last_not_of(" \t");
	// if (left > right)
	// 	throw InvalidFormatException();
	s_amount = line.substr(left, right - left + 1);
	// std::clog << s_amount << std::endl;
//	return (std::make_pair(DATE_INVALID, INVALID_AMOUNT));
	float				amount;
	std::stringstream	ss;
	ss << s_amount;
	ss >> amount;
	std::clog << s_amount << "\t" << ss.fail() << "\t" << ss.eof() << std::endl;
	if (ss.fail() || !ss.eof())
		throw InvalidFormatException();
		// amount = INVALID_AMOUNT;
	return (std::make_pair(date, amount));
}

// When an exception thrown
const char*	Parser::InvalidFormatException::what(void) const throw() {
// const char*	Parser::InvalidFormatException::invalid_argument(const std::string& line) const throw() {
/*	std::clog << "\033[35;3m[" << this \
		<< "]<BitcoinExchange::InvalidFormatException> what() called\033[m" \
		<< std::endl;*/
	return ("Error: bad input => ");
}
