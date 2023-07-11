/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/07/11 23:46:07 by Yoshihiro K      ###   ########.fr       */
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
	std::cout << "\033[35;3m" << tc << "\033[m" << std::endl;
	for (unsigned int i = 0; i < tc.size(); i++)
		debug_print(tc[i]);
}

template <typename T1, typename T2>
static T1&	multiply(T1& arg1, T2& arg2) {
	arg1 *= arg2;
	return (arg1);
}

template <typename T1, typename T2>
static T1&	append(T1& arg1, T2& arg2) {
	arg1 += arg2;
	return (arg1);
}

static int	case_numeric(void) {
	std::clog << std::endl << "\033[43mCASE: Test for numeric\033[m" << std::endl;
	float			floats[] = { 1.5, 2.4, 3.3, 4.2, 5.1 };
	int				nums[] = { 3, 2, 8, 10, 5 };
	Array<float>	arr_floats(sizeof(floats) / sizeof(float));
	Array<int>		arr_nums(arr_floats.size());

	std::clog << std::endl << "\033[32;2mValues at construction\033[m" << std::endl;
	std::clog << "multiplicands (float):" << std::endl;
	debug_array(arr_floats);
	std::clog << "multipliers (int):" << std::endl;
	debug_array(arr_nums);

	std::clog << std::endl << "\033[32;2mCopying array values\033[m" << std::endl;
	arr_floats = floats;
	arr_nums = nums;

	std::clog << std::endl << "\033[32;2mValues after copying\033[m" << std::endl;
	std::clog << "multiplicands (float):" << std::endl;
	debug_array(arr_floats);
	std::clog << "multipliers (int):" << std::endl;
	debug_array(arr_nums);

	std::clog << std::endl << "\033[32;2mApplying multiply()\033[m" << std::endl;
	for (unsigned int i = 0; i < arr_floats.size(); i++)
		multiply(arr_floats[i], arr_nums[i]);

	std::clog << std::endl << "\033[32;2mValues after multiplying\033[m" << std::endl;
	std::clog << "multiplicands (float):" << std::endl;
	debug_array(arr_floats);

	std::clog << std::endl << "\033[32;2mTrying access on the inavailable index\033[m" << std::endl;
	try {
		// std::clog << "\033[2;3mIn try{} block\033[m" << std::endl;
		std::cout << "arr_floats[" << static_cast<int>(-arr_floats.size()) 
			<< "] * arr_nums[" << -arr_nums.size() << "] = " << std::flush;
		std::cout << multiply(arr_floats[static_cast<int>(-arr_floats.size())], \
			arr_nums[-arr_nums.size()]) << std::endl;
	}
	catch (std::exception& e) {
		// std::clog << "\033[2;3mIn catch{} block\033[m" << std::endl;
		std::clog << "\033[31m" << e.what() << "\033[m" << std::endl;
	}

	return (0);
}

static int	case_string(void) {
	std::clog << "\033[43mCASE: Test for string\033[m" << std::endl;
	std::string	fruits[] = { "apple", "orange", "grape", "peach", "melon" };
	std::string	foods[] = { " pie", " cake", " juice", " jelly", " soda" };
	Array<std::string>	arr_fruits(sizeof(fruits) / sizeof(std::string));
	Array<std::string>	arr_foods(arr_fruits.size());

	std::clog << std::endl << "\033[32;2mValues at construction\033[m" << std::endl;
	std::clog << "fruits (string):" << std::endl;
	debug_array(arr_fruits);
	std::clog << "foods (string):" << std::endl;
	debug_array(arr_foods);

	std::clog << std::endl << "\033[32;2mCopying array values\033[m" << std::endl;
	arr_fruits = fruits;
	arr_foods = foods;

	std::clog << std::endl << "\033[32;2mValues after copying\033[m" << std::endl;
	std::clog << "fruits (string):" << std::endl;
	debug_array(arr_fruits);
	std::clog << "foods (string):" << std::endl;
	debug_array(arr_foods);

	std::clog << std::endl << "\033[32;2mApplying multiply()\033[m" << std::endl;
	for (unsigned int i = 0; i < arr_fruits.size(); i++)
		append(arr_fruits[i], arr_foods[i]);

	std::clog << std::endl << "\033[32;2mValues after multiplying\033[m" << std::endl;
	std::clog << "products (string):" << std::endl;
	debug_array(arr_fruits);

	std::clog << std::endl << "\033[32;2mTrying access on the inavailable index\033[m" << std::endl;
	try {
		// std::clog << "\033[2;3mIn try{} block\033[m" << std::endl;
		std::cout << "arr_fruits[" << arr_fruits.size() \
			<< "] + arr_foods[" << arr_foods.size() << "] = " << std::flush;
		std::cout << append(arr_fruits[arr_fruits.size()], arr_foods[arr_foods.size()]) \
			<< std::endl;
	}
	catch (std::exception& e) {
		// std::clog << "\033[2;3mIn catch{} block\033[m" << std::endl;
		std::clog << "\033[31m" << e.what() << "\033[m" << std::endl;
	}
	return (0);
}

int	main(void) {
	case_numeric();
	case_string();
	std::clog << "\033[33;42mFINISH\033[m" << std::endl;
	return (0);
}
