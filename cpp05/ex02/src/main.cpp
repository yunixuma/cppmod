/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/25 05:35:48 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	case_construct_regular(void) {
	std::clog << "\033[32;43mCASE: Regular construct\033[m" << std::endl;
	try {
		AForm*	form1 = new ShrubberyCreationForm("W-8BEN");
		std::cout << form1 << std::endl;
		AForm*	form2 = new ShrubberyCreationForm("DS-160");
		std::cout << form2 << std::endl;
		AForm*	form3 = new ShrubberyCreationForm("IRS 1040");
		std::cout << form3 << std::endl;
		delete form1;
		delete form2;
		delete form3;
	}
	catch (std::exception & e) {
		std::cerr << "An error caught, thrown from std::exception: " << std::endl \
			<< e.what() << std::endl;
		return (1);
	}
	return (0);
}

int	case_construct_low(void) {
	std::clog << "\033[35;43mCASE: Too low w/ construct\033[m" << std::endl;
	try {
		AForm*	form = new ShrubberyCreationForm("W-8BEN");
		std::cout << form << std::endl;
		delete form;
	}
	catch (std::exception & e) {
		std::cerr << "An error caught, thrown from std::exception: " << std::endl \
			<< e.what() << std::endl;
		return (1);
	}
	return (0);
}

int	case_construct_high(void) {
	std::clog << "\033[35;43mCASE: Too high w/ construct\033[m" << std::endl;
	try {
		AForm*	form = new ShrubberyCreationForm("W-8BEN");
		std::cout << *form << std::endl;
		delete form;
	}
	catch (std::exception & e) {
		std::cerr << "An error caught, thrown from std::exception: " << std::endl \
			<< e.what() << std::endl;
		return (1);
	}
	return (0);
}

void	case_sign_success(void) {
	std::clog << "\033[32;43mCASE: Succeed signing\033[m" << std::endl;
	Bureaucrat	bc1("John", 40);
	Bureaucrat	bc2("Jane");
	AForm*		form1 = new ShrubberyCreationForm("W-8BEN");
	AForm*		form2 = new ShrubberyCreationForm("DS-160");
	bc1.signForm(*form1);
	std::cout << *form1 << std::endl;
	bc2.signForm(*form2);
	std::cout << *form2 << std::endl;
	delete form1;
	delete form2;
}

void	case_sign_fail_grade(void) {
	std::clog << "\033[35;43mCASE: Fail signing for the grade\033[m" << std::endl;
	Bureaucrat	bc("John", 80);
	AForm*		form = new ShrubberyCreationForm("DS-160");
	bc.signForm(*form);
	std::cout << *form << std::endl;
	delete form;
}

void	case_sign_fail_already(void) {
	std::clog << "\033[35;43mCASE: Fail signing for already signed\033[m" << std::endl;
	Bureaucrat	bc1("John", 40);
	Bureaucrat	bc2("Jane");
	AForm*		form = new ShrubberyCreationForm("DS-160");
	bc1.signForm(*form);
	std::cout << *form << std::endl;
	bc2.signForm(*form);
	std::cout << *form << std::endl;
	delete form;
}

int	main(void) {
	if (!case_construct_regular())
		std::cout << "No exception occurred" << std::endl;
	if (!case_construct_high())
		std::cout << "No exception occurred" << std::endl;
	if (!case_construct_low())
		std::cout << "No exception occurred" << std::endl;
	case_sign_success();
	case_sign_fail_grade();
	case_sign_fail_already();
	return (0);
}
