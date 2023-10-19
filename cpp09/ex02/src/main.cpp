/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/20 03:54:32 by Yoshihiro K      ###   ########.fr       */
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

static void	printList(std::list<int> lst) {
	std::list<int>::iterator	it = lst.begin();
	size_t						size = lst.size();
	size_t						i = 1;

	std::clog << "size: " << size << std::endl;
	if (size > 5)
		size = 5;
	while (i++ < size) {
		std::cout << *it << " ";
		it++;
	}
	if (size < lst.size())
		std::cout << "[...]";
	else
		std::cout << *it;
	std::cout << std::endl;
}

int	main(int argc, char *argv[]) {
	// Change destination of clog to /dev/null
	std::streambuf* strbuf;
	std::ofstream ofstr("/dev/null");
	strbuf = std::clog.rdbuf(ofstr.rdbuf());
	// Restore destination of clog when debugging
	if (DEBUG_MODE)
		std::clog.rdbuf(strbuf);

	if (argc != 2) {
		std::cout << "\033[33mUsage: ./PmergeMe \"<list of positive integers>\" \033[m" << std::endl;
		return (ENOENT);
	}

	PmergeMe			pme;
	std::list<int>		lst;
	std::vector<int>	vec;
	float	time_lst;
	float	time_vec;

	try {
		lst = pme.split2List(argv[1]);
	}
	catch (const std::exception& e) {
		std::cout << "\033[31mError: " << e.what() << "\033[m" << std::endl;
		return (EINVAL);
	}
	vec = pme.list2Vector(lst);

	std::cout << "Before: ";
	printList(lst);

	time_lst = pme.sort(lst);

	std::cout << "After: ";
	printList(lst);
	std::cout << "Time to process a range of " \
		<< lst.size() << " elements with std::list : " \
		<< time_lst << " us" << std::endl;

	time_vec = pme.sort(vec);

	std::cout << "Time to process a range of " \
		<< vec.size() << " elements with std::vector : " \
		<< time_vec << " us" << std::endl;

	// try {
	// 	while (it != ite) {
	// 		pme.tokenize(it);
	// 		it++;
	// 	}
	// 	std::cout << pme.getResult() << std::endl;
	// }
	// catch (const std::exception& e) {
	// 	std::cout << "\033[31m" << e.what() << "\033[m" << std::endl;
	// 	return (EINVAL);
	// }
	return (0);
}
