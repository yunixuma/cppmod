/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/22 19:44:33 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
	this->id = 0;
	this->first_name = "";
	this->last_name = "";
	this->nickname = "";
	this->phone_number = "";
	this->darkest_secret = "";
}

Contact::~Contact(void) {
}

int	Contact::input_values(size_t count) {
	this->id = count;
	
	std::cout << std::left;
	do {
		std::cout << "\033[mEnter the " << std::setw(14) << "first name" << ": \033[36m";
		std::getline(std::cin, this->first_name);
		if (std::cin.eof())
			return (4);
	} while (!this->first_name.length());
	do {
		std::cout << "\033[mEnter the " << std::setw(14) << "last name" << ": \033[36m";
		std::getline(std::cin, this->last_name);
		if (std::cin.eof())
			return (4) ;
	} while (!this->last_name.length());
	do {
		std::cout << "\033[mEnter the " << std::setw(14) << "nickname" << ": \033[36m";
		std::getline(std::cin, this->nickname);
		if (std::cin.eof())
			return (4) ;
	} while (!this->nickname.length());
	do {
		std::cout << "\033[mEnter the " << std::setw(14) << "phone number" << ": \033[36m";
		std::getline(std::cin, this->phone_number);
		if (std::cin.eof())
			return (4) ;
	} while (!this->phone_number.length());
	do {
		std::cout << "\033[mEnter the " << std::setw(14) << "darkest secret" << ": \033[36m";
		std::getline(std::cin, this->darkest_secret);
		if (std::cin.eof())
			return (4) ;
	} while (!this->darkest_secret.length());

	return (0);
}

int	Contact::copy_values(Contact *src) {
	this->id = src->id;
	this->first_name = src->first_name;
	this->last_name =src->last_name;
	this->nickname = src->nickname;
	this->phone_number = src->phone_number;
	this->darkest_secret = src->darkest_secret;
	return (0);
}

int	Contact::output_digest() {
	if (this->id == 0)
		return (2);
	std::cout << std::setw(4) << std::right << this->id << std::left << " | ";
	std::cout << std::setw(10) << this->first_name.substr(0,10) << " | ";
	std::cout << std::setw(10) << this->last_name.substr(0,10) << " | ";
	std::cout << std::setw(10) << this->nickname.substr(0,10) << " | ";
	std::cout << std::endl;
	return (0);
}

int	Contact::output_detail(size_t id) {
	std::cout << std::endl;
	if (id == 0 || this->id != id)
		return (2);
	std::cout << std::setw(17) << "\033[mIndex";
	std::cout << ": \033[32m" << this->id << "\033[m" << std::endl;
	std::cout << std::setw(17) << "\033[mFirst name";
	std::cout << ": \033[32m" << this->first_name << "\033[m" << std::endl;
	std::cout << std::setw(17) << "\033[mLast name";
	std::cout << ": \033[32m" << this->last_name << "\033[m" << std::endl;
	std::cout << std::setw(17) << "\033[mNickname";
	std::cout << ": \033[32m" << this->nickname << "\033[m" << std::endl;
	std::cout << std::setw(17) << "\033[mPhone number";
	std::cout << ": \033[32m" << this->phone_number << "\033[m" << std::endl;
	std::cout << std::setw(17) << "\033[mDarkest secret";
	std::cout << ": \033[32m" << this->darkest_secret << "\033[m" << std::endl;
	std::cout << "\033[m";
	return (0);
}
