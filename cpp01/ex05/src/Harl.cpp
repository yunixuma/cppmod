/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/29 00:39:21 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

const std::string Harl::levels_[] = {"DEBUG", "INFO", "WARNING", "ERROR", \
	"Probably complaining about insignificant problems"};

Harl::Harl() {
	std::cout << "\033[36;2;3m" << "Creating a Harl\033[m" << std::endl;
	pfs_[0] = &Harl::debug;
	pfs_[1] = &Harl::info;
	pfs_[2] = &Harl::warning;
	pfs_[3] = &Harl::error;
}

Harl::~Harl(void) {
	std::cout << "\033[31;2;3m" << "Destroying the Harl\033[m" << std::endl;
}

void	Harl::debug( void ) {
	const static std::string	msg_debug = "\033[35mI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. \nI really do!\033[m";
	std::cout << msg_debug << std::endl;
}

void	Harl::info( void ) {
	const static std::string	msg_info = "\033[36mI cannot believe adding extra bacon costs more money. \nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\033[m";
	std::cout << msg_info << std::endl;
}

void	Harl::warning( void ) {
	const static std::string	msg_warning = "\033[33mI think I deserve to have some extra bacon for free. \nI’ve been coming for years whereas you started working here since last month.\033[m";
	std::cout << msg_warning << std::endl;
}

void	Harl::error( void ) {
	const static std::string	msg_error = "\033[31mThis is unacceptable! I want to speak to the manager now.\033[m";
	std::cout << msg_error << std::endl;
}

void	Harl::complain( std::string level ) {
	int	i = 0;
	while (i < 4)
	{
		if (this->levels_[i] == level)
		{
			std::cout << "\033[2;3mCalling " << &pfs_[i] << " for " << this->levels_[i] << "\033[m" << std::endl;
			(this->*pfs_[i])();
			return ;
		}
		i++;
	}
	std::cerr << "\033[2;3m" << this->levels_[i] << "\033[m" << std::endl;
}
