/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/04 21:03:42 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <list>
#include <typeinfo>
#include <string>
#include "MutantStack.hpp"

template <class T, typename U>
static void	push_and_pr(T* stk, U val) {
	stk->push(val);
	std::cout << "[" \
		<< stk << "]\033[35m<" \
		<< typeid(*stk).name() << ">\033[mstk[" \
		<< stk->size() - 1 << "] \033[33mtop\033[m\t: \033[32m" \
		<< stk->top() << "\033[m" << std::endl;
}

template <typename U>
static void	push_and_pr(std::list<U>* stk, U val) {
	stk->push_back(val);
	std::cout << "[" \
		<< stk << "]\033[35m<" \
		<< typeid(*stk).name() << ">\033[mstk[" \
		<< stk->size() - 1 << "] \033[33mtop\033[m\t: \033[32m" \
		<< stk->back() << "\033[m" << std::endl;
}

template <typename U>
static U&	pr_and_pop(std::stack<U>* stk) {
	U&	ret = stk->top();
	std::cout << "[" \
		<< stk << "]\033[35m<" \
		<< typeid(*stk).name() << ">\033[mstk[" \
		<< stk->size() - 1 << "] \033[33mpop\033[m\t: \033[32m" \
		<< ret << "\033[m" << std::endl;
	stk->pop();
	return (ret);
}

template <typename U>
static U&	pr_and_pop(MutantStack<U>* stk) {
	U&	ret = stk->top();
	std::cout << "[" \
		<< stk << "]\033[35m<" \
		<< typeid(*stk).name() << ">\033[mstk[" \
		<< stk->size() - 1 << "] \033[33mpop\033[m\t: \033[32m" \
		<< ret << "\033[m" << std::endl;
	stk->pop();
	return (ret);
}

template <typename U>
static U&	pr_and_pop(std::list<U>* stk) {
	U&	ret = stk->back();
	std::cout << "[" \
		<< stk << "]\033[35m<" \
		<< typeid(*stk).name() << ">\033[mstk[" \
		<< stk->size() - 1 << "] \033[33mpop_back\033[m\t: \033[32m" \
		<< ret << "\033[m" << std::endl;
	stk->pop_back();
	return (ret);
}

static int	case_sample(void) {
	std::clog << "\033[43mCASE: Test sample\033[m" << std::endl;
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

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return (0);
}

static int	case_mstack_int(void) {
	std::clog << "\033[43mCASE: Test for MutantStack of integer\033[m" << std::endl;
	MutantStack<int> stk;

	std::cout << stk << std::endl;
	std::cout << "stk.\033[33mempty()\033[m\t: \033[32m" \
		<< stk.empty() << "\033[m" << std::endl;
/*	std::cout << "stk.begin()\t->[" \
		<< &(*stk.begin()) << "]: " << *stk.begin() << std::endl;
	std::cout << "stk.end()\t->[" \
		<< &(*stk.end()) << "]: " << *stk.end() << std::endl;
	std::cout << "stk.front()\t->[" << &stk.front() \
		<< "]: " << stk.front() << std::endl;
	std::cout << "stk.back()\t->[" << &stk.back() \
		<< "]: " << stk.back() << std::endl;*/

	push_and_pr(&stk, 5);
	push_and_pr(&stk, 17);
	pr_and_pop(&stk);
	push_and_pr(&stk, 3);
	push_and_pr(&stk, -5);
	push_and_pr(&stk, 737);
	push_and_pr(&stk, 0);
	pr_and_pop(&stk);
	//[...]

	std::cout << "stk.\033[33mempty()\033[m\t: \033[32m" \
		<< stk.empty() << "\033[m" << std::endl;
	MutantStack<int>::iterator it = stk.begin();
	MutantStack<int>::iterator ite = stk.end();
	std::cout << "stk.\033[33mfront()\033[m\t->[" << &stk.front() \
		<< "]: \033[33m" << stk.front() << "\033[m" << std::endl;
	std::cout << "stk.\033[33mback()\033[m\t->[" << &stk.back() \
		<< "]: \033[33m" << stk.back() << "\033[m" << std::endl;
	unsigned int i = 0;
	while (it != ite)
	{
		std::cout << "stk\033[33m[" << i++ << "]\033[m\t->[" \
			<< &(*it) << "]: \033[32m" << *it << "\033[m" << std::endl;
		it++;
	}
	it = stk.begin();
	std::cout << "stk[0]\033[33m++\033[m\t->[" \
		<< &(*(it++)) << "]:  \033[32m" << *it << "\033[m" << std::endl;
	std::cout << "\033[33m--\033[mstk[0]\t->[" \
		<< &(*(--it)) << "]: \033[32m" << *it << "\033[m" << std::endl;
	it += 2;
	std::cout << "stk[0]\033[33m+2\033[m\t->[" \
		<< &(*(it)) << "]: \033[32m" << *it << "\033[m" << std::endl;
	std::stack<int> s(stk);
	return (0);
}

