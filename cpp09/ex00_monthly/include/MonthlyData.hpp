/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonthlyData.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/13 11:54:38 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONTHLYDATA_HPP
# define MONTHLYDATA_HPP

# include <map>
# include <iterator>
# include <iostream>
# include "btc.hpp"
# include "DateConverter.hpp"

class MonthlyData
{
private:
	int						month_;
	std::map<int, float>	daily_price_;
	bool					addData(int day, float price);
public:
	MonthlyData(int month = 0);
	~MonthlyData(void);
	MonthlyData(const MonthlyData& src);
	MonthlyData&			operator=(const MonthlyData& rhs);
	bool					addData(t_pair& pair);
	float					getPrice(int day) const;
};

#endif
