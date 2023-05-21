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
	if (cmd == "ADD")
	{
		if (pb->add_contact())
			return (4);
	}
	else if (cmd == "SEARCH")
	{
		if (pb->search_contact())
			return (3);
	}
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
//		cmd.clear();
//		std::cin.clear();
		std::cout << std::endl;
		std::cout << "\033[32m=== My Awesome PhoneBook (";
		std::cout << (pb.get_count() > 8 ? 8 : pb.get_count());
		std::cout << " records) ===\033[m" << std::endl;
		std::cout << "\033[33m* Available commands: ADD / SEARCH / EXIT *\033[m" << std::endl;
		std::cout << "Enter the command: \033[36m";
		std::getline(std::cin, cmd);
		std::cout << "\033[m";
		if (std::cin.eof())
			break ;
		else if (cmd.length() == 0)
			continue ;
		status = command(&pb, cmd);
		if (status == 9)
			return (0);
		else if (status == 7)
			std::cerr << "\033[31mWrong command. Please try again.\033[m" << std::endl;
		else if (status == 4)
			break ;
	}
	std::cout << std::endl;
	std::cerr << "\033[31mOperation aborted.\033[m" << std::endl;
	return (4);
}
