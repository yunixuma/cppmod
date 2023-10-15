/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/15 20:00:50 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) \
	: vals_() {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<RPN> Constructor called" \
		<< "\033[m" << std::endl;
}

RPN::RPN(const RPN& src) \
	: vals_(src.vals_) {
	std::clog << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<RPN> Copy constructor called" \
		<< "\033[m" << std::endl;
}

RPN&	RPN::operator=(const RPN& rhs) {
	std::clog << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<RPN> Copy assignment operator called" \
		<< "\033[m" << std::endl;
	if (this != &rhs)
		this->vals_ = rhs.vals_;
	return (*this);
}

RPN::~RPN(void) {
	std::clog << "\033[31;2;3m[" << this \
		<< "]<RPN> Destructor called\033[m" << std::endl;
}

void	RPN::tokenize(std::string::iterator& it) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<RPN> tokenize called" \
		<< "\033[m" << std::endl;
	if (std::strchr(CHRS_NUM, *it)) {
		stackVal(*it - '0');
	}
	else if (std::strchr(CHRS_OPER, *it))
		operation(*it);
	else if (!std::strchr(CHRS_SPACE, *it))
		throw InvalidTokenError();
}

void	RPN::stackVal(int val) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<RPN> stackVal called" \
		<< "\033[m" << std::endl;
	vals_.push(val);
}

void	RPN::operation(char oper) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<RPN> operation called" \
		<< "\033[m" << std::endl;
	if (vals_.size() < 2)
		throw SyntaxError();
	int	val2 = vals_.top();
	vals_.pop();
	int	val1 = vals_.top();
	vals_.pop();
	vals_.push(calc(val1, val2, oper));
}

int	RPN::calc(int val1, int val2, char oper) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<RPN> calc called" \
		<< "\033[m" << std::endl;
	switch (oper) {
		case '+':
			return (val1 + val2);
		case '-':
			return (val1 - val2);
		case '*':
			return (val1 * val2);
		case '/':
			if (val2 == 0)
				throw DivideByZeroException();
			return (val1 / val2);
		default:
			throw SyntaxError();
	}
}

int	RPN::getResult(void) const {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<RPN> result called" \
		<< "\033[m" << std::endl;
	if (vals_.size() > 1)
		throw NotConcludedException();
	else if (vals_.size() == 0)
		throw NoStacksException();
	return (vals_.top());
}

// When an exception thrown
const char*	RPN::SyntaxError::what(void) const throw() {
/*	std::clog << "\033[35;3m[" << this \
		<< "]<RPN::SyntaxError> what() called\033[m" \
		<< std::endl;*/
	return ("Error: Syntax error");
}

const char*	RPN::InvalidTokenError::what(void) const throw() {
/*	std::clog << "\033[35;3m[" << this \
		<< "]<RPN::InvaldTokenError> what() called\033[m" \
		<< std::endl;*/
	return ("Error: Invalid token detected");
}

const char*	RPN::DivideByZeroException::what(void) const throw() {
/*	std::clog << "\033[35;3m[" << this \
		<< "]<RPN::DivideByZeroException> what() called\033[m" \
		<< std::endl;*/
	return ("Error: Divide by zero");
}

const char*	RPN::NoStacksException::what(void) const throw() {
/*	std::clog << "\033[35;3m[" << this \
		<< "]<RPN::NoStacksException> what() called\033[m" \
		<< std::endl;*/
	return ("Error: No input");
}

const char*	RPN::NotConcludedException::what(void) const throw() {
/*	std::clog << "\033[35;3m[" << this \
		<< "]<RPN::NotConcludedException> what() called\033[m" \
		<< std::endl;*/
	return ("Error: The expression is not concluded");
}
