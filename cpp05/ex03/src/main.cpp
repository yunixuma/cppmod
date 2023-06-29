/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/29 15:54:21 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

static void	case_shrubbery(void) {
	std::clog << "\033[32;43mCASE: Create a Shrubbery cration form\033[m" << std::endl;
	Intern	someRandomIntern;
	AForm*	rrf;
	rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
	if (rrf)
		std::cout << *rrf << std::endl;
}

static void	case_robotomy(void) {
	std::clog << "\033[32;43mCASE: Create a Robotomy request form\033[m" << std::endl;
	Intern	someRandomIntern;
	AForm*	rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf)
		std::cout << *rrf << std::endl;
}

static void	case_presidential(void) {
	std::clog << "\033[32;43mCASE: Create a Presidential pardon form\033[m" << std::endl;
	Intern	someRandomIntern;
	AForm*	rrf;
	rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
	if (rrf)
		std::cout << *rrf << std::endl;
}

static void	case_noexist(void) {
	std::clog << "\033[35;43mCASE: The form name doesn't exist\033[m" << std::endl;
	Intern	someRandomIntern;
	AForm*	rrf;
	rrf = someRandomIntern.makeForm("something name", "Bender");
	if (rrf)
		std::cout << *rrf << std::endl;
}

int	main(void) {
	case_shrubbery();
	case_robotomy();
	case_presidential();
	case_noexist();
	std::clog << "\033[33;42mFINISH\033[m" << std::endl;
	return (0);
}
