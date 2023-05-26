/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/22 20:16:15 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"

static int	 command(PhoneBook *pb, std::string cmd) {
	if (cmd == "ADD")
		return (pb->add_contact());
	else if (cmd == "SEARCH")
		return (pb->search_contact());
	else if (cmd == "EXIT")
		return (9);
	else
		return (7);
	return (0);
}

int main(void)
{
	std::string	cmd;
	PhoneBook	pb;
	int			status = 4;

	while (true)
	{
		std::cout << std::endl;
		std::cout << "\033[32m=== My Awesome PhoneBook (";
		std::cout << (pb.get_count() > 8 ? 8 : pb.get_count());
		std::cout << " records) ===\033[m" << std::endl;
		std::cout << "\033[33m* Available commands: ADD / SEARCH / EXIT *\033[m" << std::endl;
		std::cout << "Enter the command: \033[36m";

		std::cin.clear();
		clearerr(stdin);
		std::getline(std::cin, cmd);

		std::cout << "\033[m";
		if (!std::cin.eof() && cmd.length() > 0)
			status = command(&pb, cmd);
		else
			status = 0;
		if (status == 9)
			break ;
		else if (status == 7)
			std::cerr << "\033[31m!!! Wrong command. Please try again. !!!\033[m" << std::endl;
		else if (status == 4)
			std::cerr << "\033[31m!!! Operation aborted. !!!\033[m" << std::endl;
	}
	std::cout << std::endl;
	return (0);
}
