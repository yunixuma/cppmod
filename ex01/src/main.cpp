/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/04/05 19:23:27 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"

static int	 command(PhoneBook *pb, std::string cmd) {
	size_t	count;

	count = PhoneBook::get_count();
	if (cmd == "ADD")
	{
		if (Contact::set_values(pb, count))
		{
			PhoneBook::set_count(count);
		}
	}
	else if (cmd == "SEARCH")
		PhoneBook::search_contact(pb);
	else if (cmd == "EXIT")
		return (1);
	return (0);
}

int main(void)
{
	std::string	cmd;
	PhoneBook	pb;

	while (true)
	{
		std::cin >> cmd;
		if (std::cin.eof())
		{
			return (1);
		}
		command(&pb, cmd);
	}
	return (0);
}
