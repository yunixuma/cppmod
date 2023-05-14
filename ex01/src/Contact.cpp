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
	index = 0;
	first_name = "";
	last_name = "";
	nick_name = "";
	phone_name = "";
	darkest_secret = "";
}

Contact::~Contact(void) {
	
}

int	Contact::set_contact(Contact::contact contact) {
	std::cin << index;
	std::cin << first_name;
	std::cin << last_name;
	std::cin << nick_name;
	std::cin << phone_number;
	std::cin << darkest_secret;
	return (0);
}
