/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/23 13:41:30 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

void	case_sign_success(void) {
	std::clog << "\033[32;43mCASE: Succeed signing\033[m" << std::endl;
	Bureaucrat	bc1("John", 25);
	Bureaucrat	bc2("Jane");
	Form		form1("Form A");
	Form		form2("Form B", 100, 100);
	bc1.signForm(form1);
	std::cout << form1 << std::endl;
	bc2.signForm(form2);
	std::cout << form2 << std::endl;
}

void	case_sign_fail_grade(void) {
	std::clog << "\033[35;43mCASE: Fail signing for the grade\033[m" << std::endl;
	Bureaucrat	bc("John", 80);
	Form		form("Form B", 20, 40);
	bc.signForm(form);
	std::cout << form << std::endl;
}

void	case_sign_fail_already(void) {
	std::clog << "\033[35;43mCASE: Fail signing for already signed\033[m" << std::endl;
	Bureaucrat	bc1("John", 25);
	Bureaucrat	bc2("Jane");
	Form		form("Form B", 100, 100);
	bc1.signForm(form);
	std::cout << form << std::endl;
	bc2.signForm(form);
	std::cout << form << std::endl;
}

int	main(void) {
	case_sign_success();
	case_sign_fail_grade();
	case_sign_fail_already();
	return (0);
}
