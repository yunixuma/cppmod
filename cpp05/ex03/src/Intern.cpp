/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/29 17:32:59 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<Intern> Constructor called\033[m" << std::endl;
	forms_[0] = new ShrubberyCreationForm("sample");
	forms_[1] = new RobotomyRequestForm("sample");
	forms_[2] = new PresidentialPardonForm("sample");
}

Intern::Intern(const Intern& src) {
	std::clog << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<Intern> Copy constructor called\033[m" << std::endl;
}

Intern&	Intern::operator=(const Intern& rhs) {
	std::clog << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<Intern> Copy assignment operator called\033[m" << std::endl;
	return (*this);
}

Intern::~Intern(void) {
	std::clog << "\033[31;2;3m[" << this \
		<< "]<Intern> Destructor called\033[m" << std::endl;
	delete forms_[0];
	delete forms_[1];
	delete forms_[2];
}

AForm*	Intern::makeForm(const std::string& name, const std::string& target) {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<Intern> makeForm() called (" \
		<< name << " for " << target << ")\033[m" << std::endl;
	AForm*	form = NULL;
	for (int i = 0; i < 3; i++) {
		if (name == forms_[i]->getName()) {
			form = forms_[i]->clone();
			form->setTarget(target);
			break ;
		}
	}
	if (form)
		std::cerr << "Intern creates " << *form << std::endl;
	else
		std::cerr << "The form name doesn't exist" << std::endl;
	return (form);
}
