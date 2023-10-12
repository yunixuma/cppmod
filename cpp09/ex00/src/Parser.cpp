/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/12 22:15:27 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

t_pair	Parser::split2Pair(std::string& line) {
	return (Parser::split2Pair(line, DELIM));
}

t_pair	Parser::split2Pair(std::string& line, char delim) {
	(void)delim;
	(void)line;
	std::string	s_date = "2021-10-12";
	std::string	s_amount = "3.1415926";
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
