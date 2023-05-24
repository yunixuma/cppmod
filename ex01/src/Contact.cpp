/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/24 05:50:53 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
	this->id_ = 0;
	this->first_name_ = "";
	this->last_name_ = "";
	this->nickname_ = "";
	this->phone_number_ = "";
	this->darkest_secret_ = "";
}

Contact::~Contact(void) {
}

int	Contact::input_values(size_t count) {
	this->id_ = count;
	
	std::cout << std::left;
	do {
		std::cout << "\033[mEnter the " << std::setw(14) << "first name" << ": \033[36m";
		std::getline(std::cin, this->first_name_);
		if (std::cin.eof())
			return (4);
	} while (!this->first_name_.length());
	do {
		std::cout << "\033[mEnter the " << std::setw(14) << "last name" << ": \033[36m";
		std::getline(std::cin, this->last_name_);
		if (std::cin.eof())
			return (4) ;
	} while (!this->last_name_.length());
	do {
		std::cout << "\033[mEnter the " << std::setw(14) << "nickname" << ": \033[36m";
		std::getline(std::cin, this->nickname_);
		if (std::cin.eof())
			return (4) ;
	} while (!this->nickname_.length());
	do {
		std::cout << "\033[mEnter the " << std::setw(14) << "phone number" << ": \033[36m";
		std::getline(std::cin, this->phone_number_);
		if (std::cin.eof())
			return (4) ;
	} while (!this->phone_number_.length());
	do {
		std::cout << "\033[mEnter the " << std::setw(14) << "darkest secret" << ": \033[36m";
		std::getline(std::cin, this->darkest_secret_);
		if (std::cin.eof())
			return (4) ;
	} while (!this->darkest_secret_.length());

	return (0);
}

int	Contact::copy_values(Contact *src) {
	this->id_ = src->id_;
	this->first_name_ = src->first_name_;
	this->last_name_ =src->last_name_;
	this->nickname_ = src->nickname_;
	this->phone_number_ = src->phone_number_;
	this->darkest_secret_ = src->darkest_secret_;
	return (0);
}

int	Contact::output_digest() {
	if (this->id_ == 0)
		return (2);
	std::cout << std::setw(4) << std::right << this->id_ << std::left << " | ";
	std::cout << std::setw(10) << this->first_name_.substr(0,10) << " | ";
	std::cout << std::setw(10) << this->last_name_.substr(0,10) << " | ";
	std::cout << std::setw(10) << this->nickname_.substr(0,10) << " | ";
	std::cout << std::endl;
	return (0);
}

int	Contact::output_detail(size_t id) {
	std::cout << std::endl;
	if (id == 0 || this->id_ != id)
		return (2);
	std::cout << std::setw(17) << "\033[mIndex";
	std::cout << ": \033[32m" << this->id_ << "\033[m" << std::endl;
	std::cout << std::setw(17) << "\033[mFirst name";
	std::cout << ": \033[32m" << this->first_name_ << "\033[m" << std::endl;
	std::cout << std::setw(17) << "\033[mLast name";
	std::cout << ": \033[32m" << this->last_name_ << "\033[m" << std::endl;
	std::cout << std::setw(17) << "\033[mNickname";
	std::cout << ": \033[32m" << this->nickname_ << "\033[m" << std::endl;
	std::cout << std::setw(17) << "\033[mPhone number";
	std::cout << ": \033[32m" << this->phone_number_ << "\033[m" << std::endl;
	std::cout << std::setw(17) << "\033[mDarkest secret";
	std::cout << ": \033[32m" << this->darkest_secret_ << "\033[m" << std::endl;
	std::cout << "\033[m";
	return (0);
}
