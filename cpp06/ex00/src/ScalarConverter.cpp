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

template<> one::operator char(std::string& str) {
	if (str.length != 1)
		return ('!');
	return (*str.c_str());
}

template <typename T>
int	ScalarConverter::convert(std::string& str)
{
	float				f;
	double				dbl;
	int					n;
	char				c;
	std::stringstream	ss;

	std::string	str(argv[1]);

	ss.str("");
	ss.clear(std::stringstream::goodbit);	
	ss << str;
	try {
		ss >> dbl;
	}
	catch (std::exception & e) {
		std::cerr << "\033[31mInvalid double: " << c << "\033[m" << std::endl;
	}
	std::cout << "double: " << dbl << std::endl;

	ss.str("");
	ss.clear(std::stringstream::goodbit);	
	ss << str;
	try {
		ss >> f;
	}
	catch (std::exception & e) {
		std::cerr << "\033[31mInvalid float: " << f << "\033[m" << std::endl;
	}
	std::cout << "float: " << f << std::endl;

	ss.str("");
	ss.clear(std::stringstream::goodbit);	
	ss << str;
	try {
		ss >> n;
	}
	catch (std::exception & e) {
		std::cerr << "\033[31mInvalid int: " << n << "\033[m" << std::endl;
	}
	std::cout << "int: " << n << std::endl;

	ss.str("");
	ss.clear(std::stringstream::goodbit);	
	ss << str;
	try {
		ss >> c;
	}
	catch (std::exception & e) {
		std::cerr << "\033[31mInvalid char: " << c << "\033[m" << std::endl;
	}
	std::cout << "char: " << c << std::endl;
}

/*
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
*/