/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/22 15:44:30 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int	case_construct_regular() {
	std::clog << "\033[32;43mCASE: Regular construct\033[m" << std::endl;
	try {
		Bureaucrat	bc1("John", 50);
		Bureaucrat	bc2("Jane");
	}
	// catch (Bureaucrat & e)
	// {
	// 	/* handle exception */
	// 	std::cerr << "An exception caught at Bureaucrat" << std::endl;
	// }
	catch (std::exception & e) {
		std::cerr << "An error caught, thrown from std::exception: " << std::endl \
			<< e.what() << std::endl;
		return (1);
	}
	return (0);
}

int	case_construct_low() {
	std::clog << "\033[35;43mCASE: Too low w/ construct\033[m" << std::endl;
	try {
		Bureaucrat	bc("John", 151);
	}
	catch (std::exception & e) {
		std::cerr << "An error caught, thrown from std::exception: " << std::endl \
			<< e.what() << std::endl;
		return (1);
	}
	return (0);
}

int	case_construct_high() {
	std::clog << "\033[35;43mCASE: Too high w/ construct\033[m" << std::endl;
	try {
		Bureaucrat	bc("John", 0);
	}
	catch (std::exception & e) {
		std::cerr << "An error caught, thrown from std::exception: " << std::endl \
			<< e.what() << std::endl;
		return (1);
	}
	return (0);
}

int	case_decrement_regular() {
	std::clog << "\033[32;43mCASE: Regular decrement\033[m" << std::endl;
	Bureaucrat	bc1("John", 50);
	Bureaucrat	bc2("Jane");
	try {
		bc1.decrementGrade();
		bc2.decrementGrade();
	}
	catch (std::exception & e) {
		std::cerr << "An error caught, thrown from std::exception: " << std::endl \
			<< e.what() << std::endl;
		return (1);
	}
	return (0);
}

int	case_decrement_low() {
	std::clog << "\033[35;43mCASE: Too low w/ decrement\033[m" << std::endl;
	Bureaucrat	bc("John", 150);
	try {
		bc.decrementGrade();
	}
	catch (std::exception & e) {
		std::cerr << "An error caught, thrown from std::exception: " << std::endl \
			<< e.what() << std::endl;
		return (1);
	}
	return (0);
}

int	case_increment_regular() {
	std::clog << "\033[32;43mCASE: Regular increment\033[m" << std::endl;
	Bureaucrat	bc1("John", 50);
	Bureaucrat	bc2("Jane");
	try {
		bc1.incrementGrade();
		bc2.incrementGrade();
	}
	catch (std::exception & e) {
		std::cerr << "An error caught, thrown from std::exception: " << std::endl \
			<< e.what() << std::endl;
		return (1);
	}
	return (0);
}

int	case_increment_high() {
	std::clog << "\033[35;43mCASE: Too high w/ increment\033[m" << std::endl;
	Bureaucrat	bc("John", 1);
	try {
		bc.incrementGrade();
	}
	catch (std::exception & e) {
		std::cerr << "An error caught, thrown from std::exception: " << std::endl \
			<< e.what() << std::endl;
		return (1);
	}
	return (0);
}

int	main() {
	if (!case_construct_regular())
		std::cout << "No exception occurred" << std::endl;
	if (!case_construct_high())
		std::cout << "No exception occurred" << std::endl;
	if (!case_construct_low())
		std::cout << "No exception occurred" << std::endl;
	if (!case_increment_regular())
		std::cout << "No exception occurred" << std::endl;
	if (!case_increment_high())
		std::cout << "No exception occurred" << std::endl;
	if (!case_decrement_regular())
		std::cout << "No exception occurred" << std::endl;
	if (!case_decrement_low())
		std::cout << "No exception occurred" << std::endl;
	return (0);
}
