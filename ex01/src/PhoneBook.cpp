/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/24 05:49:42 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	std::cout << "\033[2;3mInitiating the PhoneBook.\033[m" << std::endl;
	Contact contacts_[8];
	this->count_ = 0;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "\033[2;3mDestroying the PhoneBook.\033[m" << std::endl;
}

size_t	PhoneBook::get_count() {
	return (this->count_);
}

Contact	*PhoneBook::get_contact(size_t count) {
	return (&this->contacts_[count % 8]);
}

int	PhoneBook::add_contact() {
	Contact	*contact;
	Contact	tmp;
	size_t	count;

	count = this->get_count();
	contact = this->get_contact(count);
	std::cout << std::endl << "\033[33mAdding No." << count + 1 << " contact\033[m" << std::endl;
	if (tmp.input_values(count + 1))
		return (1);
	contact->copy_values(&tmp);
	this->set_count(count + 1);
	return (0);
}

int	PhoneBook::search_contact() {
	size_t				index;
	std::string			input;
	std::stringstream	ss;

	if (this->count_ == 0)
	{
		std::cerr << "\033[31m!!! No contacts exists. !!!\033[m" << std::endl;
		return (1);
	}

	if (this->count_ < 8)
		index = 0;
	else
		index = this->count_ - 8;

	std::cout << std::endl;
	std::cout << "Index| First name | Last name  | Nickname   |" << std::endl;
	for (size_t i = 0; i < 8; i++)
		this->get_contact(index + i)->output_digest();
	std::cout << std::endl;

	std::cout << "\033[33mTo show the content of the contact, \033[m" << std::endl;
	try {
		std::cout << "Enter the index: \033[36m";
		std::getline(std::cin, input);
		if (std::cin.eof() || input.length() == 0)
			return (4);
		std::cout << "\033[m";
		ss << input;
		ss >> index;
		if(ss.fail())
			throw (std::exception());
	}
	catch (const std::exception& e) {
		std::cerr << "\033[31m!!! Index must be a integral number. !!!\033[m" << std::endl;
		return (6);
	}

	if (this->get_contact(index - 1)->output_detail(index))
	{
		std::cerr << "\033[31m!!! Index " << index << " does not exist. !!!\033[m" << std::endl;
		return (1);
	}
	return (0);
}

int	PhoneBook::set_count(size_t count) {
	this->count_ = count;
	return (1);
}
