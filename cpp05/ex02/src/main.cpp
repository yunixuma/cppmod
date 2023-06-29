/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/29 15:55:35 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void	case_construct(void) {
	std::clog << "\033[32;43mCASE: Construct & copy assignment\033[m" << std::endl;
	AForm*	form1 = new ShrubberyCreationForm("W-8BEN");
	std::cout << *form1 << std::endl;
	AForm*	form2 = new ShrubberyCreationForm(*form1);
	std::cout << *form2 << std::endl;
	ShrubberyCreationForm*	form3 = new ShrubberyCreationForm("DS-160");
	std::cout << *form3 << std::endl;
	*form3 = *form2;
	std::cout << *form3 << std::endl;
	delete form1;
	delete form2;
	delete form3;
}

static void	case_exec_success(void) {
	std::clog << "\033[32;43mCASE: Succeed execution\033[m" << std::endl;
	Bureaucrat	bc("John", 5);
	std::cout << bc << std::endl;
	AForm*		form1 = new ShrubberyCreationForm("W-8BEN");
	AForm*		form2 = new RobotomyRequestForm("DS-160");
	AForm*		form3 = new PresidentialPardonForm("DS-160");
	bc.signForm(*form1);
	bc.signForm(*form2);
	bc.signForm(*form3);
	std::cout << *form1 << std::endl;
	std::cout << *form2 << std::endl;
	std::cout << *form3 << std::endl;
	bc.executeForm(*form1);
	bc.executeForm(*form2);
	usleep(574831);
	bc.executeForm(*form2);
	usleep(657483);
	bc.executeForm(*form2);
	bc.executeForm(*form3);
	delete form1;
	delete form2;
	delete form3;
}

static void	case_exec_fail_grade(void) {
	std::clog << "\033[35;43mCASE: Fail execution for the grade\033[m" << std::endl;
	Bureaucrat	bc("John", 140);
	std::cout << bc << std::endl;
	AForm*		form = new ShrubberyCreationForm("DS-160");
	bc.signForm(*form);
	std::cout << *form << std::endl;
	bc.executeForm(*form);
	delete form;
}

static void	case_exec_fail_nosign(void) {
	std::clog << "\033[35;43mCASE: Fail execution for not signed\033[m" << std::endl;
	Bureaucrat	bc("John", 40);
	std::cout << bc << std::endl;
	AForm*		form = new ShrubberyCreationForm("DS-160");
	std::cout << *form << std::endl;
	bc.executeForm(*form);
	delete form;
}

int	main(void) {
	case_construct()
	case_exec_success();
	case_exec_fail_grade();
	case_exec_fail_nosign();
	std::clog << "\033[33;42mFINISH\033[m" << std::endl;
	return (0);
}