static int	case_mstack_str(void) {
	std::clog << "\033[43mCASE: Test for MutantStack of string\033[m" << std::endl;
	MutantStack<std::string> stk;

	std::cout << stk << std::endl;
	std::cout << "stk.\033[33mempty()\033[m\t: \033[32m" \
		<< stk.empty() << "\033[m" << std::endl;
/*	std::cout << "stk.begin()\t->[" \
		<< &(*stk.begin()) << "]: " << *stk.begin() << std::endl;
	std::cout << "stk.end()\t->[" \
		<< &(*stk.end()) << "]: " << *stk.end() << std::endl;
	std::cout << "stk.front()\t->[" << &stk.front() \
		<< "]: " << stk.front() << std::endl;
	std::cout << "stk.back()\t->[" << &stk.back() \
		<< "]: " << stk.back() << std::endl;*/

	push_and_pr(&stk, "egg");
	push_and_pr(&stk, "tomato");
	pr_and_pop(&stk);
	push_and_pr(&stk, "potato");
	push_and_pr(&stk, "salt");
	push_and_pr(&stk, "carrot");
	push_and_pr(&stk, "pepper");
	pr_and_pop(&stk);
	//[...]

	std::cout << "stk.\033[33mempty()\033[m\t: \033[32m" \
		<< stk.empty() << "\033[m" << std::endl;
	MutantStack<std::string>::iterator it = stk.begin();
	MutantStack<std::string>::iterator ite = stk.end();
	std::cout << "stk.\033[33mfront()\033[m\t->[" << &stk.front() \
		<< "]: \033[32m" << stk.front() << "\033[m" << std::endl;
	std::cout << "stk.\033[33mback()\033[m\t->[" << &stk.back() \
		<< "]: \033[32m" << stk.back() << "\033[m" << std::endl;
	unsigned int i = 0;
	while (it != ite)
	{
		std::cout << "stk\033[33m[" << i++ << "]\033[m\t->[" \
			<< &(*it) << "]: \033[32m" << *it << "\033[m" << std::endl;
		it++;
	}
	it = stk.begin();
	std::cout << "stk[0]\033[33m++\033[m\t->[" \
		<< &(*(it++)) << "]:  \033[32m" << *it << "\033[m" << std::endl;
	std::cout << "\033[33m--\033[mstk[0]\t->[" \
		<< &(*(--it)) << "]: \033[32m" << *it << "\033[m" << std::endl;
	it += 2;
	std::cout << "stk[0]\033[33m+2\033[m\t->[" \
		<< &(*(it)) << "]: \033[32m" << *it << "\033[m" << std::endl;
	std::stack<std::string> s(stk);
	return (0);
}

