/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/11/05 13:59:58 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<PmergeMe> Constructor called" \
		<< "\033[m" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& src) {
	std::clog << "\033[36;2;3m[" << this << "<-" << &src \
		<< "]<PmergeMe> Copy constructor called" \
		<< "\033[m" << std::endl;
	*this = src;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& rhs) {
	std::clog << "\033[35;2;3m[" << this << "<-" << &rhs \
		<< "]<PmergeMe> Copy assignment operator called" \
		<< "\033[m" << std::endl;
	// if (this != &rhs) {
	// 	groups = rhs.grp_lst_;
	// 	groups = rhs.grp_vec_;
	// }
	return (*this);
}

PmergeMe::~PmergeMe(void) {
	std::clog << "\033[31;2;3m[" << this \
		<< "]<PmergeMe> Destructor called\033[m" << std::endl;
}
/*
t_lst	PmergeMe::split2List(const std::string& str) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<PmergeMe> split2List called" << std::endl;
	std::clog << str << "\t<" << typeid(str).name() \
		<< ">\033[m" << std::endl;
	t_lst		lst;
	int					val = 0;
	std::stringstream	ss;

	ss << str;
	while (ss >> val) {
		if (val < 0)
			throw std::invalid_argument("negative number");
		lst.push_back(val);
		while (ss.peek() == ' ')
			ss.ignore();
		val = 0;
	}
	// std::clog << "val: " << val << std::endl;
	if (val == INT_MAX || val == INT_MIN)
		throw std::invalid_argument("overflow");
	if (!ss.eof())
		throw std::invalid_argument("not integer");
	// if (ss.fail() && !ss.eof())
	// 	throw std::invalid_argument("wrong argument");
	return (lst);
}
*/
t_lst	PmergeMe::args2List(size_t argc, char *argv[]) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<PmergeMe> args2List called" << std::endl;
	std::clog << argv << "\t<" << typeid(argv).name() \
		<< ">\033[m" << std::endl;
	t_lst		lst;
	int					val = 0;
	std::stringstream	ss;
	size_t				i = 1;

	while (i < argc) {
		ss.clear();
		ss << argv[i++];
		if (!(ss >> val))
			break ;
		if (val < 0)
			throw std::invalid_argument("negative number");
		if (ss.peek() == ' ')
			throw std::invalid_argument("argument not separated");
		lst.push_back(val);
		val = 0;
	}
	// std::clog << "val: " << val << std::endl;
	if (lst.size() != argc - 1)
		throw std::invalid_argument("wrong argument");
	if (val == INT_MAX || val == INT_MIN)
		throw std::invalid_argument("overflow");
	if (!ss.eof())
		throw std::invalid_argument("not integer");
	// if (ss.fail() && !ss.eof())
	// 	throw std::invalid_argument("wrong argument");
	return (lst);
}

t_vec	PmergeMe::list2Vector(const t_lst& lst) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<PmergeMe> list2Vector called" << std::endl;
	std::clog << &lst << "\t<" << typeid(lst).name() \
		<< ">\033[m" << std::endl;
	t_vec	vec(lst.size());
	t_lst::const_iterator	it = lst.begin();
	t_lst::const_iterator	ite = lst.end();
	size_t					i = 0;
	while (it != ite)
		vec[i++] = *(it++);
	return (vec);
}

size_t	PmergeMe::calcMid(size_t size) const {
	size_t	mid = (sizeof(size_t) * (BITS_BYTE >> 1));
	size_t	delta = mid >> 1;
	while (delta) {
		// std::clog << "pivot: " << pivot << "\tmid: " << mid << std::endl;
		if ((1U << mid) < size)
			mid += delta;
		else if ((1U << mid) > size)
			mid -= delta;
		else
			break;
		delta >>= 1;
	}
	if ((1U << mid) > size)
		mid--;
	// std::clog << "size: " << size << "    mid: " << mid << std::endl;
	return (1 << mid);
}

