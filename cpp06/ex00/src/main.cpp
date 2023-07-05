/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/07/06 05:35:11 by Yoshihiro K      ###   ########.fr       */
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
	std::string	str(argv[1]);

	try {
		char	c = ScalarConverter::convert<char>(str);
		std::cout << "\033[33mchar: " << c << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << "\033[31mchar: " << e.what() << "\033[m" << std::endl;
	}

	try {
		int	n = ScalarConverter::convert<int>(str);
		std::cout << "\033[33mint: " << n << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << "\033[31mint: " << e.what() << "\033[m" << std::endl;
	}
/*
	try {
		float	f = ScalarConverter::convert(str);
		std::cout << "\033[33mfloat: " << f << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << "\033[31mfloat: " << e.what() << "\033[m" << std::endl;
	}

	try {
		double	dbl = ScalarConverter::convert(str);
		std::cout << "\033[33mdouble: " << dbl << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << "\033[31mdouble: " << e.what() << "\033[m" << std::endl;
	}
*/
	// std::cout << "char: " << ScalarConverter::toChar(str) << std::endl;
	// std::cout << "int: " << ScalarConverter::toInt(str) << std::endl;
	// std::cout << "float: " << ScalarConverter::toFloat(str) << std::endl;
	// std::cout << "double: " << ScalarConverter::toDouble(str) << std::endl;
	std::clog << "\033[33;42mFINISH\033[m" << std::endl;
	return (0);
}
