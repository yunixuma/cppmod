/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/07/11 04:54:50 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

template <typename T>
static void	debug_print(T& arg) {
	std::cout << "\033[35;3m[" << &arg << "] {" << arg << "}\033[m" << std::endl;
}

template <typename T>
static void	debug_array(T& tc) {
	for (unsigned int i = 0; i < tc.size(); i++)
		debug_print(tc[i]);
}

template <typename T1, typename T2>
static void	multiply(T1& arg1, T2& arg2) {
	arg1 *= arg2;
}

template <typename T1, typename T2>
static void	append(T1& arg1, T2& arg2) {
	arg1 += arg2;
}

static int	case_numeric(void) {
	std::clog << "\033[43mCASE: Test for numeric\033[m" << std::endl;
	float			floats[] = { 1.5, 2.4, 3.3, 4.2, 5.1 };
	int				nums[] = { 3, 2, 8, 10, 5 };
	Array<float>	arr_floats(5);
	Array<int>		arr_nums(5);

	std::clog << "\033[32;2mValues at construction\033[m" << std::endl;
	std::clog << "multiplicands (float):" << std::endl;
	debug_array(arr_floats);
	std::clog << "multipliers (int):" << std::endl;
	debug_array(arr_nums);

	std::clog << "\033[32;2mCopying array values\033[m" << std::endl;
	arr_floats = floats;
	arr_nums = nums;

	std::clog << "\033[32;2mValues after copying\033[m" << std::endl;
	std::clog << "multiplicands (float):" << std::endl;
	debug_array(arr_floats);
	std::clog << "multipliers (int):" << std::endl;
	debug_array(arr_nums);

	std::clog << "\033[32;2mApplying multiply()\033[m" << std::endl;
	for (unsigned int i = 0; i < arr_floats.size(); i++)
		multiply(arr_floats[i], arr_nums[i]);

	std::clog << "\033[32;2mValues after multiplying\033[m" << std::endl;
	std::clog << "multiplicands (float):" << std::endl;
	debug_array(arr_floats);

	return (0);
}
/*
static int	case_string(void) {
	std::clog << "\033[43mCASE: Test for string\033[m" << std::endl;
	std::string	fruits[] = { "apple", "orange", "grape", "peach", "melon" };
	std::string	foods[] = { " pie", " cake", " juice", " jelly", " soda" };

	std::clog << "fruits (string):" << std::endl;
	iter(fruits, 5, debug_print);
	std::clog << "foods (string):" << std::endl;
	iter(foods, 5, debug_print);
	std::clog << "\033[32;2mApplying append()\033[m" << std::endl;
	iter(fruits, foods, 5, append);
	std::clog << "products (float):" << std::endl;
	iter(fruits, 5, debug_print);
	return (0);
}
*/
int	main(void) {
	case_numeric();
	// case_string();
	std::clog << "\033[33;42mFINISH\033[m" << std::endl;
	return (0);
}