void	PmergeMe::sortMergeSub(t_lst& lst, size_t left, size_t right)
{
	if (left >= right)
		return;
	size_t	mid = left + (right - left + 1) / 2;
	printList(lst);
	std::clog << "145 (" << left << ", " << mid << ", " << right << ")" << std::endl; printList(lst);
	sortMergeSub(lst, left, mid - 1);
	std::clog << "147 (" << left << ", " << mid << ", " << right << ")" << std::endl; printList(lst);
	sortMergeSub(lst, mid, mid * 2 - left - 1);
	t_lst_it	it1 = lst.begin(); std::advance(it1, left);
	t_lst_it	it2 = lst.begin(); std::advance(it2, mid);
	if (*it1 < *it2) {
		for (size_t i = left; i < mid; i++)
			std::iter_swap(it1++, it2++);
	}
	// std::clog << "@155ms "; printGroups(groups);
}

void	PmergeMe::sortMerge(t_lst& lst, size_t left, size_t right)
{
	if (left >= right)
		return;
	std::list<std::pair<size_t, int> >	groups;
	size_t	mid = left + calcMid((right - left + 1) / 2);

	t_lst_it	it1 = lst.begin(); std::advance(it1, left);
	t_lst_it	it2 = lst.begin(); std::advance(it2, mid);
	std::clog << "166 (" << left << ", " << mid << ", " << right << ")" << std::endl;
	sortMergeSub(lst, left, mid - 1);
	std::clog << "168 (" << left << ", " << mid << ", " << right << ")" << std::endl;
	sortMergeSub(lst, mid, mid * 2 - left - 1);
	// std::clog << "@170m0 "; printGroups(groups);
	if ((left == 0 && right == lst.size() - 1 && *it1 > *it2) \
		|| ((left != 0 || right != lst.size()) && *it1 < *it2)) {
		t_lst_it	it1_copy = it1;
		t_lst_it	it2_copy = it2;
		for (size_t i = left; i < mid; i++)
			std::iter_swap(it1_copy++, it2_copy++);
	}
	std::clog << "@177m2 "; printList(lst);
	// std::clog << "@178m2 "; printGroups(groups);
	// if (left == 0 && right == lst.size() - 1) {
	// 	std::clog << "#180m3" << std::endl;
	// 	groups.push_back(std::make_pair(mid - left, *it1));
	// 	groups.push_back(std::make_pair(mid - left, *it2));
	// } else if (right - left + 1 == mid - left) {
	// 	std::clog << "#184m5" << std::endl;
	// 	groups.push_back(std::make_pair(right - left + 1, *it1));
	// }
	// std::clog << "@187m6 "; printGroups(groups);
	if (mid * 2 - left < right)
		sortMerge(lst, mid * 2 - left, right);
	// std::clog << "@190m7 "; printGroups(groups);
}

t_lst_grp	PmergeMe::initGroup(t_lst& lst)
{
	t_lst_grp	groups;
	t_lst_it	it = lst.begin();
	size_t		size = lst.size();
	size_t		sub_size = calcMid(size / 2);

	groups.push_back(std::make_pair(sub_size, it));
	std::advance(it, sub_size);
	groups.push_back(std::make_pair(sub_size, it));
	std::advance(it, sub_size);
	size_t	i = sub_size * 2;
	std::clog << "@205\ti: " << i << "\tsub_size" << sub_size << "\tsize" << size << std::endl;
	printGroups(groups);
	while (i < size) {
		sub_size = calcMid(size - i);
		std::clog << "@209\ti: " << i << "\tsub_size" << sub_size << std::endl;
		groups.push_back(std::make_pair(sub_size, it));
		i += sub_size;
		std::advance(it, sub_size);
		printGroups(groups);
	}
	return (groups);
}

void	PmergeMe::sortInsert(t_lst& lst, t_lst_grp& groups) {
	t_lst_grp::iterator	it = groups.begin();
	t_lst_grp::iterator	ite = groups.end();

	while (it != ite) {
		std::clog << "it->first: " << it->first << "\t" << "it->second: " << *(it->second) << std::endl;
		it++;
	}
	(void)lst;
}

t_lst	PmergeMe::cut(t_lst& lst, t_lst_it& it, size_t size) {
	t_lst_it	it2 = it;
	t_lst		lst2;
	size_t		i = 0;

	while (i++ < size) {
		lst2.push_back(*it2);
		it2++;
	}
	lst.erase(it, it2);
	return (lst2);
}

