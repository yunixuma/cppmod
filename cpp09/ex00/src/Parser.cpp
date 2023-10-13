/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/13 19:58:15 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"
#include <iostream>

char	Parser::searchDelim(std::string& line) {
	size_t	pos;
	pos = line.find_first_of(DELIMS);
	if (pos == std::string::npos)
		return (DELIM);
	return (line[pos]);
}

t_pair	Parser::split2Pair(std::string& line) {
	return (Parser::split2Pair(line, DELIM));
}

t_pair	Parser::split2Pair(std::string& line, char delim) {
	(void)delim;
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
	left = line.find(delim, right + 1);
	left = line.find_first_not_of(" \t", left + 1);
	right = line.find_last_not_of(" \t");
	// std::clog << "(" << left << ", " << right << ")" << std::endl;
	s_amount = line.substr(left, right - left + 1);
	// std::clog << s_amount << std::endl;
//	return (std::make_pair(DATE_INVALID, INVALID_AMOUNT));
	float				amount;
	std::stringstream	ss;
	ss << s_amount;
	ss >> amount;
	std::clog << s_amount << "\t" << ss.fail() << "\t" << ss.eof() << std::endl;
	if (ss.fail() || !ss.eof())
		amount = INVALID_AMOUNT;
	return (std::make_pair(DateConverter::iso2yyyymmdd(s_date), amount));
}

// When an exception thrown
const char*	Parser::InvalidFormatException::what(void) const throw() {
// const char*	Parser::InvalidFormatException::invalid_argument(const std::string& line) const throw() {
/*	std::clog << "\033[35;3m[" << this \
		<< "]<BitcoinExchange::InvalidFormatException> what() called\033[m" \
		<< std::endl;*/
	return ("Error: bad input => ");
}
