/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/13 01:24:26 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
# define PARSER_HPP

# include <sstream>
# include <string>
# include "btc.hpp"
# include "DateConverter.hpp"

# define DELIM	','

class Parser
{
private:
	Parser();
	~Parser();
public:
	static t_pair	split2Pair(std::string& line);
	static t_pair	split2Pair(std::string& line, char delim);
};

#endif
