/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonthlyData.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/09 03:53:01 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONTHLYDATA_HPP
# define MONTHLYDATA_HPP

# include <map>
# include <iterator>
# include <iostream>

# define INVALID_PRICE	-0.01f

class MonthlyData
{
private:
	int						month_;
	std::map<int, float>	daily_price_;
public:
	MonthlyData(int month = 0);
	MonthlyData(const MonthlyData& src);
	MonthlyData&	operator=(const MonthlyData& rhs);
	~MonthlyData(void);
	bool			addData(int day, float price);
	float			getPrice(int day) const;
};

#endif
