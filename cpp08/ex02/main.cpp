/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/02 20:56:52 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <list>
#include "MutantStack.hpp"

static int	case_purestack(void) {
	std::clog << "\033[43mCASE: Test for pure stack data structure\033[m" << std::endl;
	std::stack<int>	stk;
	stk.push(5);
	stk.push(17);
	std::cout << stk.top() << std::endl;
	stk.pop();
	std::cout << stk.size() << std::endl;
	stk.push(3);
	stk.push(5);
	stk.push(737);
	//[...]

	stk.push(0);
/*	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);*/
	return (0);
}

static int	case_basic(void) {
	std::clog << "\033[43mCASE: Test for MutantStack\033[m" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]

	mstack.push(0);
/*	std::iterator it = mstack.begin();
	std::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}*/
	std::stack<int> s(mstack);
	return (0);
}

static int	case_list(void) {
	std::clog << "\033[43mCASE: Test for list instead of MutantStack\033[m" << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	// std::cout << lst.top() << std::endl;
	// lst.pop();
	std::cout << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	//[...]

	lst.push_back(0);
	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator ite = lst.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> s(lst);
	return (0);
}

int	main(void) {
	case_purestack();
	case_basic();
	case_list();
	std::clog << "\033[33;42mFINISH\033[m" << std::endl;
	return (0);
}