void	PmergeMe::sort(t_lst& lst) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<PmergeMe> sort called" << std::endl;
	std::clog << &lst << "\t<" << typeid(lst).name() \
		<< ">\033[m" << std::endl;
	if (sortCheck(lst))
		return ;
	sortMerge(lst, 0, lst.size() - 1);
	t_lst_grp	groups = initGroup(lst);
	initGroup(lst);
	sortInsert(lst, groups);
/*
	t_lst_it	it1 = lst.begin();
	t_lst_it	it2 = it1++;
// https://cpprefjp.github.io/reference/algorithm/iter_swap.html
// https://cpprefjp.github.io/reference/list/list/insert.html
	std::iter_swap(it1, it2);
	t_lst_it	it3 = lst.end();
	it3--;
	std::advance(it1, 2);
	std::clog << "it1: " << *it1 << std::endl;
	std::clog << "it2: " << *it2 << std::endl;
	std::clog << "it3: " << *it3 << std::endl;
	// lst.insert(it3, it2, it1);
	std::clog << "it1: " << *it1 << std::endl;
	std::clog << "it2: " << *it2 << std::endl;
	std::clog << "it3: " << *it3 << std::endl;
	lst.erase(it2, it1);
	// int		tmp = 0;
	// while (tmp >= 0)
	// 	tmp += 8;
*/
}

void	PmergeMe::sortMergeSub(t_vec& vec, size_t left, size_t right)
{
	if (left >= right)
		return;
	size_t	mid = left + (right - left + 1) / 2;
	printList(vec);
	std::clog << "234 (" << left << ", " << mid << ", " << right << ")" << std::endl; printList(vec);
	sortMergeSub(vec, left, mid - 1);
	std::clog << "236 (" << left << ", " << mid << ", " << right << ")" << std::endl; printList(vec);
	sortMergeSub(vec, mid, mid * 2 - left - 1);
	if (vec[left] < vec[mid]) {
		t_vec::iterator	it1 = vec.begin() + left;
		t_vec::iterator	it2 = vec.begin() + mid;
		for (size_t i = left; i < mid; i++) {
			std::iter_swap(it1++, it2++);
		}
	}
	// std::clog << "@245ms "; printGroups(groups);
}

void	PmergeMe::sortMerge(t_vec& vec, size_t left, size_t right)
{
	if (left >= right)
		return;
	size_t	mid = left + calcMid((right - left + 1) / 2);



	std::clog << "256 (" << left << ", " << mid << ", " << right << ")" << std::endl;
	sortMergeSub(vec, left, mid - 1);
	std::clog << "258 (" << left << ", " << mid << ", " << right << ")" << std::endl;
	sortMergeSub(vec, mid, mid * 2 - left - 1);
	if ((left == 0 && right == vec.size() - 1 && vec[left] > vec[mid]) \
		|| ((left != 0 || right != vec.size()) && vec[left] < vec[mid])) {
		t_vec::iterator	it1 = vec.begin() + left;
		t_vec::iterator	it2 = vec.begin() + mid;
		for (size_t i = left; i < mid; i++)
			std::iter_swap(it1++, it2++);
	}
	std::clog << "@264m0 "; printList(vec);
	// std::clog << "@265m0 "; printGroups(groups);
	// if (left == 0 && right == vec.size() - 1) {
	// 	std::clog << "#269m1" << std::endl;
	// 	groups.push_back(std::make_pair(mid - left, vec[left]));
	// 	groups.push_back(std::make_pair(mid - left, vec[mid]));
	// } else if (right - left + 1 == mid - left) {
	// 	std::clog << "#273m2" << std::endl;
	// 	groups.push_back(std::make_pair(mid - left, vec[left]));
	// }
	// std::clog << "@276m3 "; printGroups(groups);
	if (mid * 2 - left < right)
		sortMerge(vec, mid * 2 - left, right);
	// std::clog << "@279m4 "; printGroups(groups);
}

