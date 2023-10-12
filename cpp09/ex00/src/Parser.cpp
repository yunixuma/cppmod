/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/12 23:03:52 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"
#include <iostream>

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
	if (ss.fail() || !ss.eof())
		amount = INVALID_AMOUNT;
	return (std::make_pair(DateConverter::iso2yyyymmdd(s_date), amount));
	
/*	std::string	buf_line_new;
	size_t		len_line = buf_line.length();
	size_t		len_search = s_search.length();
	size_t 	pos = 0;
	size_t 	pos2;

	while (pos < len_line) {
		pos2 = buf_line.find(s_search, pos);
		if (pos2 == std::string::npos)
			break ;
		buf_line_new += buf_line.substr(pos, pos2 - pos);
		buf_line_new += s_replace;
		pos = pos2 + len_search;
	}
	buf_line_new += buf_line.substr(pos, len_line - pos);
	return (buf_line_new);

	if (s_date.empty() || s_date.length() != 10) {
		return (0);
	}
	if (s_date[4] != '-' || s_date[7] != '-') {
		return (0);
	}
	s_date.erase(4, 1);
	s_date.erase(6, 1);

	int					n_date;
	std::stringstream	ss;
	ss << s_date;
	ss >> n_date;
	if (n_date < DATE_LOWER_LIMIT \
		|| DATE_HIGHER_LIMIT < n_date) {
		return (0);
	}
	if (!valid(n_date)) {
		return (0);
	}
	return (n_date);*/
}
