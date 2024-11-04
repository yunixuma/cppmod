/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2024/11/04 23:23:25 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	// this->name_ = name;
	this->hitPoint_ = this->hitPointDefault_;
	this->hitPointMax_ = this->hitPointDefault_;
	this->energyPoint_ = this->energyPointDefault_;
	this->attackDamage_ = this->attackDamageDefault_;
	std::cout << "\033[36;2;3mCreating a FragTrap (" \
		<< this << ": " << name << ")\033[m" << std::endl;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src) {
	std::cout << "\033[36;2mCopy constructor of FragTrap called (" \
		<< &src << " -> " << this << ")\033[m" << std::endl;
	// this->name_ = src.name_;
	// this->hitPoint_ = src.hitPoint_;
	// this->hitPointMax_ = this->hitPointMax_;
	// this->energyPoint_ = src.energyPoint_;
	// this->attackDamage_ = src.attackDamage_;
}

FragTrap&	FragTrap::operator=(const FragTrap& rhs) {
	std::cout << "\033[36;2mCopy assignment operator of ClapTrap called (" \
		<< &rhs << " -> " << this << ")\033[m" << std::endl;
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
		// this->name_ = rhs.name_;
		// this->hitPoint_ = rhs.hitPoint_;
		// this->hitPoint_ = rhs.hitPointMax_;
		// this->energyPoint_ = rhs.energyPoint_;
		// this->attackDamage_ = rhs.attackDamage_;
	}
	return (*this);
}

FragTrap::~FragTrap(void) {
	std::cout << "\033[31;2;3mDestroying the FragTrap (" \
		<< this << ": " << ClapTrap::getName() << ")\033[m" << std::endl;
}

void	FragTrap::attack(const std::string& target) {
	std::cout << "\033[32mFragTrap ";
	ClapTrap::attack_common(target);
}

void	FragTrap::highFivesGuys(void) const {
	std::cout << "\033[36mFragTrap " << ClapTrap::getName() \
		<< " requests positive high fives\033[m" << std::endl;
}

/*
void	FragTrap::takeDamage(unsigned int amount) {
	unsigned int	hitPoint = ClapTrap::getHitPoint();
	if (hitPoint < amount)
		ClapTrap::setHitPoint(0);
	else
		ClapTrap::setHitPoint(hitPoint - amount);
	std::cout << "\033[32mFragTrap " << ClapTrap::getName() \
		<< " take damage and loses " << amount \
		<< " hit points!\033[m" << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount) {
	unsigned int	hitPoint = ClapTrap::getHitPoint();
	unsigned int	energyPoint = ClapTrap::getEnergyPoint();
	if (hitPoint == 0)
	{
		std::cout << "\033[32mFragTrap " << ClapTrap::getName() \
			<< " cannot be repaired," \
			<< " because no hit points left\033[m" << std::endl;
		return ;
	}
	else if (energyPoint == 0)
	{
		std::cout << "\033[32mFragTrap " << ClapTrap::getName() \
			<< " cannot be repaired," \
			<< " because no energy points left\033[m" << std::endl;
		return ;
	}
	ClapTrap::setHitPoint(hitPoint + amount);
	ClapTrap::setEnergyPoint(energyPoint - 1);
	std::cout << "\033[32mFragTrap " << ClapTrap::getName() \
		<< " is repaired and gets " << amount \
		<< " hit points!\033[m" << std::endl;
}
*/