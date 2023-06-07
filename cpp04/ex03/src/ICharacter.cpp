/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/08 02:25:18 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp

ICharacter::ICharacter(void) {
	std::cerr << "\033[36;2;3m[" << this \
		<< "]<ICharacter> Constructor called (" << this->ideas_[0] << ")\033[m" << std::endl;
	for (size_t i = 0; i < 100; i++)
	{
		this->ideas_[i] = new std::string("(undefined)");
	}
	// std::cerr << this << " alloc [" << 0 << "]{" << this->ideas_[0] << "}" << std::endl;
}

ICharacter::ICharacter(const ICharacter& src) {
	std::cerr << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<ICharacter> Copy constructor called (" << this->ideas_[0] << ")\033[m" << std::endl;
	// this->ideas_ = new std::string[100];
	for (size_t i = 0; i < 100; i++)
		this->ideas_[i] = new std::string(*src.ideas_[i]);
	// std::cerr << this << " alloc [" << 0 << "]{" << this->ideas_[0] << "}" << std::endl;
}

ICharacter&	ICharacter::operator=(const ICharacter& rhs) {
	std::cerr << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<ICharacter> Copy assignment operator called (" << this->ideas_[0] << ")\033[m" << std::endl;
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

ICharacter::~ICharacter(void) {
	std::cerr << "\033[31;2;3m[" << this \
		<< "]<ICharacter> Destructor called (" << this->ideas_[0] << ")\033[m" << std::endl;
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

const std::string*	ICharacter::getIdea(size_t idx) const {
	// if (!this->brain_[idx])
	// 	return ("(null)");
	return (this->ideas_[idx]);
}
