/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/09 11:35:53 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	std::cerr << "\033[36;2;3m[" << this \
		<< "]<MateriaSource> Constructor called\033[m" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& src) {
	std::cerr << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<MateriaSource> Copy constructor called (" << this->name_ << ")\033[m" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (src.slot_[i])
			this->slot_[i] = new AMateria(src.slot_[i]);
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& rhs) {
	std::cerr << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<MateriaSource> Copy assignment operator called (" << this->name_ << ")\033[m" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (rhs.slot_[i])
			this->slot_[i] = new AMateria(rhs.slot_[i]);
	}
	return (*this);
}

MateriaSource::~MateriaSource(void) {
	std::cerr << "\033[31;2;3m[" << this \
		<< "]<MateriaSource> Destructor called (" << this->name_ << ")\033[m" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->slot_[i])
		{
			delete this->slot_[i];
			this->slot_[i] = NULL;
		}
	}
}