t_vec_grp	PmergeMe::initGroup(t_vec& vec)
{
	t_vec_grp	groups;
	t_vec_it	it = vec.begin();
	size_t		size = vec.size();
	size_t		sub_size = calcMid(size / 2);

	groups.push_back(std::make_pair(sub_size, it));
	std::advance(it, sub_size);
	groups.push_back(std::make_pair(sub_size, it));
	std::advance(it, sub_size);
	size_t	i = sub_size * 2;
	std::clog << "@288\ti: " << i << "\tsub_size" << sub_size << "\tsize" << size << std::endl;
	printGroups(groups);
	while (i < size) {
		sub_size = calcMid(size - i);
		std::clog << "@294\ti: " << i << "\tsub_size" << sub_size << std::endl;
		groups.push_back(std::make_pair(sub_size, it));
		i += sub_size;
		std::advance(it, sub_size);
		printGroups(groups);
	}
	return (groups);
}

void	PmergeMe::sortInsert(t_vec& vec, t_vec_grp& groups) {
	t_vec_grp_it	grp_it;
	t_vec_grp_it	grp_ite;
	t_vec			vec2;
	size_t			size = groups.begin()->first;

	while (size > 0) {
		grp_it = groups.begin();
		grp_ite = groups.end();
		while (grp_it != grp_ite) {
			std::clog << "it->first: " << grp_it->first << "\t" << "it->second: " << *(grp_it->second) << std::endl;
			if (grp_it->first == size) {
				vec2 = sortInsertCut(vec, groups, grp_it);
				sortInsertBS(vec, vec2, groups);
			}
			grp_it++;
		}
		size >>= 1;
		printList(vec);
		printGroups(groups);
	}
	(void)vec;
}

t_vec	PmergeMe::sortInsertCut(t_vec& vec, t_vec_grp& grp, t_vec_grp_it& grp_it) {
	t_vec	vec2;
	size_t	size = grp_it->first / 2;
	if (size == 0) {
		vec2.push_back(*(grp_it->second));
		vec.erase(grp_it->second);
		grp_it = grp.erase(grp_it);
		return (vec2);
	}
	t_vec_it	it = grp_it->second;
	std::advance(it, size);
	vec2 = cut(vec, it, size);
	return (vec2);
}

t_vec	PmergeMe::cut(t_vec& vec, t_vec_it& it, size_t size) {
	t_vec_it	it2 = it;
	t_vec		vec2;
	size_t		i = 0;

	while (i++ < size) {
		vec2.push_back(*it2);
		it2++;
	}
	vec.erase(it, it2);
	return (vec2);
}

void	PmergeMe::sortInsertBS(t_vec& vec, t_vec& vec2, t_vec_grp& groups) {
	t_vec_grp_it			grp_it = groups.begin();
	t_vec_it				pos;
	t_vec::reverse_iterator	it2 = vec2.rbegin();
	t_vec::reverse_iterator	ite2 = vec2.rend();
	size_t					dist = groups.size() / 2;

	std::clog << "vec2: "; printList(vec2);
	while (dist > 0) {
		std::clog << "dist: " << dist << "\tgrp_it->second: " << *grp_it->second << std::endl;
		if (*grp_it->second == vec2[0])
			break;
		if (*grp_it->second < vec2[0])
			std::advance(grp_it, static_cast<int>(-dist));
		else
			std::advance(grp_it, static_cast<int>(dist));
		dist /= 2;
	}
	pos = grp_it->second;
	std::clog << "pos: " << *pos << std::endl;
	while (it2 != ite2) {
		pos = vec.insert(pos, *it2);
		it2++;
	}
	groups.insert(grp_it, std::make_pair(vec2.size(), pos));
}

void	PmergeMe::sort(t_vec& vec) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<PmergeMe> sort called" << std::endl;
	std::clog << &vec << "\t<" << typeid(vec).name() \
		<< ">\033[m" << std::endl;
// https://www.geeksforgeeks.org/c-program-for-merge-sort/
	if (sortCheck(vec))
		return ;
	sortMerge(vec, 0, vec.size() - 1);
	t_vec_grp	groups = initGroup(vec);
	sortInsert(vec, groups);

