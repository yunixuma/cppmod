/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2024/05/22 01:46:46 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
# include <string>
//# include <cstring>
#include "PmergeMe.hpp"

# ifndef DEBUG_MODE
#  define DEBUG_MODE	0
# endif

template <typename T>
void	printList(T& lst) {
	typename T::iterator	it = lst.begin();
	size_t					size = lst.size();
	size_t					i = 1;

	std::clog << "size: " << size << std::endl;
	if (size > SIZE_PRINT)
		size = SIZE_PRINT;
	while (i++ < size) {
		std::cout << *it << " ";
		it++;
	}
	if (size < lst.size())
		std::cout << "[...]";
	else if (size)
		std::cout << *it;
	std::cout << std::endl;
}

int	main(int argc, char *argv[]) {
	// Change destination of clog to /dev/null
	std::streambuf* strbuf;
	std::ofstream ofstr("/dev/null");
	strbuf = std::clog.rdbuf(ofstr.rdbuf());
	strbuf = std::cerr.rdbuf(ofstr.rdbuf());
	// Restore destination of clog/cerr when debugging
	if (DEBUG_MODE)
	{
		std::clog.rdbuf(strbuf);
		std::cerr.rdbuf(strbuf);
	}

	if (argc < 2) {
		std::cout << "\033[33mUsage: ./PmergeMe <arguments of positive integers> \033[m" << std::endl;
		return (ENOENT);
	}

	PmergeMe	pmm;
	t_lst		lst;
	t_vec		vec;
	float		time_sort;

	try {
		lst = pmm.args2List(argc, argv);
	}
	catch (const std::exception& e) {
		std::cout << "\033[31mError: " << e.what() << "\033[m" << std::endl;
		return (EINVAL);
	}
	vec = pmm.list2Vector(lst);

	std::cout << "Before: ";
	printList(lst);
	std::cout << "Before: ";
	// printList(vec);

	time_sort = pmm.measureClocks(lst) * ORDER_TIME;

	std::cout << "After: ";
	printList(lst);
	std::cout << "Time to process a range of " \
		<< lst.size() << " elements with std::list : " \
		<< time_sort << UNIT_TIME << std::endl;

	time_sort = pmm.measureClocks(vec) * ORDER_TIME;

	// std::cout << "After: ";
	// printList(vec);
	std::cout << "Time to process a range of " \
		<< vec.size() << " elements with std::vector : " \
		<< time_sort << UNIT_TIME << std::endl;
	// try {
	// 	while (it != ite) {
	// 		pmm.tokenize(it);
	// 		it++;
	// 	}
	// 	std::cout << pmm.getResult() << std::endl;
	// }
	// catch (const std::exception& e) {
	// 	std::cout << "\033[31m" << e.what() << "\033[m" << std::endl;
	// 	return (EINVAL);
	// }
	return (0);
}
