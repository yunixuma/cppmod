/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/07/10 15:19:23 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
/*
Base::Base(void) {
	std::cout << "\033[36;2;3m[" << this \
		<< "]<Base> Constructor called (" << this->type << ")\033[m" << std::endl;
}

Base::Base(const Base& src) {
	std::cout << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<Base> Copy constructor called (" << this->type << ")\033[m" << std::endl;
	// this->type = src.type;
}

Base&	Base::operator=(const Base& rhs) {
	std::cout << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<Base> Copy assignment operator called (" << this->type << ")\033[m" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}
*/
Base::~Base(void) {
	std::cout << "\033[31;2;3m[" << this \
		<< "]<Base> Destructor called\033[m" << std::endl;
}
