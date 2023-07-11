/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/07/11 16:46:53 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->name_ = name;
	this->weapon_ = NULL;
	std::cout << "\033[36;2;3m" << "Creating a humanB (" \
		<< this << ": " << this->name_ << ")\033[m" << std::endl;
}

HumanB::~HumanB(void) {
	std::cout << "\033[31;2;3m" << "Destroying the humanB (" \
		<< this << ": " << this->name_ << ")\033[m" << std::endl;
}

std::string	HumanB::getName(void) const {
	return (this->name_);
}

void	HumanB::setName(std::string name) {
	std::cout << "\033[2;3m" << "Rename " << this << ": " \
		<< this->name_ << " -> " << name << "\033[m" << std::endl;
	this->name_ = name;
}

Weapon*	HumanB::getWeapon() const {
	return (this->weapon_);
}

void	HumanB::setWeapon(Weapon& weapon) {
	if (this->weapon_) {
		std::cout << "\033[2;3m" << "Switching the equipment (" << this << ": " \
			<< this->weapon_->getType() << " -> " << weapon.getType() << ")\033[m" << std::endl;
	} else {
		std::cout << "\033[2;3m" << "Equipping (" << this << ": " \
			<< weapon.getType() << ")\033[m" << std::endl;
	}
	this->weapon_ = &weapon;
}

void	HumanB::attack(void) const {
	std::cout << "\033[33m" << this->name_;
	if (this->weapon_)
		std::cout << " attacks with their " << this->weapon_->getType() << "\033[m" << std::endl;
	else
		std::cout << " cannot attack" << "\033[m" << std::endl;
}
