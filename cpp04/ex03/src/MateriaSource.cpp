/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/09 22:49:54 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	std::cerr << "\033[36;2;3m[" << this \
		<< "]<MateriaSource> Constructor called\033[m" << std::endl;
	for (int i = 0; i < 4; i++)
		this->store_[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& src) {
	std::cerr << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<MateriaSource> Copy constructor called\033[m" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (src.store_[i])
			this->store_[i] = src.store_[i]->clone();
		else
			this->store_[i] = NULL;
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& rhs) {
	std::cerr << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<MateriaSource> Copy assignment operator called\033[m" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (rhs.store_[i])
			this->store_[i] = rhs.store_[i]->clone();
		else
			this->store_[i] = NULL;
	}
	return (*this);
}

MateriaSource::~MateriaSource(void) {
	std::cerr << "\033[31;2;3m[" << this \
		<< "]<MateriaSource> Destructor called\033[m" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->store_[i])
		{
			delete this->store_[i];
			this->store_[i] = NULL;
		}
	}
}

void	MateriaSource::learnMateria(AMateria* src) {
	std::cerr << "\033[33;2;3m[" << this \
		<< "]<MateriaSource> learnMateria() called (" << src->getType() << ")\033[m" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (!this->store_[i])
		{
			this->store_[i] = src;
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	std::cerr << "\033[33;2;3m[" << this \
		<< "]<MateriaSource> createMateria() called (" << type << ")\033[m" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->store_[i] && this->store_[i]->getType() == type)
			return (this->store_[i]->clone());
	}
	return (NULL);
}
