/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/09 15:27:33 by Yoshihiro K      ###   ########.fr       */
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
	class InvalidFormatException : public std::exception
	{
	public:
		virtual std::string	what(std::string& line) const throw();
	};
	class InvalidDateException : public std::exception
	{
	public:
		virtual std::string	what(std::string& s_date) const throw();
	};
	class NotPositiveException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
	class TooLargeException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
};

#endif
