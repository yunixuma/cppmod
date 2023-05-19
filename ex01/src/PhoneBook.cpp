/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/04/05 20:32:10 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	Contact contacts[8];
	this->count = 0;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "The destructor called." << std::endl;
}

int	PhoneBook::add_contact() {
	
	return (1);
}

int	PhoneBook::search_contact() {
	for (size_t i = 0; i < 8; i++)
	{
		std::cout << i << std::endl;
	}
	return (1);
}

Contact	PhoneBook::get_contact(size_t count) {
	return (contacts[count % 8]);
}

size_t	PhoneBook::get_count() {
	return (this->count);
}

int	PhoneBook::set_count(size_t count) {
	this->count = count;
	return (1);
}
