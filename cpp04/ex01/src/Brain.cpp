/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/06 12:07:07 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {

	std::cout << "\033[36;2;3mCreating a Brain (" \
		<< ")\033[m" << std::endl;
}

Brain::Brain(const Brain& src) {
	std::cout << "\033[36;2mCopy constructor of Brain called (" \
		<< &src << " -> " << this << ")\033[m" << std::endl;
	for (size_t i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
}

Brain&	Brain::operator=(const Brain& rhs) {
	std::cout << "\033[36;2mCopy assignment operator of Brain called (" \
		<< &rhs << " -> " << this << ")\033[m" << std::endl;
	if (this != &rhs)
	{
		for (size_t i = 0; i < 100; i++)
			this->ideas[i] = rhs.ideas[i];
	}
	return (*this);
}

Brain::~Brain(void) {
	std::cout << "\033[31;2;3mDestroying the Brain (" \
		<< this << ")\033[m" << std::endl;
}
