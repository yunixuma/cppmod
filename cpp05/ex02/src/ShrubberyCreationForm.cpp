/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/24 18:45:04 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name, int grade_to_sign, int grade_to_exec) \
	: name_(name), signed_(false), \
	grade_to_sign_(grade_to_sign) , grade_to_exec_(grade_to_exec) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<ShrubberyCreationForm> Constructor called (" \
		<< this->name_ << ")\033[m" << std::endl;
	if (this->grade_to_sign_ > 150 || this->grade_to_exec_ > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (this->grade_to_sign_ < 1 || this->grade_to_exec_ < 1)
		throw Bureaucrat::GradeTooHighException();
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) \
	: name_(src.name_), signed_(src.signed_), \
	grade_to_sign_(src.grade_to_sign_) , grade_to_exec_(src.grade_to_exec_) {
	std::clog << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<ShrubberyCreationForm> Copy constructor called (" \
		<< this->name_ << ")\033[m" << std::endl;
	if (this->grade_to_sign_ > 150 || this->grade_to_exec_ > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (this->grade_to_sign_ < 1 || this->grade_to_exec_ < 1)
		throw Bureaucrat::GradeTooHighException();
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
	std::clog << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<ShrubberyCreationForm> Copy assignment operator called (" \
		<< this->name_ << ")\033[m" << std::endl;
	if (this != &rhs)
	{
		const_cast<std::string&>(this->name_) = rhs.name_;
		this->signed_ = rhs.signed_;
		const_cast<int&>(this->grade_to_sign_) = rhs.grade_to_sign_;
		const_cast<int&>(this->grade_to_exec_) = rhs.grade_to_exec_;
	}
	if (this->grade_to_sign_ > 150 || this->grade_to_exec_ > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (this->grade_to_sign_ < 1 || this->grade_to_exec_ < 1)
		throw Bureaucrat::GradeTooHighException();
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::clog << "\033[31;2;3m[" << this \
		<< "]<ShrubberyCreationForm> Destructor called (" \
		<< this->name_ << ")\033[m" << std::endl;
}

const std::string&	ShrubberyCreationForm::getName(void) const {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<ShrubberyCreationForm> getName() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	return (this->name_);
}

bool	ShrubberyCreationForm::getSigned(void) const {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<ShrubberyCreationForm> getSigned() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	return (this->signed_);
}

int	ShrubberyCreationForm::getGradeToSign(void) const {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<ShrubberyCreationForm> getGradeToSign() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	return (this->grade_to_sign_);
}

int	ShrubberyCreationForm::getGradeToExec(void) const {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<ShrubberyCreationForm> getGradeToExec() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	return (this->grade_to_exec_);
}

void	ShrubberyCreationForm::beSigned(const Bureaucrat& bc) {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<ShrubberyCreationForm> beSigned() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	if (this->grade_to_sign_ < bc.getGrade())
		throw ShrubberyCreationForm::GradeTooLowException();
	else if (this->signed_ == true)
		throw ShrubberyCreationForm::AlreadySignedException();
	this->signed_ = true;
}

// When an exception thrown
const char*	ShrubberyCreationForm::GradeTooHighException::what(void) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<ShrubberyCreationForm::GradeTooHighException> what() called\033[m" << std::endl;
	return ("the grade is too high");
	// return (1);
}

const char*	ShrubberyCreationForm::GradeTooLowException::what(void) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<ShrubberyCreationForm::GradeTooLowException> what() called\033[m" << std::endl;
	return ("the grade is too low");
	// return (2);
}

const char*	ShrubberyCreationForm::AlreadySignedException::what(void) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<ShrubberyCreationForm::AlreadySignedException> what() called\033[m" << std::endl;
	return ("already signed");
	// return (3);
}

// Insertion operator overload to print
std::ostream&	operator<<(std::ostream& stream, const ShrubberyCreationForm& ShrubberyCreationForm) {
	stream << "ShrubberyCreationForm \"" << ShrubberyCreationForm.getName() << "\", signed " \
		<< (ShrubberyCreationForm.getSigned() ? "true" : "false") << ", grade " \
		<< ShrubberyCreationForm.getGradeToSign() << " to sign, grade " \
		<< ShrubberyCreationForm.getGradeToExec() << " to execute.";
	return (stream);
}
