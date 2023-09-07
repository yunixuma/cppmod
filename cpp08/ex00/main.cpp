/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/07/30 14:49:51 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"

static int	case_basic(void) {
	std::clog << "\033[43mBasic tests\033[m" << std::endl;
	std::vector<int>	arr = {0, 1, 2, 3, 4};

	std::cout << easyfind(arr, 3) << std::endl;

	return (0);
}

int	main(void) {
	case_basic();
	std::clog << "\033[33;42mFINISH\033[m" << std::endl;
	return (0);
}
