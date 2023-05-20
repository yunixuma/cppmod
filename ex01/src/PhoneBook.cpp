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
	std::cout << "\033[2;3mInitiating the PhoneBook.\033[m" << std::endl;
	Contact contacts[8];
	this->count = 0;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "\033[2;3mDestroying the PhoneBook.\033[m" << std::endl;
}

size_t	PhoneBook::get_count() {
	return (this->count);
}

Contact	*PhoneBook::get_contact(size_t count) {
	return (&this->contacts[count % 8]);
}

int	PhoneBook::search_contact() {
	size_t				index;
	std::string			input;
	std::stringstream	ss;

	if (this->count < 8)
		index = 0;
	else
		index = this->count - 8;
	for (size_t i = 0; i < 8; i++)
		this->get_contact(index + i)->output_digest();
	std::cout << "To show the content of the contact, " << std::endl;
	std::cout << "Enter the index: ";
	std::getline(std::cin, input);
	ss << input;
	ss >> index;
	if (this->get_contact(index - 1)->output_detail(index))
	{
		std::cerr << "\033[31mIndex " << index << " does not exist.\033[m" << std::endl;
		return (1);
	}
	return (0);
}

int	PhoneBook::set_count(size_t count) {
	this->count = count;
	return (1);
}
