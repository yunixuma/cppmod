/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2024/11/04 08:16:40 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) :
	FragTrap(), name_(name) {
	ClapTrap::name_ = name + "_clap_name";
	this->energyPoint_ = ScavTrap().getEnergyPoint();
	std::cout << "\033[36;2;3mCreating a DiamondTrap (" \
		<< this << ": " << name << ")\033[m" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) \
	: ClapTrap(src), ScavTrap(src), FragTrap(src), name_(src.name_) {
	std::cout << "\033[36;2mCopy constructor of DiamondTrap called (" \
		<< &src << " -> " << this << ")\033[m" << std::endl;
	// this->name_ = src.name_;
	// this->hitPoint_ = src.hitPoint_;
	this->hitPointMax_ = src.hitPointMax_;
	// this->energyPoint_ = src.energyPoint_;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& rhs) {
	std::cout << "\033[36;2mCopy assignment operator of ClapTrap called (" \
		<< &rhs << " -> " << this << ")\033[m" << std::endl;
	if (this != &rhs)
	{
		this->name_ = rhs.name_;
		this->hitPoint_ = rhs.hitPoint_;
		this->hitPointMax_ = rhs.hitPointMax_;
		this->energyPoint_ = rhs.energyPoint_;
		this->attackDamage_ = rhs.attackDamage_;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "\033[31;2;3mDestroying the DiamondTrap (" \
		<< this << ": " << ClapTrap::getName() << ")\033[m" << std::endl;
}

void	DiamondTrap::attack(const std::string& target) {
	// std::cout << "\033[32mDiamondTrap ";
	// ClapTrap::attack_common(target);
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) const {
	std::cout << "\033[36mDiamondTrap characteristic name: " << this->name_ \
		<< "; ClapTrap name: " << ClapTrap::getName() << "\033[m" << std::endl;
}

const std::string&	DiamondTrap::getName(void) const {
//	std::cerr << "\033[2;3mgetName member function called\033[m" << std::endl;
	return (this->name_);
}
