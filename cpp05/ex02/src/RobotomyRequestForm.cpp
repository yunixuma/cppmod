/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/25 10:03:07 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) \
	: AForm("shrubbery_creation", target, 145, 137) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<RobotomyRequestForm> Constructor called (" \
		<< this->getName() << ")\033[m" << std::endl;
	// if (this->getGradeToSign() > 150 || this->getGradeToExec() > 150)
	// 	throw Bureaucrat::GradeTooLowException();
	// else if (this->getGradeToSign() < 1 || this->getGradeToExec() < 1)
	// 	throw Bureaucrat::GradeTooHighException();
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) \
	: AForm(src) {
	std::clog << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<RobotomyRequestForm> Copy constructor called (" \
		<< this->getName() << ")\033[m" << std::endl;
	if (this->getGradeToSign() > 150 || this->getGradeToExec() > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (this->getGradeToSign() < 1 || this->getGradeToExec() < 1)
		throw Bureaucrat::GradeTooHighException();
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
	std::clog << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<RobotomyRequestForm> Copy assignment operator called (" \
		<< this->getName() << ")\033[m" << std::endl;
	if (this != &rhs)
		this->copy(rhs);
	if (this->getGradeToSign() > 150 || this->getGradeToExec() > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (this->getGradeToSign() < 1 || this->getGradeToExec() < 1)
		throw Bureaucrat::GradeTooHighException();
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::clog << "\033[31;2;3m[" << this \
		<< "]<RobotomyRequestForm> Destructor called (" \
		<< this->getName() << ")\033[m" << std::endl;
}

void	RobotomyRequestForm::beSigned(const Bureaucrat& bc) {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<RobotomyRequestForm> beSigned() called (" \
		<< this->getName() << ")\033[m" << std::endl;
	if (this->getGradeToSign() < bc.getGrade())
		throw RobotomyRequestForm::GradeTooLowException();
	else if (this->getSigned() == true)
		throw RobotomyRequestForm::AlreadySignedException();
	this->setSigned(true);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<RobotomyRequestForm> execute() called (" \
		<< this->getName() << ")\033[m" << std::endl;
	(void)executor;
}

// When an exception thrown
const char*	RobotomyRequestForm::GradeTooHighException::what(void) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<RobotomyRequestForm::GradeTooHighException> what() called\033[m" << std::endl;
	return ("the grade is too high");
	// return (1);
}

const char*	RobotomyRequestForm::GradeTooLowException::what(void) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<RobotomyRequestForm::GradeTooLowException> what() called\033[m" << std::endl;
	return ("the grade is too low");
	// return (2);
}

const char*	RobotomyRequestForm::AlreadySignedException::what(void) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<RobotomyRequestForm::AlreadySignedException> what() called\033[m" << std::endl;
	return ("already signed");
	// return (3);
}

// Insertion operator overload to print
std::ostream&	operator<<(std::ostream& stream, const RobotomyRequestForm& RobotomyRequestForm) {
	stream << "RobotomyRequestForm \"" << RobotomyRequestForm.getName() << "\", signed " \
		<< (RobotomyRequestForm.getSigned() ? "true" : "false") << ", grade " \
		<< RobotomyRequestForm.getGradeToSign() << " to sign, grade " \
		<< RobotomyRequestForm.getGradeToExec() << " to execute.";
	return (stream);
}
