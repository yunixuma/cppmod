/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/07/10 15:33:08 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"

A::A(void) {
	std::cout << "\033[36;2;3m[" << this \
		<< "]<A> Constructor called\033[m" << std::endl;
	// this->type = "A";
}
/*
A::A(const A& src) : Base(src) {
	std::cout << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<A> Copy constructor called\033[m" << std::endl;
	// this->type = src.type;
}

A&	A::operator=(const A& rhs) {
	std::cout << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<A> Copy assignment operator called\033[m" << std::endl;
	if (this != &rhs)
	{
		Base::operator=(rhs);
		// this->type = rhs.type;
	}
	return (*this);
}
*/
A::~A(void) {
	std::cout << "\033[31;2;3m[" << this \
		<< "]<A> Destructor called\033[m" << std::endl;
}
