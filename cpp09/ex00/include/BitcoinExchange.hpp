/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/13 15:13:17 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <exception>
# include <iostream>
# include <string>
# include <cstring>
# include "btc.hpp"
# include "MonthlyData.hpp"
# include "Parser.hpp"
# include "DateConverter.hpp"

class BitcoinExchange
{
private:
	std::map<int, MonthlyData>	monthly_data_;
	void				addData(std::ifstream& ifs);
	void				exchange(int date, float amount) const;
public:
	BitcoinExchange(void);
	~BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange& src);
	BitcoinExchange&	operator=(const BitcoinExchange& rhs);
	void				openData(const std::string& filepath);
	void				exchange(t_pair& pair) const;
	float				getPrice(int month, int day) const;
	// class NotPositiveException : public std::range_error
	class DuplicateDataException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
	class NotPositiveException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
	// class TooLargeException : public std::out_of_range
	class TooLargeException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
		// virtual const char*	out_of_range() const throw();
	};
};

#endif
