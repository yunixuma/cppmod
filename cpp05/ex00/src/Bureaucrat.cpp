/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/11 16:01:57 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) \
	: name_(name), grade_(grade) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<Bureaucrat> Constructor called (" \
		<< this->name_ << ")\033[m" << std::endl;
	if (this->grade_ > 150)
		throw this->GradeTooLowException();
	else if (this->grade_ < 1)
		throw this->GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) \
	: name_(src.name_), grade_(src.grade_) {
	std::clog << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<Bureaucrat> Copy constructor called (" \
		<< this->name_ << ")\033[m" << std::endl;
	// this->name_ = src.name_;
	// this->grade_ = src.grade_;
	if (this->grade_ > 150)
		throw this->GradeTooLowException();
	else if (this->grade_ < 1)
		throw this->GradeTooHighException();
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& rhs) {
	std::clog << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<Bureaucrat> Copy assignment operator called (" \
		<< this->name_ << ")\033[m" << std::endl;
	if (this != &rhs)
	{
		this->name_ = rhs.name_;
		this->grade_ = rhs.grade_;
	}
	if (this->grade_ > 150)
		throw this->GradeTooLowException();
	else if (this->grade_ < 1)
		throw this->GradeTooHighException();
	return (*this);
}

Bureaucrat::~Bureaucrat(void) {
	std::clog << "\033[31;2;3m[" << this \
		<< "]<Bureaucrat> Destructor called (" \
		<< this->name_ << ")\033[m" << std::endl;
}

const std::string&	Bureaucrat::getName(void) const {
	std::clog << "\033[32m[" << this \
		<< "]<Bureaucrat> getName() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	return (this->name_);
}

int	Bureaucrat::getGrade(void) const {
	std::clog << "\033[32m[" << this \
		<< "]<Bureaucrat> getGrade() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	return (this->grade_);
}

void	Bureaucrat::incrementGrade(void) {
	std::clog << "\033[32m[" << this \
		<< "]<Bureaucrat> incrementGrade() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	this->grade_--;
	if (this->grade_ > 150)
		throw std::range_error("The grade too low");
	else if (this->grade_ < 1)
		throw std::range_error("The grade too high");
	// if (this->grade_ > 150)
	// 	throw this->GradeTooLowException();
	// else if (this->grade_ < 1)
	// 	throw this->GradeTooHighException();
}

void	Bureaucrat::decrementGrade(void) {
	std::clog << "\033[32m[" << this \
		<< "]<Bureaucrat> decrementGrade() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	this->grade_++;
	if (this->grade_ > 150)
		throw std::range_error("The grade too low");
	else if (this->grade_ < 1)
		throw std::range_error("The grade too high");
	// if (this->grade_ > 150)
	// 	throw this->GradeTooLowException();
	// else if (this->grade_ < 1)
	// 	throw this->GradeTooHighException();
}

// When an exception thrown
int	Bureaucrat::GradeTooHighException(void) {
	std::clog << "\033[32m[" << this \
		<< "]<Bureaucrat> GradeTooHighException() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	return (1);
}

int	Bureaucrat::GradeTooLowException() {
	std::clog << "\033[32m[" << this \
		<< "]<Bureaucrat> GradeTooLowException() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	return (2);
}

// Insertion operator overload to print
std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& bc) {
	stream << bc.getName() << ", bureaucrat grade " << bc.getGrade() << ".";
	return (stream);
}
