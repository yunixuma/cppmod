/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/06 16:22:26 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) {
	this->type = "Dog";
	this->brain_ = new Brain();
	std::cout << "\033[36;2;3mCreating a Dog (" \
		<< this << ": " << this->type << ")\033[m" << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src) {
	std::cout << "\033[36;2mCopy constructor of Dog called (" \
		<< &src << " -> " << this << ")\033[m" << std::endl;
	this->type = src.type;
	this->brain_ = new Brain(*(src.getBrain()));
}

Dog&	Dog::operator=(const Dog& rhs) {
	std::cout << "\033[36;2mCopy assignment operator of Dog called (" \
		<< &rhs << " -> " << this << ")\033[m" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
		this->brain_ = rhs.brain_;
	}
	return (*this);
}

Dog::~Dog(void) {
	std::cout << "\033[31;2;3mDestroying the Dog (" \
		<< this << ": " << this->type << ")\033[m" << std::endl;
	delete this->brain_;
}

void	Dog::makeSound(void) const {
	std::cout << "\033[32m" << this->type \
		<< " barks \"Bowwow!\"\033[m" << std::endl;
}

const Brain	*Dog::getBrain(void) const {
	return (this->brain_);
}

const std::string&	Dog::getIdea(size_t idx) const {
	// if (!this->brain_[idx])
	// 	return ("(null)");
	return (this->brain_->getIdea(idx));
}
