/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/07 15:56:40 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"

B::B(void) {
	std::cout << "\033[36;2;3m[" << this \
		<< "]<B> Constructor called\033[m" << std::endl;
	// this->type = "B";
}

B::B(const B& src) : Base(src) {
	std::cout << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<B> Copy constructor called (" << this->type << ")\033[m" << std::endl;
	// this->type = src.type;
}

B&	B::operator=(const B& rhs) {
	std::cout << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<B> Copy assignment operator called (" << this->type << ")\033[m" << std::endl;
	if (this != &rhs)
	{
		Base::operator=(rhs);
		// this->type = rhs.type;
	}
	return (*this);
}

B::~B(void) {
	std::cout << "\033[31;2;3m[" << this \
		<< "]<B> Destructor called (" << this->type << ")\033[m" << std::endl;
}
