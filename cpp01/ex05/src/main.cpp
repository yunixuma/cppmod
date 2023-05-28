/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/29 00:45:29 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main(void)
{
	Harl	harl;
	const static std::string cases[] = {"DEBUG", "INFO", "WARNING", "ERROR", "OTHER"};

	for (size_t i = 0; i < 5; i++)
	{
		std::cout << std::endl << "Test case: " << cases[i] << std::endl;
		harl.complain(cases[i]);
	}
	std::cout << std::endl;
	return (0);
}
