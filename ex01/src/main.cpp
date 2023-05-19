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
	Contact	contact; 	
	size_t	count;

	count = pb->get_count();
	contact = pb->get_contact(count);
	if (cmd == "ADD")
	{
		if (contact.set_values(count))
		{
			pb->set_count(count);
		}
	}
	else if (cmd == "SEARCH")
		pb->search_contact();
	else if (cmd == "EXIT")
		return (9);
	else
		return (1);
	return (0);
}

int main(void)
{
	std::string	cmd;
	PhoneBook	pb;
	int			status;

	while (true)
	{
		std::cout << "\033[33m* Available commands: ADD / SEARCH / EXIT *\033[m" << std::endl;
		std::cout << "\033[32mEnter the command: \033[m\033[36m";
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			return (1);
		std::cout << "\033[m";
		status = command(&pb, cmd);
		if (status == 9)
			break ;
		else if (status == 1)
			std::cerr << "\033[31mWrong command. Please try again.\033[m" << std::endl;
	}
	return (0);
}
