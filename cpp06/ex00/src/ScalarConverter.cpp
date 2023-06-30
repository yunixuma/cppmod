/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/30 11:36:48 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string	ScalarConverter::convert(const std::string& str) {
	 std::clog << "\033[32;2;3m<ScalarConverter> toInt() called (" \
		<< str << ")\033[m" << std::endl;
	return (str);
}

std::string	ScalarConverter::toChar(const std::string& str) {
	 std::clog << "\033[32;2;3m<ScalarConverter> toChar() called (" \
		<< str << ")\033[m" << std::endl;
	return (str);
}

std::string	ScalarConverter::toFloat(const std::string& str) {
	 std::clog << "\033[32;2;3m<ScalarConverter> toFloat() called (" \
		<< str << ")\033[m" << std::endl;
	return (str);
}

std::string	ScalarConverter::toDouble(const std::string& str) {
	 std::clog << "\033[32;2;3m<ScalarConverter> toDouble() called (" \
		<< str << ")\033[m" << std::endl;
	return (str);
}
