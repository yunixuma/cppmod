/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/09/12 19:51:43 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"

static int	case_vector(void) {
	std::clog << "\033[43mCASE: Test for vector\033[m" << std::endl;
	int	arr[] = {1, 3, 5, 7, 9};
	int	n = sizeof(arr) / sizeof(arr[0]);
	std::vector<int>	myvec(arr, arr + n);

	try {
		std::cout << easyfind(myvec, 3) << " found\033[m" << std::endl;
		std::cout << easyfind(myvec, 6) << " found\033[m" << std::endl;
		std::cout << easyfind(myvec, 9) << " found\033[m" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "\033[31;3m" << e.what() << std::endl;
	}

	return (0);
}

static int	case_list(void) {
	std::clog << "\033[43mCASE: Test for list\033[m" << std::endl;
	std::list<double>	mylst;
	mylst.push_back(1.1);
	mylst.push_back(2.2);
	mylst.push_back(3.3);
	mylst.push_back(4.4);
	mylst.push_back(5.5);

	try {
		std::cout << easyfind(mylst, 2.2) << " found\033[m" << std::endl;
		std::cout << easyfind(mylst, 4.4) << " found\033[m" << std::endl;
		std::cout << easyfind(mylst, 6.6) << " found\033[m" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "\033[31;3m" << e.what() << "\033[m" << std::endl;
	}

	return (0);
}
/*
static int	case_map(void) {
	std::clog << "\033[43mCASE: Test for map\033[m" << std::endl;
	std::map<std::string, int> mymap = {{"one", 1}, {"two", 2}, {"three", 3}};

	easyfind(mymap, 2);
	easyfind(mymap, 6);

	return (0);
}
*/
int	main(void) {
	case_vector();
	case_list();
//	case_map();
	std::clog << "\033[33;42mFINISH\033[m" << std::endl;
	return (0);
}
