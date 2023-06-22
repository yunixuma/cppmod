/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/22 22:33:11 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) \
	: name_(name), grade_(grade) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<Bureaucrat> Constructor called (" \
		<< this->name_ << ")\033[m" << std::endl;
	if (this->grade_ > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (this->grade_ < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) \
	: name_(src.name_), grade_(src.grade_) {
	std::clog << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<Bureaucrat> Copy constructor called (" \
		<< this->name_ << ")\033[m" << std::endl;
	// this->name_ = src.name_;
	// this->grade_ = src.grade_;
	if (this->grade_ > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (this->grade_ < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& rhs) {
	std::clog << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<Bureaucrat> Copy assignment operator called (" \
		<< this->name_ << ")\033[m" << std::endl;
	if (this != &rhs)
	{
		const_cast<std::string&>(this->name_) = rhs.name_;
		this->grade_ = rhs.grade_;
	}
	if (this->grade_ > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (this->grade_ < 1)
		throw Bureaucrat::GradeTooHighException();
	return (*this);
}

Bureaucrat::~Bureaucrat(void) {
	std::clog << "\033[31;2;3m[" << this \
		<< "]<Bureaucrat> Destructor called (" \
		<< this->name_ << ")\033[m" << std::endl;
}

const std::string&	Bureaucrat::getName(void) const {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<Bureaucrat> getName() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	return (this->name_);
}

int	Bureaucrat::getGrade(void) const {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<Bureaucrat> getGrade() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	return (this->grade_);
}

void	Bureaucrat::incrementGrade(void) {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<Bureaucrat> incrementGrade() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	this->grade_--;
	// if (this->grade_ > 150)
	// 	throw Bureaucrat::GradeTooLowException();
	if (this->grade_ < 1)
		throw Bureaucrat::GradeTooHighException();
	// if (this->grade_ > 150)
	// 	throw std::range_error("The grade too low");
	// else if (this->grade_ < 1)
	// 	throw std::range_error("The grade too high");
}

void	Bureaucrat::decrementGrade(void) {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<Bureaucrat> decrementGrade() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	this->grade_++;
	if (this->grade_ > 150)
		throw Bureaucrat::GradeTooLowException();
	// else if (this->grade_ < 1)
	// 	throw Bureaucrat::GradeTooHighException();
	// if (this->grade_ > 150)
	// 	throw std::range_error("The grade too low");
	// else if (this->grade_ < 1)
	// 	throw std::range_error("The grade too high");
}

void	Bureaucrat::signForm(const Form& form) const {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<Bureaucrat> signForm() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	this->grade_++;
	if (this->grade_ > 150)
		throw Bureaucrat::GradeTooLowException();
	// else if (this->grade_ < 1)
	// 	throw Bureaucrat::GradeTooHighException();
	// if (this->grade_ > 150)
	// 	throw std::range_error("The grade too low");
	// else if (this->grade_ < 1)
	// 	throw std::range_error("The grade too high");
}

// When an exception thrown
const char*	Bureaucrat::GradeTooHighException::what(void) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<Bureaucrat::GradeTooHighException> what() called\033[m" << std::endl;
	return ("The grade too high");
	// return (1);
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<Bureaucrat::GradeTooLowException> what() called\033[m" << std::endl;
	return ("The grade too low");
	// return (2);
}

// Insertion operator overload to print
std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& bc) {
	stream << bc.getName() << ", bureaucrat grade " << bc.getGrade() << ".";
	return (stream);
}
