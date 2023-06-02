/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/02 13:29:29 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) {
	this->name_ = name;
	this->hitPoint_ = 10;
	this->energyPoint_ = 10;
	this->attackDamage_ = 0;
	std::cout << "\033[36;2;3m" << "Creating a ClapTrap (" \
		<< this << ": " << this->name_ << ")\033[m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src) {
	std::cerr << "\033[36;2m" << "Copy constructor called\033[m" << std::endl;
	this->name_ = src.name_;
	this->hitPoint_ = src.hitPoint_;
	this->energyPoint_ = src.energyPoint_;
	this->attackDamage_ = src.attackDamage_;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& rhs) {
	std::cerr << "\033[36;2m" << "Copy assignment operator called\033[m" << std::endl;
	if (this != &rhs)
	{
		this->name_ = rhs.name_;
		this->hitPoint_ = rhs.hitPoint_;
		this->energyPoint_ = rhs.energyPoint_;
		this->attackDamage_ = rhs.attackDamage_;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void) {
	std::cout << "\033[31;2;3m" << "Destroying the ClapTrap (" \
		<< this << ": " << this->name_ << ")\033[m" << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	if (this->hitPoint_ == 0)
	{
		std::cout << "\033[32m" << "ClapTrap " << this->name_ \
			<< " cannot attack," \
			<< " because no hit points left\033[m" << std::endl;
		return ;
	}
	else if (this->energyPoint_ == 0)
	{
		std::cout << "\033[32m" << "ClapTrap " << this->name_ \
			<< " cannot attack," \
			<< " because no energy points left\033[m" << std::endl;
		return ;
	}
	this->energyPoint_ -= 1;
	std::cout << "\033[32m" << "ClapTrap " << this->name_ \
		<< " attacks " << target << ", causing " << this->attackDamage_ \
		<< " points of damage!\033[m" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->hitPoint_ < amount)
		this->hitPoint_ = 0;
	else
		this->hitPoint_ -= amount;
	std::cout << "\033[32m" << "ClapTrap " << this->name_ \
		<< " take damage and loses " << amount \
		<< " hit points!\033[m" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->hitPoint_ == 0)
	{
		std::cout << "\033[32m" << "ClapTrap " << this->name_ \
			<< " cannot be repaired," \
			<< " because no hit points left\033[m" << std::endl;
		return ;
	}
	else if (this->energyPoint_ == 0)
	{
		std::cout << "\033[32m" << "ClapTrap " << this->name_ \
			<< " cannot be repaired," \
			<< " because no energy points left\033[m" << std::endl;
		return ;
	}
	this->hitPoint_ += amount;
	this->energyPoint_ -= 1;
	std::cout << "\033[32m" << "ClapTrap " << this->name_ \
		<< " is repaired and gets " << amount \
		<< " hit points!\033[m" << std::endl;
}

const std::string&	ClapTrap::getName(void) const {
//	std::cerr << "\033[2;3m" << "getName member function called\033[m" << std::endl;
	return (this->name_);
}

unsigned int	ClapTrap::getHitPoint(void) const {
//	std::cerr << "\033[2;3m" << "getHitPoint member function called\033[m" << std::endl;
	return (this->hitPoint_);
}

unsigned int	ClapTrap::getEnergyPoint(void) const {
//	std::cerr << "\033[2;3m" << "getEnergyPoint member function called\033[m" << std::endl;
	return (this->energyPoint_);
}

unsigned int	ClapTrap::getAttackDamage(void) const {
//	std::cerr << "\033[2;3m" << "getAttackDamage member function called\033[m" << std::endl;
	return (this->attackDamage_);
}

void	ClapTrap::setName(const std::string& name) {
//	std::cerr << "\033[2;3m" << "setHitPoint member function called\033[m" << std::endl;
	this->name_ = name;
}

void	ClapTrap::setHitPoint(unsigned int hitPoint) {
//	std::cerr << "\033[2;3m" << "setHitPoint member function called\033[m" << std::endl;
	this->hitPoint_ = hitPoint;
}

void	ClapTrap::setEnergyPoint(unsigned int energyPoint) {
//	std::cerr << "\033[2;3m" << "setEnergyPoint member function called\033[m" << std::endl;
	this->energyPoint_ = energyPoint;
}

void	ClapTrap::setAttackDamage(unsigned int attackDamage) {
//	std::cerr << "\033[2;3m" << "setAttackDamage member function called\033[m" << std::endl;
	this->attackDamage_ = attackDamage;
}
