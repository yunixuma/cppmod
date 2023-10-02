/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/02 11:29:31 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(int n) : N_(n) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<Span> Constructor called (" \
		<< this->N_ << ")\033[m" << std::endl;
}

Span::Span(const Span& src) : N_(src.N_), numbers_(src.numbers_) {
	std::clog << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<Span> Copy constructor called (" \
		<< this->N_ << ")\033[m" << std::endl;
	// this->name_ = src.name_;
	// this->grade_ = src.grade_;
	// if (this->grade_ > 150)
	// 	throw Span::GradeTooLowException();
	// else if (this->grade_ < 1)
	// 	throw Span::GradeTooHighException();
}

Span&	Span::operator=(const Span& rhs) {
	std::clog << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<Span> Copy assignment operator called (" \
		<< this->N_ << ")\033[m" << std::endl;
	if (this != &rhs)
	{
		this->N_ = rhs.N_;
		this->numbers_ = rhs.numbers_;
	}
	return (*this);
}

Span::~Span(void) {
	std::clog << "\033[31;2;3m[" << this \
		<< "]<Span> Destructor called (" \
		<< this->N_ << ")\033[m" << std::endl;
}

void	Span::addNumber(int num) {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<Span> addNumber() called (" \
		<< this->numbers_.size() << " / " << this->N_ \
		<< ")\033[m" << std::endl;
	if (this->numbers_.size() >= this->N_)
		throw Span::StoreFullException();
	this->numbers_.push_back(num);
	this->numbers_.sort();
}

int	Span::shortestSpan(void) const {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<Span> shortestSpan() called (" \
		<< this->numbers_.size() << " / " << this->N_ \
		<< ")\033[m" << std::endl;
	if (this->numbers_.size() == 0)
		throw Span::NoStoredException();
	else if (this->numbers_.size() == 1)
		throw Span::NoSpanException();
	std::list<int>::const_iterator itr = this->numbers_.begin();
	std::list<int>::const_iterator end = this->numbers_.end();

	int ret = INT_MAX;
	int	tmp;
	while (++itr != end) {
		tmp = - *(--itr) + *(++itr);
		if (tmp < ret)
			ret = tmp;
	}
	return (ret);
}

int	Span::longestSpan(void) const {
	std::clog << "\033[32;2;3m[" << this \
		<< "]<Span> longestSpan() called (" \
		<< this->numbers_.size() << " / " << this->N_ \
		<< ")\033[m" << std::endl;
	if (this->numbers_.size() == 0)
		throw Span::NoStoredException();
	else if (this->numbers_.size() == 1)
		throw Span::NoSpanException();
	int	num_max = this->numbers_.back();
	int	num_min = this->numbers_.front();
	return (num_max - num_min);
}

// When an exception thrown
const char*	Span::NoStoredException::what(void) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<Span::NoStoredException> what() called\033[m" << std::endl;
	return ("No numbers stored");
	// return (2);
}

const char*	Span::NoSpanException::what(void) const throw() {
	std::clog << "\033[35;2;3m[" << this \
		<< "]<Span::NoSpanException> what() called\033[m" << std::endl;
	return ("No span found");
	// return (1);
}

const char*	Span::StoreFullException::what(void) const throw() {
	std::clog << "\033[35;3m[" << this \
		<< "]<Span::StoreFullException> what() called\033[m" << std::endl;
	return ("The store is already full");
	// return (3);
}

// Debug
void	Span::debug(void) const {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<Span> debug() called (" \
		<< this->numbers_.size() << " / " << this->N_ \
		<< ")\033[m" << std::endl;
	std::list<int>::const_iterator itr = this->numbers_.begin();
	std::list<int>::const_iterator end = this->numbers_.end();
	unsigned int	i = 0;
	while (itr != end) {
		std::cout << i++ << "\t: " << *itr << std::endl;
		itr++;
	}
}
