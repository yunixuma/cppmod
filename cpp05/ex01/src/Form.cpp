/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/23 13:28:56 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string& name, int grade_to_sign, int grade_to_exec) \
	: name_(name), signed_(false), \
	grade_to_sign_(grade_to_sign) , grade_to_exec_(grade_to_exec) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<Form> Constructor called (" \
		<< this->name_ << ")\033[m" << std::endl;
}

Form::Form(const Form& src) \
	: name_(src.name_), signed_(src.signed_), \
	grade_to_sign_(src.grade_to_sign_) , grade_to_exec_(src.grade_to_exec_) {
	std::clog << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<Form> Copy constructor called (" \
		<< this->name_ << ")\033[m" << std::endl;
}

Form&	Form::operator=(const Form& rhs) {
	std::clog << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<Form> Copy assignment operator called (" \
		<< this->name_ << ")\033[m" << std::endl;
	if (this != &rhs)
	{
		const_cast<std::string&>(this->name_) = rhs.name_;
		this->signed_ = rhs.signed_;
		const_cast<int&>(this->grade_to_sign_) = rhs.grade_to_sign_;
		const_cast<int&>(this->grade_to_exec_) = rhs.grade_to_exec_;
	}
	return (*this);
}

Form::~Form(void) {
	std::clog << "\033[31;2;3m[" << this \
		<< "]<Form> Destructor called (" \
		<< this->name_ << ")\033[m" << std::endl;
}

const std::string&	Form::getName(void) const {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<Form> getName() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	return (this->name_);
}

bool	Form::getSigned(void) const {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<Form> getSigned() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	return (this->signed_);
}

int	Form::getGradeToSign(void) const {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<Form> getGradeToSign() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	return (this->grade_to_sign_);
}

int	Form::getGradeToExec(void) const {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<Form> getGradeToExec() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	return (this->grade_to_exec_);
}

void	Form::beSigned(const Bureaucrat& bc) {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<Form> beSigned() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	if (this->grade_to_sign_ < bc.getGrade())
		throw Form::GradeTooLowException();
	else if (this->signed_ == true)
		throw Form::AlreadySignedException();
	this->signed_ = true;
}

// When an exception thrown
const char*	Form::GradeTooHighException::what(void) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<Form::GradeTooHighException> what() called\033[m" << std::endl;
	return ("the grade is too high");
	// return (1);
}

const char*	Form::GradeTooLowException::what(void) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<Form::GradeTooLowException> what() called\033[m" << std::endl;
	return ("the grade is too low");
	// return (2);
}

const char*	Form::AlreadySignedException::what(void) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<Form::AlreadySignedException> what() called\033[m" << std::endl;
	return ("already signed");
	// return (3);
}

// Insertion operator overload to print
std::ostream&	operator<<(std::ostream& stream, const Form& form) {
	stream << "Form \"" << form.getName() << "\", signed " \
		<< (form.getSigned() ? "true" : "false") << ", grade " \
		<< form.getGradeToSign() << " to sign, grade " \
		<< form.getGradeToExec() << " to execute.";
	return (stream);
}
