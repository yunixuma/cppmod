/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/07 15:57:09 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"

C::C(void) {
	std::cout << "\033[36;2;3m[" << this \
		<< "]<C> Constructor called (" << this->type << ")\033[m" << std::endl;
	this->type = "C";
}

C::C(const C& src) : Base(src) {
	std::cout << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<C> Copy constructor called (" << this->type << ")\033[m" << std::endl;
	// this->type = src.type;
}

C&	C::operator=(const C& rhs) {
	std::cout << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<C> Copy assignment operator called (" << this->type << ")\033[m" << std::endl;
	if (this != &rhs)
	{
		Base::operator=(rhs);
		// this->type = rhs.type;
	}
	return (*this);
}

C::~C(void) {
	std::cout << "\033[31;2;3m[" << this \
		<< "]<C> Destructor called (" << this->type << ")\033[m" << std::endl;
}
