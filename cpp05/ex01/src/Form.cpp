/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/22 17:26:51 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string& name, int grade) \
	: name_(name), grade_(grade) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<Form> Constructor called (" \
		<< this->name_ << ")\033[m" << std::endl;
	if (this->grade_ > 150)
		throw Form::GradeTooLowException();
	else if (this->grade_ < 1)
		throw Form::GradeTooHighException();
}

Form::Form(const Form& src) \
	: name_(src.name_), grade_(src.grade_) {
	std::clog << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<Form> Copy constructor called (" \
		<< this->name_ << ")\033[m" << std::endl;
	if (this->grade_ > 150)
		throw Form::GradeTooLowException();
	else if (this->grade_ < 1)
		throw Form::GradeTooHighException();
}

Form&	Form::operator=(const Form& rhs) {
	std::clog << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<Form> Copy assignment operator called (" \
		<< this->name_ << ")\033[m" << std::endl;
	if (this != &rhs)
	{
		const_cast<std::string&>(this->name_) = rhs.name_;
		this->grade_ = rhs.grade_;
	}
	if (this->grade_ > 150)
		throw Form::GradeTooLowException();
	else if (this->grade_ < 1)
		throw Form::GradeTooHighException();
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

int	Form::getGrade(void) const {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<Form> getGrade() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	return (this->grade_);
}

void	Form::incrementGrade(void) {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<Form> incrementGrade() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	this->grade_--;
	if (this->grade_ > 150)
		throw Form::GradeTooLowException();
	else if (this->grade_ < 1)
		throw Form::GradeTooHighException();
}

void	Form::decrementGrade(void) {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<Form> decrementGrade() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	this->grade_++;
	if (this->grade_ > 150)
		throw Form::GradeTooLowException();
	else if (this->grade_ < 1)
		throw Form::GradeTooHighException();
	// if (this->grade_ > 150)
	// 	throw std::range_error("The grade too low");
	// else if (this->grade_ < 1)
	// 	throw std::range_error("The grade too high");
}

// When an exception thrown
const char*	Form::GradeTooHighException::what(void) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<Form::GradeTooHighException> what() called\033[m" << std::endl;
	return ("The grade too high");
	// return (1);
}

const char*	Form::GradeTooLowException::what(void) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<Form::GradeTooLowException> what() called\033[m" << std::endl;
	return ("The grade too low");
	// return (2);
}

// Insertion operator overload to print
std::ostream&	operator<<(std::ostream& stream, const Form& form) {
	stream << form.getName() << ", Form grade " << form.getGrade() << ".";
	return (stream);
}
