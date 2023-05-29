/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/29 15:56:32 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.h"

std::string sed_line(std::string buf_line, std::string s_search, std::string s_replace) {
	std::string	buf_line_new;
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
}