static int	case_purestack(void) {
	std::clog << "\033[43mCASE: Test for pure stack data structure\033[m" << std::endl;
	std::stack<int>	stk;

	// std::cout << stk << std::endl;
	std::cout << "stk.\033[33mempty()\033[m\t: \033[32m" \
		<< stk.empty() << "\033[m" << std::endl;
/*	std::cout << "stk.begin()\t->[" \
		<< &(*stk.begin()) << "]: " << *stk.begin() << std::endl;
	std::cout << "stk.end()\t->[" \
		<< &(*stk.end()) << "]: " << *stk.end() << std::endl;
	std::cout << "stk.front()\t->[" << &stk.front() \
		<< "]: " << stk.front() << std::endl;
	std::cout << "stk.back()\t->[" << &stk.back() \
		<< "]: " << stk.back() << std::endl;*/

	push_and_pr(&stk, 5);
	push_and_pr(&stk, 17);
	pr_and_pop(&stk);
	push_and_pr(&stk, 3);
	push_and_pr(&stk, -5);
	push_and_pr(&stk, 737);
	push_and_pr(&stk, 0);
	pr_and_pop(&stk);
	//[...]

	std::cout << "stk.\033[33mempty()\033[m\t: \033[32m" \
		<< stk.empty() << "\033[m" << std::endl;
/*	std::stack<int>::iterator it = stk.begin();
	std::stack<int>::iterator ite = stk.end();
	std::cout << "stk.front()\t->[" << &stk.front() \
		<< "]: " << stk.front() << std::endl;
	std::cout << "stk.back()\t->[" << &stk.back() \
		<< "]: " << stk.back() << std::endl;
	unsigned int i = 0;
	while (it != ite)
	{
		std::cout << "stk[" << i++ << "]\t->[" \
			<< &(*it) << "]: " << *it << std::endl;
		it++;
	}
	it = stk.begin();
	std::cout << "stk[0]++\t->[" \
		<< &(*(it++)) << "]: " << *it << std::endl;
	std::cout << "--stk[0]\t->[" \
		<< &(*(--it)) << "]: " << *it << std::endl;
	it += 2;
	std::cout << "stk[0]+2\t->[" \
		<< &(*(it)) << "]: " << *it << std::endl;*/
	std::stack<int> s(stk);
	return (0);
}

static int	case_list(void) {
	std::clog << "\033[43mCASE: Test for list instead of MutantStack\033[m" << std::endl;
	std::list<int>	stk;

	// std::cout << stk << std::endl;
	std::cout << "stk.\033[33mempty()\033[m\t: \033[32m" \
		<< stk.empty() << "\033[m" << std::endl;
/*	std::cout << "stk.begin()\t->[" \
		<< &(*stk.begin()) << "]: " << *stk.begin() << std::endl;
	std::cout << "stk.end()\t->[" \
		<< &(*stk.end()) << "]: " << *stk.end() << std::endl;
	std::cout << "stk.front()\t->[" << &stk.front() \
		<< "]: " << stk.front() << std::endl;
	std::cout << "stk.back()\t->[" << &stk.back() \
		<< "]: " << stk.back() << std::endl;*/

	push_and_pr(&stk, 5);
	push_and_pr(&stk, 17);
	pr_and_pop(&stk);
	push_and_pr(&stk, 3);
	push_and_pr(&stk, -5);
	push_and_pr(&stk, 737);
	push_and_pr(&stk, 0);
	pr_and_pop(&stk);
	//[...]

	std::cout << "stk.\033[33mempty()\033[m\t: \033[32m" \
		<< stk.empty() << "\033[m" << std::endl;
	std::list<int>::iterator it = stk.begin();
	std::list<int>::iterator ite = stk.end();
	std::cout << "stk.\033[33mfront()\033[m\t->[" << &stk.front() \
		<< "]: \033[32m" << stk.front() << "\033[m" << std::endl;
	std::cout << "stk.\033[33mback()\033[m\t->[" << &stk.back() \
		<< "]: \033[32m" << stk.back() << "\033[m" << std::endl;
	unsigned int i = 0;
	while (it != ite)
	{
		std::cout << "stk\033[33m[" << i++ << "]\033[m\t->[" \
			<< &(*it) << "]: \033[32m" << *it << "\033[m" << std::endl;
		it++;
	}
	it = stk.begin();
	std::cout << "stk[0]\033[33m++\033[m\t->[" \
		<< &(*(it++)) << "]:  \033[32m" << *it << "\033[m" << std::endl;
	std::cout << "\033[33m--\033[mstk[0]\t->[" \
		<< &(*(--it)) << "]: \033[32m" << *it << "\033[m" << std::endl;
/*	it += 2;
	std::cout << "stk[0]\033[33m+2\033[m\t->[" \
		<< &(*(it)) << "]: \033[32m" << *it << "\033[m" << std::endl;*/
	// std::stack<int> s(stk);
	return (0);
}

int	main(void) {
	case_purestack();
	case_mstack_int();
	case_list();
	case_sample();
	case_mstack_str();
	std::clog << "\033[33;42mFINISH\033[m" << std::endl;
	return (0);
}
