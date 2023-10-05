/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonthlyData.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/06 02:31:38 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MonthlyData.hpp"

MonthlyData::MonthlyData(const std::string& name, int grade) \
	: name_(name), grade_(grade) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<MonthlyData> Constructor called (" \
		<< this->name_ << ")\033[m" << std::endl;
	if (this->grade_ > 150)
		throw MonthlyData::GradeTooLowException();
	else if (this->grade_ < 1)
		throw MonthlyData::GradeTooHighException();
}

MonthlyData::MonthlyData(const MonthlyData& src) \
	: name_(src.name_), grade_(src.grade_) {
	std::clog << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<MonthlyData> Copy constructor called (" \
		<< this->name_ << ")\033[m" << std::endl;
	// this->name_ = src.name_;
	// this->grade_ = src.grade_;
	if (this->grade_ > 150)
		throw MonthlyData::GradeTooLowException();
	else if (this->grade_ < 1)
		throw MonthlyData::GradeTooHighException();
}

MonthlyData&	MonthlyData::operator=(const MonthlyData& rhs) {
	std::clog << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<MonthlyData> Copy assignment operator called (" \
		<< this->name_ << ")\033[m" << std::endl;
	if (this != &rhs)
	{
		const_cast<std::string&>(this->name_) = rhs.name_;
		this->grade_ = rhs.grade_;
	}
	if (this->grade_ > 150)
		throw MonthlyData::GradeTooLowException();
	else if (this->grade_ < 1)
		throw MonthlyData::GradeTooHighException();
	return (*this);
}

MonthlyData::~MonthlyData(void) {
	std::clog << "\033[31;2;3m[" << this \
		<< "]<MonthlyData> Destructor called (" \
		<< this->name_ << ")\033[m" << std::endl;
}

const std::string&	MonthlyData::getName(void) const {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<MonthlyData> getName() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	return (this->name_);
}

int	MonthlyData::getGrade(void) const {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<MonthlyData> getGrade() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	return (this->grade_);
}

void	MonthlyData::incrementGrade(void) {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<MonthlyData> incrementGrade() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	this->grade_--;
	// if (this->grade_ > 150)
	// 	throw MonthlyData::GradeTooLowException();
	if (this->grade_ < 1)
		throw MonthlyData::GradeTooHighException();
	// if (this->grade_ > 150)
	// 	throw std::range_error("The grade too low");
	// else if (this->grade_ < 1)
	// 	throw std::range_error("The grade too high");
}

void	MonthlyData::decrementGrade(void) {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<MonthlyData> decrementGrade() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	this->grade_++;
	if (this->grade_ > 150)
		throw MonthlyData::GradeTooLowException();
	// else if (this->grade_ < 1)
	// 	throw MonthlyData::GradeTooHighException();
	// if (this->grade_ > 150)
	// 	throw std::range_error("The grade too low");
	// else if (this->grade_ < 1)
	// 	throw std::range_error("The grade too high");
}

// When an exception thrown
const char*	MonthlyData::GradeTooHighException::what(void) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<MonthlyData::GradeTooHighException> what() called\033[m" << std::endl;
	return ("The grade too high");
	// return (1);
}

const char*	MonthlyData::GradeTooLowException::what(void) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<MonthlyData::GradeTooLowException> what() called\033[m" << std::endl;
	return ("The grade too low");
	// return (2);
}

// Insertion operator overload to print
std::ostream&	operator<<(std::ostream& stream, const MonthlyData& bc) {
	stream << bc.getName() << ", bureaucrat grade " << bc.getGrade() << ".";
	return (stream);
}
