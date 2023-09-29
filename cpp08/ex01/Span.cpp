/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/09/29 22:47:48 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(const std::string& name, int grade) \
	: name_(name), grade_(grade) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<Span> Constructor called (" \
		<< this->name_ << ")\033[m" << std::endl;
	if (this->grade_ > 150)
		throw Span::GradeTooLowException();
	else if (this->grade_ < 1)
		throw Span::GradeTooHighException();
}

Span::Span(const Span& src) \
	: name_(src.name_), grade_(src.grade_) {
	std::clog << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<Span> Copy constructor called (" \
		<< this->name_ << ")\033[m" << std::endl;
	// this->name_ = src.name_;
	// this->grade_ = src.grade_;
	if (this->grade_ > 150)
		throw Span::GradeTooLowException();
	else if (this->grade_ < 1)
		throw Span::GradeTooHighException();
}

Span&	Span::operator=(const Span& rhs) {
	std::clog << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<Span> Copy assignment operator called (" \
		<< this->name_ << ")\033[m" << std::endl;
	if (this != &rhs)
	{
		const_cast<std::string&>(this->name_) = rhs.name_;
		this->grade_ = rhs.grade_;
	}
	if (this->grade_ > 150)
		throw Span::GradeTooLowException();
	else if (this->grade_ < 1)
		throw Span::GradeTooHighException();
	return (*this);
}

Span::~Span(void) {
	std::clog << "\033[31;2;3m[" << this \
		<< "]<Span> Destructor called (" \
		<< this->name_ << ")\033[m" << std::endl;
}

int	Span::getGrade(void) const {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<Span> getGrade() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	return (this->grade_);
}

void	Span::incrementGrade(void) {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<Span> incrementGrade() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	this->grade_--;
	// if (this->grade_ > 150)
	// 	throw Span::GradeTooLowException();
	if (this->grade_ < 1)
		throw Span::GradeTooHighException();
	// if (this->grade_ > 150)
	// 	throw std::range_error("The grade too low");
	// else if (this->grade_ < 1)
	// 	throw std::range_error("The grade too high");
}

// When an exception thrown
const char*	Span::GradeTooHighException::what(void) const throw() {
	std::clog << "\033[35;2;3m[" << this \
		<< "]<Span::GradeTooHighException> what() called\033[m" << std::endl;
	return ("The grade too high");
	// return (1);
}

const char*	Span::GradeTooLowException::what(void) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<Span::GradeTooLowException> what() called\033[m" << std::endl;
	return ("The grade too low");
	// return (2);
}
