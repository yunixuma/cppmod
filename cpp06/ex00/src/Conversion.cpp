/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/29 17:55:58 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

const std::string&	Conversion::getName(void) const {
/*	 std::clog << "\033[32;2;3m[" << this \
		<< "]<Conversion> getName() called (" \
		<< this->name_ << ")\033[m" << std::endl;*/
	return (this->name_);
}

const std::string&	Conversion::getTarget(void) const {
/*	 std::clog << "\033[32;2;3m[" << this \
		<< "]<Conversion> getTarget() called (" \
		<< this->name_ << ")\033[m" << std::endl;*/
	return (this->target_);
}

void	Conversion::setTarget(const std::string& target) {
/*	 std::clog << "\033[32;2;3m[" << this \
		<< "]<Conversion> setTarget() called (" \
		<< this->name_ << ")\033[m" << std::endl;*/
	const_cast<std::string&>(this->target_) = target;
}

bool	Conversion::getSigned(void) const {
/*	std::clog << "\033[32;2;3m[" << this \
		<< "]<Conversion> getSigned() called (" \
		<< this->name_ << ")\033[m" << std::endl;*/
	return (this->signed_);
}

int	Conversion::getGradeToSign(void) const {
/*	 std::clog << "\033[32;2;3m[" << this \
		<< "]<Conversion> getGradeToSign() called (" \
		<< this->name_ << ")\033[m" << std::endl;*/
	return (this->grade_to_sign_);
}

int	Conversion::getGradeToExec(void) const {
/*	std::clog << "\033[32;2;3m[" << this \
		<< "]<Conversion> getGradeToExec() called (" \
		<< this->name_ << ")\033[m" << std::endl;*/
	return (this->grade_to_exec_);
}

void	Conversion::setSigned(bool issigned) {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<Conversion> setSigned() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	this->signed_ = issigned;
}

void	Conversion::copy(const Conversion& src) {
	std::clog << "\033[35;2;3m[" << this \
		<< "]<Conversion> copy() called (" \
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
const char*	Conversion::GradeTooHighException::what(void) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<Conversion::GradeTooHighException> what() called\033[m" << std::endl;
	return ("the grade is too high");
	// return (1);
}

const char*	Conversion::GradeTooLowException::what(void) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<Conversion::GradeTooLowException> what() called\033[m" << std::endl;
	return ("the grade is too low");
	// return (2);
}

const char*	Conversion::AlreadySignedException::what(void) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<Conversion::AlreadySignedException> what() called\033[m" << std::endl;
	return ("the form is already signed");
	// return (3);
}

const char*	Conversion::NotSignedException::what(void) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<Conversion::NotSignedException> what() called\033[m" << std::endl;
	return ("the form is not signed yet");
	// return (4);
}

// Insertion operator overload to print
std::ostream&	operator<<(std::ostream& stream, const Conversion& form) {
	stream << "Form \"" << form.getName() << "\" for \"" 
		<< form.getTarget() << "\", signed " \
		<< (form.getSigned() ? "true" : "false") << ", grade " \
		<< form.getGradeToSign() << " to sign, grade " \
		<< form.getGradeToExec() << " to execute.";
	return (stream);
}
