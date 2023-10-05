/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/06 02:27:55 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& name, int grade) \
	: name_(name), grade_(grade) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<BitcoinExchange> Constructor called (" \
		<< this->name_ << ")\033[m" << std::endl;
	if (this->grade_ > 150)
		throw BitcoinExchange::GradeTooLowException();
	else if (this->grade_ < 1)
		throw BitcoinExchange::GradeTooHighException();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) \
	: name_(src.name_), grade_(src.grade_) {
	std::clog << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<BitcoinExchange> Copy constructor called (" \
		<< this->name_ << ")\033[m" << std::endl;
	// this->name_ = src.name_;
	// this->grade_ = src.grade_;
	if (this->grade_ > 150)
		throw BitcoinExchange::GradeTooLowException();
	else if (this->grade_ < 1)
		throw BitcoinExchange::GradeTooHighException();
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& rhs) {
	std::clog << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<BitcoinExchange> Copy assignment operator called (" \
		<< this->name_ << ")\033[m" << std::endl;
	if (this != &rhs)
	{
		const_cast<std::string&>(this->name_) = rhs.name_;
		this->grade_ = rhs.grade_;
	}
	if (this->grade_ > 150)
		throw BitcoinExchange::GradeTooLowException();
	else if (this->grade_ < 1)
		throw BitcoinExchange::GradeTooHighException();
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void) {
	std::clog << "\033[31;2;3m[" << this \
		<< "]<BitcoinExchange> Destructor called (" \
		<< this->name_ << ")\033[m" << std::endl;
}

const std::string&	BitcoinExchange::getName(void) const {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<BitcoinExchange> getName() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	return (this->name_);
}

int	BitcoinExchange::getGrade(void) const {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<BitcoinExchange> getGrade() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	return (this->grade_);
}

void	BitcoinExchange::incrementGrade(void) {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<BitcoinExchange> incrementGrade() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	this->grade_--;
	// if (this->grade_ > 150)
	// 	throw BitcoinExchange::GradeTooLowException();
	if (this->grade_ < 1)
		throw BitcoinExchange::GradeTooHighException();
	// if (this->grade_ > 150)
	// 	throw std::range_error("The grade too low");
	// else if (this->grade_ < 1)
	// 	throw std::range_error("The grade too high");
}

void	BitcoinExchange::decrementGrade(void) {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<BitcoinExchange> decrementGrade() called (" \
		<< this->name_ << ")\033[m" << std::endl;
	this->grade_++;
	if (this->grade_ > 150)
		throw BitcoinExchange::GradeTooLowException();
	// else if (this->grade_ < 1)
	// 	throw BitcoinExchange::GradeTooHighException();
	// if (this->grade_ > 150)
	// 	throw std::range_error("The grade too low");
	// else if (this->grade_ < 1)
	// 	throw std::range_error("The grade too high");
}

// When an exception thrown
const char*	BitcoinExchange::GradeTooHighException::what(void) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<BitcoinExchange::GradeTooHighException> what() called\033[m" << std::endl;
	return ("The grade too high");
	// return (1);
}

const char*	BitcoinExchange::GradeTooLowException::what(void) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<BitcoinExchange::GradeTooLowException> what() called\033[m" << std::endl;
	return ("The grade too low");
	// return (2);
}

// Insertion operator overload to print
std::ostream&	operator<<(std::ostream& stream, const BitcoinExchange& bc) {
	stream << bc.getName() << ", bureaucrat grade " << bc.getGrade() << ".";
	return (stream);
}
