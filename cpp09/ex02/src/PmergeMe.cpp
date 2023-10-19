/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/20 04:21:42 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<PmergeMe> Constructor called" \
		<< "\033[m" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& src) {
	std::clog << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<PmergeMe> Copy constructor called" \
		<< "\033[m" << std::endl;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& rhs) {
	std::clog << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<PmergeMe> Copy assignment operator called" \
		<< "\033[m" << std::endl;
	// if (this != &rhs)
	// 	this->vals_ = rhs.vals_;
	return (*this);
}

PmergeMe::~PmergeMe(void) {
	std::clog << "\033[31;2;3m[" << this \
		<< "]<PmergeMe> Destructor called\033[m" << std::endl;
}

std::list<int>	PmergeMe::split2List(const std::string& str) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<PmergeMe> split2List called" << std::endl;
	std::clog << str << "\t<" << typeid(str).name() \
		<< ">\033[m" << std::endl;
	std::list<int>		lst;
	int					val = 0;
	std::stringstream	ss;

	ss << str;
	while (ss >> val) {
		if (val < 0)
			throw std::invalid_argument("negative number");
		lst.push_back(val);
		while (ss.peek() == ' ')
			ss.ignore();
		val = 0;
	}
	// std::clog << "val: " << val << std::endl;
	if (val == INT_MAX || val == INT_MIN)
		throw std::invalid_argument("overflow");
	if (!ss.eof())
		throw std::invalid_argument("not integer");
	// if (ss.fail() && !ss.eof())
	// 	throw std::invalid_argument("wrong argument");
	return (lst);
}

std::vector<int>	PmergeMe::list2Vector(const std::list<int>& lst) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<PmergeMe> split2List called" << std::endl;
	std::clog << &lst << "\t<" << typeid(lst).name() \
		<< ">\033[m" << std::endl;
	std::vector<int>	vec;
	std::list<int>::const_iterator	it = lst.begin();
	std::list<int>::const_iterator	ite = lst.end();
	while (it != ite)
		vec.push_back(*(it++));
	return (vec);
}

float	PmergeMe::sort(std::list<int>& lst) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<PmergeMe> sort called" << std::endl;
	std::clog << &lst << "\t<" << typeid(lst).name() \
		<< ">\033[m" << std::endl;
	clock_t	start = clock();
	int		tmp = 0;
	while (tmp >= 0)
		tmp++;
	clock_t	end = clock();
	std::clog << start << "\t" << end << "\t" \
		<< difftime(end, start) << std::endl;
	return (0.0f);
}

float	PmergeMe::sort(std::vector<int>& vec) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<PmergeMe> sort called" << std::endl;
	std::clog << &vec << "\t<" << typeid(vec).name() \
		<< ">\033[m" << std::endl;
	return (0.0f);
}

// When an exception thrown
// const char*	PmergeMe::SyntaxError::what(void) const throw() {
/*	std::clog << "\033[35;3m[" << this \
		<< "]<PmergeMe::SyntaxError> what() called\033[m" \
		<< std::endl;*/
// 	return ("Error: Syntax error");
// }
