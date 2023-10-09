/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/09 15:50:20 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

t_pair	Parser::split(std::string& line) {
	return (Parser::split(line, DELIM));
}

t_pair	Parser::split(std::string& line, char delim) {
	(void)line;
	(void)delim;
	return (std::make_pair(0, 0.0f));
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
