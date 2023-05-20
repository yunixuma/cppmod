/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/04/05 19:31:32 by ykosaka          ###   ########.fr       */
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

int	Contact::set_values(size_t count) {
	this->id = count;
	
	do {
		std::cout << "Enter the first name: ";
		std::getline(std::cin, this->first_name);
	} while (!this->first_name.length());
	do {
		std::cout << "Enter the last name: ";
		std::getline(std::cin, this->last_name);
	} while (!this->last_name.length());
	do {
		std::cout << "Enter the nickname: ";
		std::getline(std::cin, this->nickname);
	} while (!this->nickname.length());
	do {
		std::cout << "Enter the phone number: ";
		std::getline(std::cin, this->phone_number);
	} while (!this->phone_number.length());
	do {
		std::cout << "Enter the darkest secret: ";
		std::getline(std::cin, this->darkest_secret);
	} while (!this->darkest_secret.length());
	return (1);
}

int	Contact::output_digest() {
	if (this->id == 0)
		return (0);
	std::cout << std::setw(4) << std::right << this->id << " | ";
	std::cout << std::setw(10) << this->first_name.substr(0,10) << " | ";
	std::cout << std::setw(10) << this->last_name.substr(0,10) << " | ";
	std::cout << std::setw(10) << this->nickname.substr(0,10) << " | ";
	std::cout << std::endl;
	return (1);
}

int	Contact::output_detail(size_t id) {
	if (id == 0 || this->id != id)
		return (1);
	std::cout << "Index: " << this->id << std::endl;
	std::cout << "First name: " << this->first_name << std::endl;
	std::cout << "Last name: " << this->last_name << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone number: " << this->phone_number << std::endl;
	std::cout << "Darkest secret: " << this->darkest_secret << std::endl;
	return (0);
}
