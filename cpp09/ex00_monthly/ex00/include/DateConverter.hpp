/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateConverter.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/13 14:40:23 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATECONVERTER_HPP
# define DATECONVERTER_HPP

# include <sstream>
# include <string>
# include <exception>

# define DATE_LOWER_LIMIT	19700101
# define DATE_HIGHER_LIMIT	20380119
// # define YEAR_LOWER_LIMIT	DATE_LOWER_LIMIT / 10000
// # define YEAR_HIGHER_LIMIT	DATE_HIGHER_LIMIT / 10000
# define DATE_INVALID		0

class DateConverter
{
private:
	DateConverter();
	~DateConverter();
public:
	static int			iso2yyyymmdd(std::string& s_date);
	static bool			valid(int date);
	static int			yyyymmdd2yyyymm(int date);
	static int			yyyymmdd2dd(int date);
	static int			getPrevMonth(int month);
	static std::string	yyyymmdd2iso(int date);
	class InvalidDateException : public std::exception
	{
	public:
		// virtual const char*	invalid_argument(const std::string& s_date) const throw();
		virtual const char*	what() const throw();
	};
};

#endif
