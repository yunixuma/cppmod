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
	std::cout << "Enter the first name: ";
	std::getline(std::cin, this->first_name);
	std::cout << "Enter the last name: ";
	std::getline(std::cin, this->last_name);
	std::cout << "Enter the nickname: ";
	std::getline(std::cin, this->nickname);
	std::cout << "Enter the phone number: ";
	std::getline(std::cin, this->phone_number);
	std::cout << "Enter the darkest secret: ";
	std::getline(std::cin, this->darkest_secret);
	return (0);
}

int	Contact::output_digest() {
	std::cout << std::setw(4) << this->id << " | ";
	std::cout << std::setw(10) << this->first_name << " | ";
	std::cout << std::setw(10) << this->last_name << " | ";
	std::cout << std::setw(10) << this->nickname << " | ";
	std::cout << std::endl;
	return (1);
}

int	Contact::output_detail() {
	std::cout << "index: " << this->id << std::endl;
	std::cout << "First name: " << this->first_name << std::endl;
	std::cout << "Last name: " << this->last_name << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone number: " << this->phone_number << std::endl;
	std::cout << "Darkest secret: " << this->darkest_secret << std::endl;
	return (1);
}
