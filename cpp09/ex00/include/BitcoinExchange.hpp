/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/09 03:46:01 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <exception>
# include <iostream>
# include <string>
# include "MonthlyData.hpp"

# define INVALID_PRICE	-0.01f

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
	void				getPrice(int month, int day) const;
	class InvalidFormatException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
	class InvalidDateException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
	class NotPositiveException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
	class ToolargeException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
};

#endif
