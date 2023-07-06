/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/07/06 22:57:53 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <cmath>

class Data
{
private:
	int			num_;
	std::string	str_;
public:
	Data(const int num = 42, const std::string& = "ft");
	Data(const Data& src);
	Data&				operator=(const Data& rhs);
	~Data();
	int					getNum(void) const;
	const std::string&	getStr(void) const;
};

std::ostream&	operator<<(std::ostream& stream, const Data& data);

#endif
