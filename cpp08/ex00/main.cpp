/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/08/08 12:24:12 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"

static int	case_vector(void) {
	std::clog << "\033[43mCASE: Test for vector\033[m" << std::endl;
	std::vector<int> myvec = {1, 2, 3, 4, 5};

	easyfind(vec, 3);
	easyfind(vec, 6);

	return (0);
}

static int	case_list(void) {
	std::clog << "\033[43mCASE: Test for list\033[m" << std::endl;
	std::list<double> mylst = {1.1, 2.2, 3.3, 4.4};

	easyfind(mylst, 3.3);

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
