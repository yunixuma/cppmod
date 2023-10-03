/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/03 17:56:17 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <list>
#include <typeinfo>
#include "MutantStack.hpp"

template <class T, typename U>
static void	push_and_pr(T* stk, U val) {
	stk->push(val);
	std::cout << "[" \
		<< stk << "]<" \
		<< typeid(*stk).name() << ">stk[" \
		<< stk->size() - 1 << "] top\t: " \
		<< stk->top() << std::endl;
}

template <typename U>
static void	push_and_pr(std::list<U>* stk, U val) {
	stk->push_back(val);
	std::cout << "[" \
		<< stk << "]<" \
		<< typeid(*stk).name() << ">stk[" \
		<< stk->size() - 1 << "] back\t: " \
		<< stk->back() << std::endl;
}

template <typename U>
static U&	pr_and_pop(std::stack<U>* stk) {
	U&	ret = stk->top();
	std::cout << "[" \
		<< stk << "]<" \
		<< typeid(*stk).name() << ">stk[" \
		<< stk->size() - 1 << "] pop\t: " \
		<< ret << std::endl;
	stk->pop();
	return (ret);
}

template <typename U>
static U&	pr_and_pop(MutantStack<U>* stk) {
	U&	ret = stk->top();
	std::cout << "[" \
		<< stk << "]<" \
		<< typeid(*stk).name() << ">stk[" \
		<< stk->size() - 1 << "] pop\t: " \
		<< ret << std::endl;
	stk->pop();
	return (ret);
}

template <typename U>
static U&	pr_and_pop(std::list<U>* stk) {
	U&	ret = stk->back();
	std::cout << "[" \
		<< stk << "]<" \
		<< typeid(*stk).name() << ">stk[" \
		<< stk->size() - 1 << "] pop_back\t: " \
		<< ret << std::endl;
	stk->pop_back();
	return (ret);
}

static int	case_purestack(void) {
	std::clog << "\033[43mCASE: Test for pure stack data structure\033[m" << std::endl;
	std::stack<int>	stk;
	push_and_pr(&stk, 5);
	push_and_pr(&stk, 17);
	pr_and_pop(&stk);
	push_and_pr(&stk, 3);
	push_and_pr(&stk, 5);
	push_and_pr(&stk, 737);
	push_and_pr(&stk, 0);
	pr_and_pop(&stk);
	//[...]

/*	MutantStack<int>::iterator it = stk.begin();
	MutantStack<int>::iterator ite = stk.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}*/
	std::stack<int> s(stk);
	return (0);
}

static int	case_basic(void) {
	std::clog << "\033[43mCASE: Test for MutantStack\033[m" << std::endl;
	MutantStack<int> stk;
	push_and_pr(&stk, 5);
	push_and_pr(&stk, 17);
	pr_and_pop(&stk);
	push_and_pr(&stk, 3);
	push_and_pr(&stk, 5);
	push_and_pr(&stk, 737);
	push_and_pr(&stk, 0);
	pr_and_pop(&stk);
	//[...]

	MutantStack<int>::iterator it = stk.begin();
	MutantStack<int>::iterator ite = stk.end();
	++it;
	std::cout << "stk[" << &stk.front() << "].front()\t: " << stk.front() << std::endl;
	std::cout << "stk[" << &stk.back() << "].back()\t: " << stk.back() << std::endl;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(stk);
	return (0);
}

static int	case_list(void) {
	std::clog << "\033[43mCASE: Test for list instead of MutantStack\033[m" << std::endl;
	std::list<int> lst;
	push_and_pr(&lst, 5);
	push_and_pr(&lst, 17);
	pr_and_pop(&lst);
	push_and_pr(&lst, 3);
	push_and_pr(&lst, 5);
	push_and_pr(&lst, 737);
	push_and_pr(&lst, 0);
	pr_and_pop(&lst);
	//[...]

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
	case_list();
	case_basic();
	std::clog << "\033[33;42mFINISH\033[m" << std::endl;
	return (0);
}
