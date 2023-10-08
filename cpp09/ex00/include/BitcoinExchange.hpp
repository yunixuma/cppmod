/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/08 12:37:31 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <exception>
# include <iostream>
# include <string>
# include "MonthlyData.hpp"

class BitcoinExchange
{
private:
	std::map<int, MonthlyData>	monthlyData_;
public:
	BitcoinExchange(const std::string& filepath);
	BitcoinExchange(const BitcoinExchange& src);
	BitcoinExchange&	operator=(const BitcoinExchange& rhs);
	~BitcoinExchange(void);
	void				exchange(int date, int amount) const;
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
