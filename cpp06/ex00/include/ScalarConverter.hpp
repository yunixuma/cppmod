/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/30 11:34:52 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>

class ScalarConverter
{
private:
	ScalarConverter();
	~ScalarConverter();
public:
	static std::string	toInt(const std::string& str);
	static std::string	toChar(const std::string& str);
	static std::string	toFloat(const std::string& str);
	static std::string	toDouble(const std::string& str);
};

#endif
