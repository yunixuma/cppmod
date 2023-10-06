/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonthlyData.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/06 12:10:36 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONTHLYDATA_HPP
# define MONTHLYDATA_HPP

# include <exception>
# include <iostream>
# include <string>

class MonthlyData
{
public:
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
private:
	std::map<int, float>	day_;
public:
	MonthlyData(int day, float price);
	MonthlyData(const MonthlyData& src);
	MonthlyData&	operator=(const MonthlyData& rhs);
	~MonthlyData(void);
	float	getPrice(int day) const;
};

// std::ostream&	operator<<(std::ostream& stream, const MonthlyData& bc);

#endif
