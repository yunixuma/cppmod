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
	Contact	*contact;
	size_t	count;

	count = pb->get_count();
	contact = pb->get_contact(count);
	if (cmd == "ADD")
	{
		if (contact->set_values(count + 1))
		{
			pb->set_count(count + 1);
			return (0);
		}
	}
	else if (cmd == "SEARCH")
	{
		if (pb->search_contact())
			return (0);
	}
	else if (cmd == "EXIT")
		return (9);
	else
		return (2);
	return (1);
}

int main(void)
{
	std::string	cmd;
	PhoneBook	pb;
	int			status;

	while (true)
	{
//		cmd.clear();
		std::cout << "\033[32m=== My Awesome PhoneBook (";
		std::cout << (pb.get_count() > 8 ? 8 : pb.get_count());
		std::cout << " records) ===\033[m" << std::endl;
		std::cout << "\033[33m* Available commands: ADD / SEARCH / EXIT *\033[m" << std::endl;
		std::cout << "\033[32mEnter the command: \033[m\033[36m";
		std::getline(std::cin, cmd);
		std::cout << "\033[m";
		if (std::cin.eof() || cmd.length() == 0)
			continue ;
		status = command(&pb, cmd);
		if (status == 9)
			break ;
		else if (status == 2)
			std::cerr << "\033[31mWrong command. Please try again.\033[m" << std::endl;
	}
	return (0);
}
