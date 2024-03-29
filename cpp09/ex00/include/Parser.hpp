/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/15 03:54:58 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
# define PARSER_HPP

# include <sstream>
# include <string>
# include "btc.hpp"
# include "DateConverter.hpp"

# define CHR_DELIM	','
# define CHRS_CHR_DELIM	",|:;/=-@"

class Parser
{
private:
	Parser();
	~Parser();
public:
	static char		searchDelim(std::string& line);
	static t_pair	split2Pair(std::string& line);
	static t_pair	split2Pair(std::string& line, char delim);
	class InvalidFormatException : public std::exception
	{
	public:
		// virtual std::string	invalid_argument(std::string& line) const throw();
		virtual const char*	what() const throw();
	};
};

#endif
