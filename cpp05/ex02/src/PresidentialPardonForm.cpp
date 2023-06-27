/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/27 14:48:27 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) \
	: AForm("shrubbery_creation", target, 25, 5) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<PresidentialPardonForm> Constructor called (" \
		<< this->getName() << ")\033[m" << std::endl;
	// if (this->getGradeToSign() > 150 || this->getGradeToExec() > 150)
	// 	throw Bureaucrat::GradeTooLowException();
	// else if (this->getGradeToSign() < 1 || this->getGradeToExec() < 1)
	// 	throw Bureaucrat::GradeTooHighException();
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) \
	: AForm(src) {
	std::clog << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<PresidentialPardonForm> Copy constructor called (" \
		<< this->getName() << ")\033[m" << std::endl;
	if (this->getGradeToSign() > 150 || this->getGradeToExec() > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (this->getGradeToSign() < 1 || this->getGradeToExec() < 1)
		throw Bureaucrat::GradeTooHighException();
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
	std::clog << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<PresidentialPardonForm> Copy assignment operator called (" \
		<< this->getName() << ")\033[m" << std::endl;
	if (this != &rhs)
		this->copy(rhs);
	if (this->getGradeToSign() > 150 || this->getGradeToExec() > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (this->getGradeToSign() < 1 || this->getGradeToExec() < 1)
		throw Bureaucrat::GradeTooHighException();
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::clog << "\033[31;2;3m[" << this \
		<< "]<PresidentialPardonForm> Destructor called (" \
		<< this->getName() << ")\033[m" << std::endl;
}

void	PresidentialPardonForm::beSigned(const Bureaucrat& bc) {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<PresidentialPardonForm> beSigned() called (" \
		<< this->getName() << ")\033[m" << std::endl;
	if (this->getGradeToSign() < bc.getGrade())
		throw PresidentialPardonForm::GradeTooLowException();
	else if (this->getSigned() == true)
		throw PresidentialPardonForm::AlreadySignedException();
	this->setSigned(true);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<PresidentialPardonForm> execute() called (" \
		<< this->getName() << ")\033[m" << std::endl;
	if (this->getSigned() == false)
		throw PresidentialPardonForm::NotSignedException();
	else if (this->getGradeToExec() < executor.getGrade())
		throw PresidentialPardonForm::GradeTooLowException();

	(void)executor;
}

// When an exception thrown
const char*	PresidentialPardonForm::GradeTooHighException::what(void) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<PresidentialPardonForm::GradeTooHighException> what() called\033[m" << std::endl;
	return ("the grade is too high");
	// return (1);
}

const char*	PresidentialPardonForm::GradeTooLowException::what(void) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<PresidentialPardonForm::GradeTooLowException> what() called\033[m" << std::endl;
	return ("the grade is too low");
	// return (2);
}

const char*	PresidentialPardonForm::AlreadySignedException::what(void) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<PresidentialPardonForm::AlreadySignedException> what() called\033[m" << std::endl;
	return ("already signed");
	// return (3);
}

// Insertion operator overload to print
std::ostream&	operator<<(std::ostream& stream, const PresidentialPardonForm& PresidentialPardonForm) {
	stream << "PresidentialPardonForm \"" << PresidentialPardonForm.getName() << "\", signed " \
		<< (PresidentialPardonForm.getSigned() ? "true" : "false") << ", grade " \
		<< PresidentialPardonForm.getGradeToSign() << " to sign, grade " \
		<< PresidentialPardonForm.getGradeToExec() << " to execute.";
	return (stream);
}
