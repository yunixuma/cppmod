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
	std::cin >> this->id;
	std::cin >> this->first_name;
	std::cin >> this->last_name;
	std::cin >> this->nickname;
	std::cin >> this->phone_number;
	std::cin >> this->darkest_secret;
	return (0);
}

int	display_contact() {
	std::cout << "display" << std::endl;
	return (1);
}
