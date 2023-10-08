/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/29 16:00:41 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

const std::string Harl::levels_[] = {"DEBUG", "INFO", "WARNING", "ERROR", \
	"Probably complaining about insignificant problems"};

Harl::Harl() {
	pfs_[0] = &Harl::debug;
	pfs_[1] = &Harl::info;
	pfs_[2] = &Harl::warning;
	pfs_[3] = &Harl::error;
}

Harl::~Harl(void) {
}

void	Harl::debug( void ) {
	std::cout << "\033[35m[ " << this->levels_[0] << " ]\033[m" << std::endl;
	const static std::string	msg_debug = "\033[35mI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. \nI really do!\033[m";
	std::cout << msg_debug << std::endl << std::endl;
}

void	Harl::info( void ) {
	std::cout << "\033[36m[ " << this->levels_[1] << " ]\033[m" << std::endl;
	const static std::string	msg_info = "\033[36mI cannot believe adding extra bacon costs more money. \nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\033[m";
	std::cout << msg_info << std::endl << std::endl;
}

void	Harl::warning( void ) {
	std::cout << "\033[33m[ " << this->levels_[2] << " ]\033[m" << std::endl;
	const static std::string	msg_warning = "\033[33mI think I deserve to have some extra bacon for free. \nI’ve been coming for years whereas you started working here since last month.\033[m";
	std::cout << msg_warning << std::endl << std::endl;
}

void	Harl::error( void ) {
	std::cout << "\033[31m[ " << this->levels_[3] << " ]\033[m" << std::endl;
	const static std::string	msg_error = "\033[31mThis is unacceptable! I want to speak to the manager now.\033[m";
	std::cout << msg_error << std::endl << std::endl;
}

void	Harl::complainAbove( std::string level ) {
	int	i = 0;
	while (i < 4) {
		if (this->levels_[i] == level)
			break ;
		i++;
	}

	switch (i) {
		case (0):
			(this->*pfs_[0])();
		case (1):
			(this->*pfs_[1])();
		case (2):
			(this->*pfs_[2])();
		case (3):
		{
			(this->*pfs_[3])();
			break ;
		}
		default:
			std::cerr << "\033[2m[ " << this->levels_[i] << " ]\033[m" << std::endl;	
	}
}
