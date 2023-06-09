/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IIMateriaSource.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/07 16:57:24 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
/*
IMateriaSource::IMateriaSource(const IMateriaSource& src) {
	std::cerr << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<IMateriaSource> Copy constructor called (" << this->name_ << ")\033[m" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (src.slot_[i])
			this->slot_[i] = new AMateria(src.slot_[i]);
	}
}

IMateriaSource&	IMateriaSource::operator=(const IMateriaSource& rhs) {
	std::cerr << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<IMateriaSource> Copy assignment operator called (" << this->name_ << ")\033[m" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (rhs.slot_[i])
			this->slot_[i] = new AMateria(rhs.slot_[i]);
	}
	return (*this);
}
*//*
IMateriaSource::~IMateriaSource(void) {
	std::cerr << "\033[31;2;3m[" << this \
		<< "]<IMateriaSource> Destructor called (" << this->name_ << ")\033[m" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->slot_[i])
		{
			delete this->slot_[i];
			this->slot_[i] = NULL;
		}
	}
}
*/