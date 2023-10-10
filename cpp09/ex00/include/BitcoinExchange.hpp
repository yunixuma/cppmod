/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/10 18:08:53 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <exception>
# include <iostream>
# include <string>
# include <cstring>
# include "btc.h"
# include "MonthlyData.hpp"
# include "DateConverter.hpp"

class BitcoinExchange
{
private:
	std::map<int, MonthlyData>	monthly_data_;
public:
	BitcoinExchange(const std::string& filepath);
	BitcoinExchange(const BitcoinExchange& src);
	BitcoinExchange&	operator=(const BitcoinExchange& rhs);
	~BitcoinExchange(void);
	void				exchange(int date, float amount) const;
	float				getPrice(int month, int day) const;
	class InvalidFormatException : public std::invalid_argument
	{
	public:
		// virtual std::string	what(std::string& line) const throw();
		virtual const char*	invalid_argument(std::string& line) const throw();
	};
	class InvalidDateException : public std::invalid_argument
	{
	public:
		virtual const char*	invalid_argument(std::string& s_date) const throw();
		// virtual std::string	what(std::string& s_date) const throw();
	};
	class NotPositiveException : public std::range_error
	{
	public:
		virtual const char*	what() const throw();
	};
	class TooLargeException : public std::out_of_range
	{
	public:
		virtual const char*	what() const throw();
	};
};

#endif
