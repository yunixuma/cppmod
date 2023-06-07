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

IMateriaSource::IMateriaSource(void) {
	std::cout << "\033[36;2;3m[" << this \
		<< "]<IMateriaSource> Constructor called (" << this->ideas_[0] << ")\033[m" << std::endl;
	for (size_t i = 0; i < 100; i++)
	{
		this->ideas_[i] = new std::string("(undefined)");
	}
	// std::cerr << this << " alloc [" << 0 << "]{" << this->ideas_[0] << "}" << std::endl;
}

IMateriaSource::IMateriaSource(const IMateriaSource& src) {
	std::cout << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<IMateriaSource> Copy constructor called (" << this->ideas_[0] << ")\033[m" << std::endl;
	// this->ideas_ = new std::string[100];
	for (size_t i = 0; i < 100; i++)
		this->ideas_[i] = new std::string(*src.ideas_[i]);
	// std::cerr << this << " alloc [" << 0 << "]{" << this->ideas_[0] << "}" << std::endl;
}

IMateriaSource&	IMateriaSource::operator=(const IMateriaSource& rhs) {
	std::cout << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<IMateriaSource> Copy assignment operator called (" << this->ideas_[0] << ")\033[m" << std::endl;
	if (this != &rhs)
	{
		for (size_t i = 0; i < 100; i++)
		{
			if (this->ideas_[i])
				delete this->ideas_[i];
			this->ideas_[i] = new std::string(*rhs.ideas_[i]);
		}
		// std::cerr << this << " alloc [" << 0 << "]{" << this->ideas_[0] << "}" << std::endl;
	}
	return (*this);
}

IMateriaSource::~IMateriaSource(void) {
	std::cout << "\033[31;2;3m[" << this \
		<< "]<IMateriaSource> Destructor called (" << this->ideas_[0] << ")\033[m" << std::endl;
	// std::cerr << this << " free [" << 0 << "]{" << this->ideas_[0] << "}" << std::endl;
	for (size_t i = 0; i < 100; i++)
	{
		if (this->ideas_[i])
		{
			delete this->ideas_[i];
			this->ideas_[i] = NULL;
		}
	}
}

const std::string*	IMateriaSource::getIdea(size_t idx) const {
	// if (!this->brain_[idx])
	// 	return ("(null)");
	return (this->ideas_[idx]);
}
