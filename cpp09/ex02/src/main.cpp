/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/21 07:02:50 by Yoshihiro K      ###   ########.fr       */
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
# define SIZE_PRINT		16

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
	std::cout << "Before: ";
	printList(vec);

	time_lst = pme.sort(lst);

	std::cout << "After: ";
	printList(lst);
	std::cout << "Time to process a range of " \
		<< lst.size() << " elements with std::list : " \
		<< time_lst << " clocks" << std::endl;

	time_vec = pme.sort(vec);

	std::cout << "After: ";
	printList(vec);
	std::cout << "Time to process a range of " \
		<< vec.size() << " elements with std::vector : " \
		<< time_vec << " clocks" << std::endl;
	std::clog << "CLOCKS_PER_SEC: " << CLOCKS_PER_SEC << std::endl;
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