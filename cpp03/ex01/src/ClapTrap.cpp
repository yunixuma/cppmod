/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2024/11/04 06:48:01 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) \
	: name_(name), \
		hitPoint_(10), hitPointMax_(hitPoint_), \
		energyPoint_(10), \
		attackDamage_(0) {
	std::cout << "\033[36;2;3mCreating a ClapTrap (" \
		<< this << ": " << this->name_ << ")\033[m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src) \
	: name_(src.name_), \
		hitPoint_(src.hitPoint_), \
		energyPoint_(src.energyPoint_), \
		attackDamage_(src.attackDamage_) {
	std::cout << "\033[36;2mCopy constructor of ClapTrap called (" \
		<< &src << " -> " << this << ")\033[m" << std::endl;
	// this->name_ = src.name_;
	// this->hitPoint_ = src.hitPoint_;
	// this->energyPoint_ = src.energyPoint_;
	// this->attackDamage_ = src.attackDamage_;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& rhs) {
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

ClapTrap::~ClapTrap(void) {
	std::cout << "\033[31;2;3mDestroying the ClapTrap (" \
		<< this << ": " << this->name_ << ")\033[m" << std::endl;
}

void	ClapTrap::attack_common(const std::string& target) {
	std::cout << this->name_;
	if (this->hitPoint_ == 0)
	{
		std::cout << " cannot attack," \
		<< " because no hit points left\033[m" << std::endl;
		return ;
	}
	else if (this->energyPoint_ == 0)
	{
		std::cout << "\033[32mClapTrap " << this->name_ \
			<< " cannot attack," \
			<< " because no energy points left\033[m" << std::endl;
		return ;
	}
	this->energyPoint_ -= 1;
	std::cout << " attacks " << target << ", causing " \
		<< this->attackDamage_ << " points of damage!\033[m" << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	std::cout << "\033[32mClapTrap ";
	this->attack_common(target);
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->hitPoint_ < amount)
		this->hitPoint_ = 0;
	else
		this->hitPoint_ -= amount;
	std::cout << "\033[32m" << this->name_ \
		<< " take damage and loses " << amount \
		<< " hit points!\033[m" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->hitPoint_ == 0)
	{
		std::cout << "\033[32m" << this->name_ \
			<< " cannot be repaired," \
			<< " because no hit points left\033[m" << std::endl;
		return ;
	}
	else if (this->energyPoint_ == 0)
	{
		std::cout << "\033[32mClapTrap " << this->name_ \
			<< " cannot be repaired," \
			<< " because no energy points left\033[m" << std::endl;
		return ;
	}
	if (this->hitPoint_ > this->hitPointMax_ + amount)
		this->hitPoint_ = this->hitPointMax_;
	else
		this->hitPoint_ += amount;
	this->energyPoint_ -= 1;
	std::cout << "\033[32mClapTrap " << this->name_ \
		<< " is repaired and gets " << amount \
		<< " hit points!\033[m" << std::endl;
}

const std::string&	ClapTrap::getName(void) const {
//	std::cerr << "\033[2;3mgetName member function called\033[m" << std::endl;
	return (this->name_);
}

unsigned int	ClapTrap::getHitPoint(void) const {
//	std::cerr << "\033[2;3mgetHitPoint member function called\033[m" << std::endl;
	return (this->hitPoint_);
}

unsigned int	ClapTrap::getEnergyPoint(void) const {
//	std::cerr << "\033[2;3mgetEnergyPoint member function called\033[m" << std::endl;
	return (this->energyPoint_);
}

unsigned int	ClapTrap::getAttackDamage(void) const {
//	std::cerr << "\033[2;3mgetAttackDamage member function called\033[m" << std::endl;
	return (this->attackDamage_);
}

/*
void	ClapTrap::setName(const std::string& name) {
//	std::cerr << "\033[2;3msetHitPoint member function called\033[m" << std::endl;
	this->name_ = name;
}

void	ClapTrap::setHitPoint(unsigned int hitPoint) {
//	std::cerr << "\033[2;3msetHitPoint member function called\033[m" << std::endl;
	this->hitPoint_ = hitPoint;
}

void	ClapTrap::setEnergyPoint(unsigned int energyPoint) {
//	std::cerr << "\033[2;3msetEnergyPoint member function called\033[m" << std::endl;
	this->energyPoint_ = energyPoint;
}

void	ClapTrap::setAttackDamage(unsigned int attackDamage) {
//	std::cerr << "\033[2;3msetAttackDamage member function called\033[m" << std::endl;
	this->attackDamage_ = attackDamage;
}
*/