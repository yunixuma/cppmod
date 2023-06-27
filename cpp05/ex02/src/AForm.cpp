/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/25 20:30:21 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string& name, const std::string& target, int grade_to_sign, int grade_to_exec) \
	: name_(name), target_(target), signed_(false), \
	grade_to_sign_(grade_to_sign) , grade_to_exec_(grade_to_exec) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<AForm> Constructor called (" \
		<< this->name_ << ")\033[m" << std::endl;
	if (this->grade_to_sign_ > 150 || this->grade_to_exec_ > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (this->grade_to_sign_ < 1 || this->grade_to_exec_ < 1)
		throw Bureaucrat::GradeTooHighException();
}

AForm::AForm(const AForm& src) \
	: name_(src.name_), signed_(src.signed_), \
	grade_to_sign_(src.grade_to_sign_) , grade_to_exec_(src.grade_to_exec_) {
	std::clog << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<AForm> Copy constructor called (" \
		<< this->name_ << ")\033[m" << std::endl;
	if (this->grade_to_sign_ > 150 || this->grade_to_exec_ > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (this->grade_to_sign_ < 1 || this->grade_to_exec_ < 1)
		throw Bureaucrat::GradeTooHighException();
}

AForm&	AForm::operator=(const AForm& rhs) {
	std::clog << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<AForm> Copy assignment operator called (" \
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

AForm::~AForm(void) {
	std::clog << "\033[31;2;3m[" << this \
		<< "]<AForm> Destructor called (" \
		<< this->name_ << ")\033[m" << std::endl;
}

const std::string&	AForm::getName(void) const {
/*	 std::clog << "\033[32;2;3m[" << this \
		<< "]<AForm> getName() called (" \
		<< this->name_ << ")\033[m" << std::endl;*/
	return (this->name_);
}

const std::string&	AForm::getTarget(void) const {
/*	 std::clog << "\033[32;2;3m[" << this \
		<< "]<AForm> getTarget() called (" \
		<< this->name_ << ")\033[m" << std::endl;*/
	return (this->target_);
}

bool	AForm::getSigned(void) const {
/*	std::clog << "\033[32;2;3m[" << this \
		<< "]<AForm> getSigned() called (" \
		<< this->name_ << ")\033[m" << std::endl;*/
	return (this->signed_);
}

int	AForm::getGradeToSign(void) const {
/*	 std::clog << "\033[32;2;3m[" << this \
		<< "]<AForm> getGradeToSign() called (" \
		<< this->name_ << ")\033[m" << std::endl;*/
	return (this->grade_to_sign_);
}

int	AForm::getGradeToExec(void) const {
/*	std::clog << "\033[32;2;3m[" << this \
		<< "]<AForm> getGradeToExec() called (" \
		<< this->name_ << ")\033[m" << std::endl;*/
	return (this->grade_to_exec_);
}

void	AForm::setSigned(bool issigned) {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<AForm> setSigned() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	this->signed_ = issigned;
}

void	AForm::copy(const AForm& src) {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<AForm> copy() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	if (this != &src) {
		const_cast<std::string&>(this->name_) = src.name_;
		const_cast<std::string&>(this->target_) = src.target_;
		this->signed_ = src.signed_;
		const_cast<int&>(this->grade_to_sign_) = src.grade_to_sign_;
		const_cast<int&>(this->grade_to_exec_) = src.grade_to_exec_;
	}
}


// When an exception thrown
const char*	AForm::GradeTooHighException::what(void) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<AForm::GradeTooHighException> what() called\033[m" << std::endl;
	return ("the grade is too high");
	// return (1);
}

const char*	AForm::GradeTooLowException::what(void) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<AForm::GradeTooLowException> what() called\033[m" << std::endl;
	return ("the grade is too low");
	// return (2);
}

const char*	AForm::AlreadySignedException::what(void) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<AForm::AlreadySignedException> what() called\033[m" << std::endl;
	return ("already signed");
	// return (3);
}

// Insertion operator overload to print
std::ostream&	operator<<(std::ostream& stream, const AForm& form) {
	stream << "Form \"" << form.getName() << "\", signed " \
		<< (form.getSigned() ? "true" : "false") << ", grade " \
		<< form.getGradeToSign() << " to sign, grade " \
		<< form.getGradeToExec() << " to execute.";
	return (stream);
}
