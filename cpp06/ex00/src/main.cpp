/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/07/05 09:21:15 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
// #include <string>
#include <sstream>
// #include <iomanip>
#include <exception>
#include "ScalarConverter.hpp"

int	main(int argc, char *argv[]) {
	if (argc != 2 || !argv[0] || !argv[1]) {
		std::cerr << "\033[31mInvalid argument\033[m" << std::endl;
		return (1);
	}
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
		return (1);
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

	// std::cout << "char: " << ScalarConverter::toChar(str) << std::endl;
	// std::cout << "int: " << ScalarConverter::toInt(str) << std::endl;
	// std::cout << "float: " << ScalarConverter::toFloat(str) << std::endl;
	// std::cout << "double: " << ScalarConverter::toDouble(str) << std::endl;
	std::clog << "\033[33;42mFINISH\033[m" << std::endl;
	return (0);
}
