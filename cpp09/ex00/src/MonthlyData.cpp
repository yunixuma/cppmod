/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonthlyData.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/08 09:59:59 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MonthlyData.hpp"

MonthlyData::MonthlyData(int month) \
	: month_(month), dailyPrice_() {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<MonthlyData> Constructor called (" \
		<< this->month_ << ")\033[m" << std::endl;
}

MonthlyData::MonthlyData(const MonthlyData& src) \
	: month_(src.month_), dailyPrice_(src.dailyPrice_) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<MonthlyData> Copy constructor called (" \
		<< this->month_ << ")\033[m" << std::endl;
}

MonthlyData&	MonthlyData::operator=(const MonthlyData& rhs) {
	std::clog << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<MonthlyData> Copy assignment operator called (" \
		<< this->month_ << ")\033[m" << std::endl;
	if (this != &rhs)
	{
		this->month_ = rhs.month_;
		this->dailyPrice_ = rhs.dailyPrice_;
	}
	return (*this);
}

MonthlyData::~MonthlyData(void) {
	std::clog << "\033[31;2;3m[" << this \
		<< "]<MonthlyData> Destructor called (" \
		<< this->month_ << ")\033[m" << std::endl;
}

bool	MonthlyData::addData(int day, float price) {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<MonthlyData> addData() called (" \
		<< this->month_ << day << ")\033[m" << std::endl;
	std::pair<std::iterator, bool>	ret;
	ret = dailyPrice_.insert(std::pair<int, float>::value_type(day, price));
	if (ret.second == false)
		return (false);
	return (true);
}

float	MonthlyData::getPrice(int day) const {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<MonthlyData> getPrice() called (" \
		<< this->month_ << day << ")\033[m" << std::endl;
	return (this->dailyPrice_.find(day)->second);
}