// https://cpprefjp.github.io/reference/vector/vector/insert.html
// https://cpprefjp.github.io/reference/vector/vector/erase.html
/*	t_vec_it	it1 = vec.begin();
	t_vec_it	it2 = vec.begin();
	t_vec_it	it3 = vec.end();
	t_vec	vec2;
	vec2.push_back(1);
	vec.push_back(1);
	vec.push_back(1);

	// std::advance(it1, 2);
	// it3--;
	vec.insert(vec2.end(), vec.begin(), vec.end());
	std::iter_swap(it1, it2);
	std::advance(it1, 2);
	std::clog << "it1: " << *it1 << std::endl;
	std::clog << "it2: " << *it2 << std::endl;
	std::clog << "it3: " << *it3 << std::endl;
	move(vec, it3, it2, it1);
	std::clog << "it1: " << *it1 << std::endl;
	std::clog << "it2: " << *it2 << std::endl;
	// std::clog << "it3: " << *it3 << std::endl;
//	vec.erase(it2, it1);
	// int		tmp = 0;
	// while (tmp >= 0)
	// 	tmp += 13;
*/
}

/*
void	PmergeMe::move(t_vec& vec, \
	t_vec_it& pos, t_vec_it& first, t_vec_it& last) {

}
*/
/*
void	PmergeMe::move(t_vec& vec, \
	t_vec_it& pos, t_vec_it& first, t_vec_it& last) {
	t_vec	tmp(first, ++last);
	t_vec_it			tmp_begin = tmp.begin();
	t_vec_it			tmp_end = tmp.end();
	t_vec_it			copy_first = first;
	t_vec_it			copy_last = last;
	std::clog << "vec      \t[" << &vec << "]" <<std::endl;
	std::clog << "first    \t[" << &first << "] : [" << &(*first) << "] " << *first <<std::endl;
	std::clog << "last     \t[" << &last << "] : [" << &(*last) << "] " << *last <<std::endl;
	std::clog << "pos     \t[" << &pos << "] : [" << &(*pos) << "] " << *pos <<std::endl;
	std::clog << "tmp      \t[" << &tmp << "]" <<std::endl;
	std::clog << "tmp_begin\t[" << &tmp_begin << "] : [" << &(*tmp_begin) << "]" << *tmp_begin <<std::endl;
	std::clog << "tmp_end  \t[" << &tmp_end << "]" <<std::endl;
	std::clog << "copy_first\t[" << &copy_first << "] : [" << &(*copy_first) << "] " << *copy_first <<std::endl;
	std::clog << "copy_last\t[" << &copy_last << "] : [" << &(*copy_last) << "] " << *copy_last <<std::endl;
	printList(tmp);
	// tmp_end--;
	std::clog << "before insert" << std::endl;
	vec.insert(pos, tmp_begin, tmp_end);
	std::clog << "after insert" << std::endl;
	printList(vec);
	(void)pos;
	// pos = last;
	vec.erase(copy_first, copy_last);
	printList(vec);
}

void PmergeMe::sortMerge(t_vec& vec, size_t l, size_t m, size_t r)
{
	size_t	i, j, k;
	size_t	n1 = m - l + 1;
	size_t	n2 = r - m;

	// Create temp arrays
	int L[n1], R[n2];

	// Copy data to temp arrays
	// L[] and R[]
	for (i = 0; i < n1; i++)
		L[i] = vec[l + i];
	for (j = 0; j < n2; j++)
		R[j] = vec[m + 1 + j];

	// Merge the temp arrays back
	// into arr[l..r]
	// Initial index of first subarray
	i = 0;

	// Initial index of second subarray
	j = 0;

	// Initial index of merged subarray
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			vec[k] = L[i];
			i++;
		}
		else {
			vec[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements
	// of L[], if there are any
	while (i < n1) {
		vec[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements of
	// R[], if there are any
	while (j < n2) {
		vec[k] = R[j];
		j++;
		k++;
	}
}
*/

// When an exception thrown
// const char*	PmergeMe::SyntaxError::what(void) const throw() {
/*	std::clog << "\033[35;3m[" << this \
		<< "]<PmergeMe::SyntaxError> what() called\033[m" \
		<< std::endl;*/
// 	return ("Error: Syntax error");
// }
