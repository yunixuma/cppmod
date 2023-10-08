/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/08 16:50:55 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
// #include <map>
#include "easyfind.hpp"

static int	case_vector(void) {
	std::clog << "\033[43mCASE: Test for vector of integers\033[m" << std::endl;
	int	arr[] = {1, 3, 5, 7, 9};
	int	n = sizeof(arr) / sizeof(arr[0]);
	std::vector<int>	myvec(arr, arr + n);

	try {
		std::cout << easyfind(myvec, 3) << " found\033[m" << std::endl;
		std::cout << easyfind(myvec, 6) << " found\033[m" << std::endl;
		std::cout << easyfind(myvec, 9) << " found\033[m" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "\033[31;3m" << e.what() << "\033[m" << std::endl;
	}

	return (0);
}

static int	case_vector_double(void) {
	std::clog << "\033[43mCASE: Test for vector of float point\033[m" << std::endl;
	double	arr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	int	n = sizeof(arr) / sizeof(arr[0]);
	std::vector<double>	myvec(arr, arr + n);

	try {
		std::cout << easyfindInfer(myvec, 2.2) << " found\033[m" << std::endl;
		std::cout << easyfindInfer(myvec, 4.4) << " found\033[m" << std::endl;
		std::cout << easyfindInfer(myvec, 6.6) << " found\033[m" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "\033[31;3m" << e.what() << "\033[m" << std::endl;
	}

	return (0);
}

static int	case_list(void) {
	std::clog << "\033[43mCASE: Test for list of integers\033[m" << std::endl;
	std::list<int>	mylst;
	mylst.push_back(1);
	mylst.push_back(3);
	mylst.push_back(5);
	mylst.push_back(7);
	mylst.push_back(9);

	try {
		std::cout << easyfind(mylst, 3) << " found\033[m" << std::endl;
		std::cout << easyfind(mylst, 6) << " found\033[m" << std::endl;
		std::cout << easyfind(mylst, 9) << " found\033[m" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "\033[31;3m" << e.what() << "\033[m" << std::endl;
	}

	return (0);
}

static int	case_list_string(void) {
	std::clog << "\033[43mCASE: Test for list of string\033[m" << std::endl;
	std::list<std::string>	mylst;
	mylst.push_back("egg");
	mylst.push_back("tomato");
	mylst.push_back("onion");
	mylst.push_back("potato");
	mylst.push_back("carrot");

	try {
		std::cout << easyfindInfer(mylst, "tomato") << " found\033[m" << std::endl;
		std::cout << easyfindInfer(mylst, "potato") << " found\033[m" << std::endl;
		std::cout << easyfindInfer(mylst, "salt") << " found\033[m" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "\033[31;3m" << e.what() << "\033[m" << std::endl;
	}

	return (0);
}

/*
static int	case_map(void) {
	std::clog << "\033[43mCASE: Test for map\033[m" << std::endl;
	std::map<std::string, int>	mymap;
	mymap["one"] = 1;
	mymap["two"] = 2;
	mymap["three"] = 3;

	easyfind(mymap, 2);
	easyfind(mymap, 6);

	return (0);
}
*/

int	main(void) {
	case_vector();
	case_list();
	// case_map();
	case_vector_double();
	case_list_string();
	std::clog << "\033[33;42mFINISH\033[m" << std::endl;
	return (0);
}
