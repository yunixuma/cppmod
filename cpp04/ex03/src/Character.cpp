/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/08 02:25:18 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp

Character::Character(const std::string& name) : name_(name) {
	std::cerr << "\033[36;2;3m[" << this \
		<< "]<Character> Constructor called (" << this->name_ << ")\033[m" << std::endl;
}

Character::Character(const Character& src) {
	std::cerr << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<Character> Copy constructor called (" << this->name_ << ")\033[m" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (src.slot_[i])
			this->slot_[i] = new AMateria(src.slot_[i]);
	}
}

Character&	Character::operator=(const Character& rhs) {
	std::cerr << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<Character> Copy assignment operator called (" << this->name_ << ")\033[m" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (rhs.slot_[i])
			this->slot_[i] = new AMateria(rhs.slot_[i]);
	}
	return (*this);
}

Character::~Character(void) {
	std::cerr << "\033[31;2;3m[" << this \
		<< "]<Character> Destructor called (" << this->name_ << ")\033[m" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->slot_[i])
		{
			delete this->slot_[i];
			this->slot_[i] = NULL;
		}
	}
}

const std::string&	Character::getName(void) const {
	return (this->name_);
}

void	equip(AMateria* m) {
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!this->slot_[i])
			this->slot_[i] = m;
	}
}

void	unequip(int idx) {
	if (0 <= idx && idx < 4)
		this->slot_[idx] = NULL;
}

void	use(int idx, ICharacter& target) {
	if (0 < idx || idx >= 4)
		return ;
	AMateria*	m = this->slot_[idx];
	if (m)
		m->use(target);
}
