/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/10 18:00:22 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) \
	: name_(name), grade_(grade) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<Bureaucrat> Constructor called (" \
		<< this->name_ << ")\033[m" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) \
	: name_(src.name_), grade_(src.grade_) {
	std::clog << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<Bureaucrat> Copy constructor called (" \
		<< this->name_ << ")\033[m" << std::endl;
	// this->name_ = src.name_;
	// this->grade_ = src.grade_;
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
}

int	Bureaucrat::getGrade(void) const {
	std::clog << "\033[32m[" << this \
		<< "]<Bureaucrat> getGrade() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	
}

void	Bureaucrat::incrementGrade(void) {
	std::clog << "\033[32m[" << this \
		<< "]<Bureaucrat> incrementGrade() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	this->grade--;
}

void	Bureaucrat::decrementGrade(void) {
	std::clog << "\033[32m[" << this \
		<< "]<Bureaucrat> decrementGrade() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	this->grade++;
}

// Insertion operator overload to print
std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& bc) {
	stream << bc.getName() << ", bureaucrat grade " << bc.getGrade << ".";
	return (stream);
}
