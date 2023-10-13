/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateConverter.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/13 15:22:33 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DateConverter.hpp"

int	DateConverter::iso2yyyymmdd(std::string& s_date) {
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
	return (n_date);
}

int	DateConverter::yyyymmdd2yyyymm(int date) {
	return (date / 100);
}

int	DateConverter::yyyymmdd2dd(int date) {
	return (date % 100);
}

bool	DateConverter::valid(int date) {
	if (date < DATE_LOWER_LIMIT || DATE_HIGHER_LIMIT < date) {
		return (false);
	}

	int	day = date % 10000;
	int	year = date - day; 
	int	month = day / 100;
	day -= month * 100;

	if (month < 1 || 12 < month) {
		return (false);
	}
	if (day < 1 || 31 < day) {
		return (false);
	}
	else if (day == 31 \
		&& (month == 4 || month == 6 || month == 9 || month == 11)) {
		return (false);
	}
	else if (month != 2)
		return (true);
	else if (day > 29) {
		return (false);
	}
	else if (day == 29 && year % 4 != 0) {
		return (false);
	}
	else if (day == 29 && year % 4 == 0 && year % 400 != 0) {
		return (false);
	}
	return (true);
}

int	DateConverter::getPrevMonth(int month) {
	if (month % 100 > 1)
		return (month - 1);
	if (month * 100 <= DATE_LOWER_LIMIT)
		return (0);
	return (month - 89);
}

std::string	DateConverter::yyyymmdd2iso(int date) {
	std::string			s_date;
	std::stringstream	ss;
	ss << date;
	ss >> s_date;
	size_t				len_to_append = 8 - s_date.length();
	while (len_to_append--)
		s_date = "0" + s_date;
	return (s_date.substr(0, 4) \
		+ "-" + s_date.substr(4, 2) \
		+ "-" + s_date.substr(6, 2));
}

// When an exception thrown
const char*	DateConverter::InvalidDateException::what() const throw() {
// const char*	DateConverter::InvalidDateException::invalid_argument(const std::string& s_date) const throw() {
/*	std::clog << "\033[35;3m[" << this \
		<< "]<BitcoinExchange::InvalidDateException> what() called\033[m" \
		<< std::endl;*/
	return ("Error: invalid date => ");
}
