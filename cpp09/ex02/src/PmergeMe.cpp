/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/11/08 14:15:07 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) : n_sorted_(0) {
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
	if (this != &rhs) {
		// this->grp_lst_ = rhs.grp_lst_;
		// this->grp_vec_ = rhs.grp_vec_;
		this->n_sorted_ = rhs.n_sorted_;
	}
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
/*
void	PmergeMe::sortMergeSub(t_lst& lst, size_t left, size_t right)
{
	if (left >= right)
		return;
	size_t	mid = left + (right - left + 1) / 2;
	std::clog << "!" << __LINE__ << "\t"; printList(lst);
	std::clog << "!" << __LINE__ << "\t(" << left << ", " << mid << ", " << right << ")" << std::endl; printList(lst);
	sortMergeSub(lst, left, mid - 1);
	std::clog << "!" << __LINE__ << "\t(" << left << ", " << mid << ", " << right << ")" << std::endl; printList(lst);
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
	size_t	mid = left + calcMid((right - left + 1) / 2);

	std::clog << "#" << __LINE__ << "\t(" << left << ", " << mid << ", " << right << ")" << std::endl;
	sortMergeSub(lst, left, mid - 1);
	std::clog << "#" << __LINE__ << "\t(" << left << ", " << mid << ", " << right << ")" << std::endl;
	sortMergeSub(lst, mid, mid * 2 - left - 1);
	// std::clog << "#" << __LINE__ << "m0 "; printGroups(groups);
	t_lst_it	it1 = lst.begin(); std::advance(it1, left);
	t_lst_it	it2 = lst.begin(); std::advance(it2, mid);
	if ((left == 0 && right == lst.size() - 1 && *it1 > *it2) || ((left != 0 || right != lst.size()) && *it1 < *it2)) {
	// if ((left != 0 || right != lst.size()) && *it1 < *it2) {
		// t_lst_it	it1_copy = it1;
		// t_lst_it	it2_copy = it2;
		for (size_t i = left; i < mid; i++)
			std::iter_swap(it1++, it2++);
	}
	std::clog << "#" << __LINE__ << "m2 "; printList(lst);
	// std::clog << "@" << __LINE__ << "m2 "; printGroups(groups);
	// if (left == 0 && right == lst.size() - 1) {
	// 	std::clog << "#" << __LINE__ << "m3" << std::endl;
	// 	groups.push_back(std::make_pair(mid - left, *it1));
	// 	groups.push_back(std::make_pair(mid - left, *it2));
	// } else if (right - left + 1 == mid - left) {
	// 	std::clog << "#" << __LINE__ << "m5" << std::endl;
	// 	groups.push_back(std::make_pair(right - left + 1, *it1));
	// }
	// std::clog << "@" << __LINE__ << "m6 "; printGroups(groups);
	if (mid * 2 - left < right)
		sortMerge(lst, mid * 2 - left, right);
	// std::clog << "@" << __LINE__ << "m7 "; printGroups(groups);
}

t_lst_grp	PmergeMe::initGroup(t_lst& lst)
{
	t_lst_grp	groups;
	t_lst_it	it = lst.begin();
	size_t		size = lst.size();
	size_t		sub_size = calcMid(size / 2);

	groups.push_back(std::make_pair(it, sub_size));
	std::advance(it, sub_size);
	groups.push_back(std::make_pair(it, sub_size));
	std::advance(it, sub_size);
	size_t	i = sub_size * 2;
	std::clog << "@" << __LINE__ << "\ti: " << i << "\tsub_size" << sub_size << "\tsize" << size << std::endl;
	printGroups(groups);
	while (i < size) {
		sub_size = calcMid(size - i);
		std::clog << "@" << __LINE__ << "\ti: " << i << "\tsub_size" << sub_size << std::endl;
		groups.push_back(std::make_pair(it, sub_size));
		i += sub_size;
		std::advance(it, sub_size);
		printGroups(groups);
	}
	return (groups);
}

void	PmergeMe::sortTriplet(t_lst& lst, t_lst_grp& groups) {
	size_t	size = groups.front().second;

	if (groups.size() < 3)
		return ;
	t_lst_grp_it	it = groups.begin();
	int				grp0 = *(it++)->first;
	int				grp1 = *(it++)->first;
	int				grp2 = *it->first;
	if (it->second != size)        
		return ;
	std::clog << "^" << __LINE__ << "\tgrp0: " << grp0 \
		<< "\tgrp1: " << grp1 \
		<< "\tgrp2: " << grp2 << std::endl;
	if (grp0 > grp2)
		swapGroup(lst, 0, size * 2, size);
	if (grp0 > grp1)
		swapGroup(lst, 0, size, size);
	if (grp1 > grp2)
		swapGroup(lst, size, size * 2, size);
}

void	PmergeMe::sortInsert(t_lst& lst, t_lst_grp& groups) {
	t_lst_grp_it	grp_it;
	t_lst_grp_it	grp_ite;
	t_lst			lst2;
	size_t			size = groups.begin()->second;

	while (size > 1) {
		grp_it = groups.begin();
		size_t	i = 0;
		while (grp_it != grp_ite) {
			std::clog << "%" << __LINE__ << "\tsize: " << size << "\ti: " << i++ << std::endl;
			std::clog << "%" << __LINE__ << "\tn_sorted: " << this->n_sorted_ << "\tit->second: " << grp_it->second << "\t" << "it->first: " << *(grp_it->first) << std::endl;
			std::clog << "%" << __LINE__ << "\t"; printGroups(groups);
			if (grp_it->second == size) {
				lst2 = sortInsertCut(lst, groups, grp_it);
				// std::clog << "%" << __LINE__ << "\t"; printGroups(groups);
				sortInsertBS(lst, lst2, groups, grp_it);
			}
			grp_it++;
			grp_ite = groups.end();
		}
		size >>= 1;
		printList(lst);
		printGroups(groups);
	}
	grp_it = groups.begin();
	std::advance(grp_it, this->n_sorted_);
	while (grp_it != grp_ite) {
		lst2 = sortInsertCut(lst, groups, grp_it);
		// std::clog << "%" << __LINE__ << "\t"; printGroups(groups);
		sortInsertBS(lst, lst2, groups, grp_it);
		grp_it++;
	}
}

t_lst	PmergeMe::sortInsertCut(t_lst& lst, t_lst_grp& groups, t_lst_grp_it& grp_it) {
	t_lst	lst2;
	size_t	size = grp_it->second / 2;
	std::clog << "&" << __LINE__ << "\t"; printGroups(groups);
	if (size == 0) {
		lst2.push_back(*(grp_it->first));
		lst.erase(grp_it->first);
		grp_it = groups.erase(grp_it);
		std::clog << "&" << __LINE__ << "\t"; printGroups(groups);
		return (lst2);
	}
	t_lst_it	it = grp_it->first;
	grp_it->second = size;
	std::advance(it, size);
	std::clog << "&" << __LINE__ << "\t"; printGroups(groups);
	lst2 = cut(lst, it, size);
	// slide
	// std::clog << "&" << __LINE__ << "\t"; printGroups(groups);
	return (lst2);
}

void	PmergeMe::swapGroup(t_lst& lst, size_t left, size_t mid) {
	std::clog << "/" << __LINE__ << "\tleft: " << left << "\tmid: " << mid << std::endl;
	std::clog << "/" << __LINE__ << "\t "; printList(lst);
	t_lst_it	it1 = lst.begin(); std::advance(it1, left);
	t_lst_it	it2 = lst.begin(); std::advance(it2, mid);
	for (size_t i = left; i < mid; i++)
		std::iter_swap(it1++, it2++);
}

void	PmergeMe::swapGroup(t_lst& lst, size_t left, size_t mid, size_t size) {
	std::clog << "/" << __LINE__ << "\tleft: " << left << "\tmid: " << mid  << "\tsize: " << size << std::endl;
	std::clog << "/" << __LINE__ << "\t "; printList(lst);
	t_lst_it	it1 = lst.begin(); std::advance(it1, left);
	t_lst_it	it2 = lst.begin(); std::advance(it2, mid);
	for (size_t i = 0; i < size; i++)
		std::iter_swap(it1++, it2++);
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

void	PmergeMe::sortInsertBS(t_lst& lst, t_lst& lst2, t_lst_grp& groups, t_lst_grp_it& grp_ite) {
	t_lst_it				pos;
	t_lst_grp_it			grp_it = groups.begin();
	t_lst::reverse_iterator	it2 = lst2.rbegin();
	t_lst::reverse_iterator	ite2 = lst2.rend();

	std::clog << "@" << __LINE__ << "\t"; printGroups(groups);
	std::clog << "@" << __LINE__ << "\tlst\t: "; printList(lst);
	std::clog << "@" << __LINE__ << "\tlst2\t: "; printList(lst2);
	pos = sortInsertBSGetPos(grp_it, lst2.front(), std::distance(groups.begin(), grp_ite));
	std::clog << "@" << __LINE__ << "\tpos: " << *pos << "\t" << *grp_ite->first << std::endl;
	while (it2 != ite2) {
		pos = lst.insert(pos, *it2);
		it2++;
	}
	std::clog << "@" << __LINE__ << "\t"; printGroups(groups);
	grp_it = groups.insert(grp_it, std::make_pair(pos, lst2.size()));
	this->n_sorted_++;
	// std::clog << "@" << __LINE__ << "\tgrp_it: " << *grp_it->first << "\t grp_ite: " << *grp_ite->first << std::endl;
	// size_t	n_slide = this->n_sorted_ - std::distance(groups.begin(), grp_it);
	// while (n_slide--) {
	// if (lst2.size() == 1) {
	// 	grp_it++;
	// 	std::clog << "@" << __LINE__ << "\t"; printGroups(groups);
	// 	std::advance(grp_it->first, lst2.size());
	// 	std::clog << "@" << __LINE__ << "\t"; printGroups(groups);
	// 	grp_ite = grp_it;
	// 	return ;
	// }
	if (grp_ite != groups.end())
		grp_ite++;
	while (grp_it != grp_ite) {
		std::clog << "@" << __LINE__ << "\t"; printGroups(groups);
		// std::clog << "@" << __LINE__ << "\tgrp_it: " << *grp_it->first << std::endl;
		std::clog << "@" << __LINE__ << "\t grp_ite: " << *grp_ite->first << std::endl;
		// std::advance(grp_ite->first, lst2.size());
		std::clog << "@" << __LINE__ << "\t"; printGroups(groups);
		grp_ite--;
	}
	// std::clog << "@" << __LINE__ << "\t"; printList(lst); printGroups(groups);
}

t_lst_it	PmergeMe::sortInsertBSGetPos(t_lst_grp_it& grp_it, int val_insert, size_t n_sought) {
	size_t	dist = 0;

	std::clog << "@" << __LINE__ << "\tn_sought: " << n_sought << "\tdist: " << dist << "\tgrp_it->first: " << *grp_it->first << std::endl;
	if (val_insert < *grp_it->first)
		return (grp_it->first);
	dist = calcMid(n_sought);
	std::advance(grp_it, n_sought - dist);
	std::clog << "@" << __LINE__ << "\tn_sought: " << n_sought << "\tdist: " << dist << std::endl;
	if (val_insert < *grp_it->first)
		dist = calcMid(n_sought - dist - 1);
	else
		dist /= 2;
	while (dist > 0) {
		std::clog << "@" << __LINE__ << "\tn_sought: " << n_sought << "\tdist: " << dist << "\tgrp_it->first: " << *grp_it->first << std::endl;
		if (*grp_it->first == val_insert)
			return (grp_it->first);
		if (*grp_it->first < val_insert)
			std::advance(grp_it, dist);
		else
			std::advance(grp_it, static_cast<int>(-dist));
		dist /= 2;
	}
	if (*grp_it->first < val_insert)
		grp_it++;
	// else if (*grp_it->first > val_insert)
	// 	grp_it--;
	return (grp_it->first);
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
	sortTriplet(lst, groups);

	this->n_sorted_ = 0;
	t_lst_grp_it	grp_it = groups.begin();
	t_lst_grp_it	grp_ite = groups.end();
	int	tmp = INT_MIN;
	while (grp_it != grp_ite) {
		if (tmp > *(grp_it->first))
			break;
		tmp = *(grp_it->first);
		this->n_sorted_++;
		grp_it++;
	}

	sortInsert(lst, groups);
*//*
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
*//*
}

void	PmergeMe::sortMergeSub(t_vec& vec, size_t left, size_t right)
{
	if (left >= right)
		return;
	size_t	mid = left + (right - left + 1) / 2;
	std::clog << "!" << __LINE__ << "\t"; printList(vec);
	std::clog << "!" << __LINE__ << "\t(" << left << ", " << mid << ", " << right << ")" << std::endl; printList(vec);
	sortMergeSub(vec, left, mid - 1);
	std::clog << "!" << __LINE__ << "\t(" << left << ", " << mid << ", " << right << ")" << std::endl; printList(vec);
	sortMergeSub(vec, mid, mid * 2 - left - 1);
	if (vec[left] < vec[mid])
		swapGroup(vec, left, mid);
	// std::clog << "@245ms "; printGroups(groups);
}

void	PmergeMe::sortMerge(t_vec& vec, size_t left, size_t right)
{
	if (left >= right)
		return;
	size_t	mid = left + calcMid((right - left + 1) / 2);

	std::clog << "#" << __LINE__ << "\t(" << left << ", " << mid << ", " << right << ")" << std::endl;
	sortMergeSub(vec, left, mid - 1);
	std::clog << "#" << __LINE__ << "\t(" << left << ", " << mid << ", " << right << ")" << std::endl;
	sortMergeSub(vec, mid, mid * 2 - left - 1);


	// if ((left != 0 || right != vec.size()) && vec[left] < vec[mid])
	if ((left == 0 && right == vec.size() - 1 && vec[left] > vec[mid]) || ((left != 0 || right != vec.size()) && vec[left] < vec[mid]))
		swapGroup(vec, left, mid);
	std::clog << "#" << __LINE__ << "m0 "; printList(vec);
	// std::clog << "#" << __LINE__ << "m0 "; printGroups(groups);
	// if (left == 0 && right == vec.size() - 1) {
	// 	std::clog << "#" << __LINE__ << "m1" << std::endl;
	// 	groups.push_back(std::make_pair(mid - left, vec[left]));
	// 	groups.push_back(std::make_pair(mid - left, vec[mid]));
	// } else if (right - left + 1 == mid - left) {
	// 	std::clog << "#" << __LINE__ << "m2" << std::endl;
	// 	groups.push_back(std::make_pair(mid - left, vec[left]));
	// }
	// std::clog << "#" << __LINE__ << "m3 "; printGroups(groups);
	if (mid * 2 - left < right)
		sortMerge(vec, mid * 2 - left, right);
	// std::clog << "#" << __LINE__ << "m4 "; printGroups(groups);
}

t_vec_grp	PmergeMe::initGroup(t_vec& vec)
{
	t_vec_grp	groups;
	t_vec_it	it = vec.begin();
	size_t		size = vec.size();
	size_t		sub_size = calcMid(size / 2);

	groups.push_back(std::make_pair(it, sub_size));
	std::advance(it, sub_size);
	groups.push_back(std::make_pair(it, sub_size));
	std::advance(it, sub_size);
	size_t	i = sub_size * 2;
	std::clog << "$" << __LINE__ << "\ti: " << i << "\tsub_size" << sub_size << "\tsize" << size << std::endl;
	printGroups(groups);
	while (i < size) {
		sub_size = calcMid(size - i);
		std::clog << "$" << __LINE__ << "\ti: " << i << "\tsub_size" << sub_size << std::endl;
		groups.push_back(std::make_pair(it, sub_size));
		i += sub_size;
		std::advance(it, sub_size);
		printGroups(groups);
	}
	return (groups);
}

void	PmergeMe::sortTriplet(t_vec& vec, t_vec_grp& groups) {
	size_t	size = groups[0].second;

	if (groups.size() < 3 || groups[2].second != size)
		return ;
	if (*groups[0].first > *groups[2].first)
		swapGroup(vec, 0, size * 2, size);
	if (*groups[0].first > *groups[1].first)
		swapGroup(vec, 0, size, size);
	if (*groups[1].first> *groups[2].first)
		swapGroup(vec, size, size * 2, size);
}

void	PmergeMe::sortInsert(t_vec& vec, t_vec_grp& groups) {
	t_vec_grp_it	grp_it;
	t_vec_grp_it	grp_ite;
	t_vec			vec2;
	size_t			size = groups.begin()->second;

	while (size > 1) {
		grp_it = groups.begin();
		size_t	i = 0;
		while (grp_it != grp_ite) {
			std::clog << "%" << __LINE__ << "\ti: " << i++ << std::endl;
			std::clog << "%" << __LINE__ << "\tn_sorted: " << this->n_sorted_ << "\tit->second: " << grp_it->second << "\t" << "it->first: " << *(grp_it->first) << std::endl;
			std::clog << "%" << __LINE__ << "\t"; printGroups(groups);
			if (grp_it->second == size) {
				vec2 = sortInsertCut(vec, groups, grp_it);
				// std::clog << "%" << __LINE__ << "\t"; printGroups(groups);
				sortInsertBS(vec, vec2, groups, grp_it);
			}
			grp_it++;
			grp_ite = groups.end();
		}
		size >>= 1;
		printList(vec);
		printGroups(groups);
	}
	grp_it = groups.begin();
	std::advance(grp_it, this->n_sorted_);
	while (grp_it != grp_ite) {
		vec2 = sortInsertCut(vec, groups, grp_it);
		// std::clog << "%" << __LINE__ << "\t"; printGroups(groups);
		sortInsertBS(vec, vec2, groups, grp_it);
		grp_it++;
	}
}

t_vec	PmergeMe::sortInsertCut(t_vec& vec, t_vec_grp& groups, t_vec_grp_it& grp_it) {
	t_vec	vec2;
	size_t	size = grp_it->second / 2;
	std::clog << "&" << __LINE__ << "\t"; printGroups(groups);
	if (size == 0) {
		vec2.push_back(*(grp_it->first));
		vec.erase(grp_it->first);
		grp_it = groups.erase(grp_it);
		std::clog << "&" << __LINE__ << "\t"; printGroups(groups);
		return (vec2);
	}
	t_vec_it	it = grp_it->first;
	grp_it->second = size;
	std::advance(it, size);
	std::clog << "&" << __LINE__ << "\t"; printGroups(groups);
	vec2 = cut(vec, it, size);
	// slide
	// std::clog << "&" << __LINE__ << "\t"; printGroups(groups);
	return (vec2);
}

void	PmergeMe::swapGroup(t_vec& vec, size_t left, size_t mid) {
	std::clog << "/" << __LINE__ << "\tleft: " << left << "\tmid: " << mid << std::endl;
	std::clog << "/" << __LINE__ << "\t "; printList(vec);
	t_vec_it	it1 = vec.begin() + left;
	t_vec_it	it2 = vec.begin() + mid;
	for (size_t i = left; i < mid; i++)
		std::iter_swap(it1++, it2++);
}

void	PmergeMe::swapGroup(t_vec& vec, size_t left, size_t mid, size_t size) {
	std::clog << "/" << __LINE__ << "\tleft: " << left << "\tmid: " << mid  << "\tsize: " << size << std::endl;
	std::clog << "/" << __LINE__ << "\t "; printList(vec);
	t_vec_it	it1 = vec.begin() + left;
	t_vec_it	it2 = vec.begin() + mid;
	for (size_t i = 0; i < size; i++)
		std::iter_swap(it1++, it2++);
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
*//*
void	PmergeMe::sortInsertBS(t_vec& vec, t_vec& vec2, t_vec_grp& groups, t_vec_grp_it& grp_ite) {
	t_vec_grp_it			grp_it = groups.begin();
	t_vec_it				pos;
	t_vec::reverse_iterator	it2 = vec2.rbegin();
	t_vec::reverse_iterator	ite2 = vec2.rend();
	size_t					dist = 0;

	std::clog << "@" << __LINE__ << "\tvec\t: "; printList(vec);
	std::clog << "@" << __LINE__ << "\tvec2\t: "; printList(vec2);
	std::clog << "@" << __LINE__ << "\t"; printGroups(groups);
	if (*grp_it->first < vec2[0]) {
		dist = this->n_sorted_ / 2;
		std::advance(grp_it, dist);
		dist /= 2;
	}
	while (dist > 0) {
		std::clog << "@" << __LINE__ << "\tn_sorted_: " << this->n_sorted_ << "\tdist: " << dist << "\tgrp_it->first: " << *grp_it->first << std::endl;
		if (*grp_it->first == vec2[0])
			break;
		if (*grp_it->first < vec2[0])
			std::advance(grp_it, dist);
		else if (dist > 1)
			std::advance(grp_it, static_cast<int>(-dist));
		dist /= 2;
	}
	pos = grp_it->first;
	std::clog << "@" << __LINE__ << "\tpos: " << *pos << "\t" << *grp_ite->first << std::endl;
	while (it2 != ite2) {
		pos = vec.insert(pos, *it2);
		it2++;
	}
	std::clog << "@" << __LINE__ << "\t"; printGroups(groups);
	grp_it = groups.insert(grp_it, std::make_pair(pos, vec2.size()));
	this->n_sorted_++;
	// std::clog << "@" << __LINE__ << "\tgrp_it: " << *grp_it->first << "\t grp_ite: " << *grp_ite->first << std::endl;
	// size_t	n_slide = this->n_sorted_ - std::distance(groups.begin(), grp_it);
	// while (n_slide--) {
	if (vec2.size() == 1) {
		grp_it++;
		std::clog << "@" << __LINE__ << "\t"; printGroups(groups);
		std::advance(grp_it->first, vec2.size());
		std::clog << "@" << __LINE__ << "\t"; printGroups(groups);
		grp_ite = grp_it;
		return ;
	}
	grp_ite++;
	while (grp_it != grp_ite) {
		std::clog << "@" << __LINE__ << "\t"; printGroups(groups);
		std::clog << "@" << __LINE__ << "\tgrp_it: " << *grp_it->first << "\t grp_ite: " << *grp_ite->first << std::endl;
		std::advance(grp_ite->first, vec2.size());
		std::clog << "@" << __LINE__ << "\t"; printGroups(groups);
		grp_ite--;
	}
	// std::clog << "@" << __LINE__ << "\t"; printList(vec); printGroups(groups);
}
*//*

void	PmergeMe::sortInsertBS(t_vec& vec, t_vec& vec2, t_vec_grp& groups, t_vec_grp_it& grp_ite) {
	t_vec_it				pos;
	t_vec_grp_it			grp_it = groups.begin();
	t_vec::reverse_iterator	it2 = vec2.rbegin();
	t_vec::reverse_iterator	ite2 = vec2.rend();

	std::clog << "@" << __LINE__ << "\t"; printGroups(groups);
	std::clog << "@" << __LINE__ << "\tvec\t: "; printList(vec);
	std::clog << "@" << __LINE__ << "\tvec2\t: "; printList(vec2);
	pos = sortInsertBSGetPos(grp_it, vec2.front(), std::distance(groups.begin(), grp_ite));
	std::clog << "@" << __LINE__ << "\tpos: " << *pos << "\t" << *grp_ite->first << std::endl;
	while (it2 != ite2) {
		pos = vec.insert(pos, *it2);
		it2++;
	}
	std::clog << "@" << __LINE__ << "\t"; printGroups(groups);
	grp_it = groups.insert(grp_it, std::make_pair(pos, vec2.size()));
	this->n_sorted_++;
	// std::clog << "@" << __LINE__ << "\tgrp_it: " << *grp_it->first << "\t grp_ite: " << *grp_ite->first << std::endl;
	// size_t	n_slide = this->n_sorted_ - std::distance(groups.begin(), grp_it);
	// while (n_slide--) {
	// if (vec2.size() == 1) {
	// 	grp_it++;
	// 	std::clog << "@" << __LINE__ << "\t"; printGroups(groups);
	// 	std::advance(grp_it->first, vec2.size());
	// 	std::clog << "@" << __LINE__ << "\t"; printGroups(groups);
	// 	grp_ite = grp_it;
	// 	return ;
	// }
	if (grp_ite != groups.end())
		grp_ite++;
	while (grp_it != grp_ite) {
		std::clog << "@" << __LINE__ << "\t"; printGroups(groups);
		// std::clog << "@" << __LINE__ << "\tgrp_it: " << *grp_it->first << std::endl;
		std::clog << "@" << __LINE__ << "\t grp_ite: " << *grp_ite->first << std::endl;
		// std::advance(grp_ite->first, vec2.size());
		std::clog << "@" << __LINE__ << "\t"; printGroups(groups);
		grp_ite--;
	}
	// std::clog << "@" << __LINE__ << "\t"; printList(vec); printGroups(groups);
}

t_vec_it	PmergeMe::sortInsertBSGetPos(t_vec_grp_it& grp_it, int val_insert, size_t n_sought) {
	size_t	dist = 0;

	std::clog << "@" << __LINE__ << "\tn_sought: " << n_sought << "\tdist: " << dist << "\tgrp_it->first: " << *grp_it->first << std::endl;
	if (val_insert < *grp_it->first)
		return (grp_it->first);
	dist = calcMid(n_sought);
	std::advance(grp_it, n_sought - dist);
	std::clog << "@" << __LINE__ << "\tn_sought: " << n_sought << "\tdist: " << dist << std::endl;
	if (val_insert < *grp_it->first)
		dist = calcMid(n_sought - dist - 1);
	else
		dist /= 2;
	while (dist > 0) {
		std::clog << "@" << __LINE__ << "\tn_sought: " << n_sought << "\tdist: " << dist << "\tgrp_it->first: " << *grp_it->first << std::endl;
		if (*grp_it->first == val_insert)
			return (grp_it->first);
		if (*grp_it->first < val_insert)
			std::advance(grp_it, dist);
		else
			std::advance(grp_it, static_cast<int>(-dist));
		dist /= 2;
	}
	if (*grp_it->first < val_insert)
		grp_it++;
	// else if (*grp_it->first > val_insert)
	// 	grp_it--;
	return (grp_it->first);
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
	sortTriplet(vec, groups);

	this->n_sorted_ = 0;
	t_vec_grp_it	grp_it = groups.begin();
	t_vec_grp_it	grp_ite = groups.end();
	int	tmp = INT_MIN;
	while (grp_it != grp_ite) {
		if (tmp > *(grp_it->first))
			break;
		tmp = *(grp_it->first);
		this->n_sorted_++;
		grp_it++;
	}

	sortInsert(vec, groups);

// https://cpprefjp.github.io/reference/vector/vector/insert.html
// https://cpprefjp.github.io/reference/vector/vector/erase.html
*//*	t_vec_it	it1 = vec.begin();
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
*//*
}
*/
/*
void	PmergeMe::move(t_vec& vec, \
	t_vec_it& pos, t_vec_it& second, t_vec_it& last) {

}
*/
/*
void	PmergeMe::move(t_vec& vec, \
	t_vec_it& pos, t_vec_it& second, t_vec_it& last) {
	t_vec	tmp(second, ++last);
	t_vec_it			tmp_begin = tmp.begin();
	t_vec_it			tmp_end = tmp.end();
	t_vec_it			copy_second = second;
	t_vec_it			copy_last = last;
	std::clog << "vec      \t[" << &vec << "]" <<std::endl;
	std::clog << "second    \t[" << &second << "] : [" << &(*second) << "] " << *second <<std::endl;
	std::clog << "last     \t[" << &last << "] : [" << &(*last) << "] " << *last <<std::endl;
	std::clog << "pos     \t[" << &pos << "] : [" << &(*pos) << "] " << *pos <<std::endl;
	std::clog << "tmp      \t[" << &tmp << "]" <<std::endl;
	std::clog << "tmp_begin\t[" << &tmp_begin << "] : [" << &(*tmp_begin) << "]" << *tmp_begin <<std::endl;
	std::clog << "tmp_end  \t[" << &tmp_end << "]" <<std::endl;
	std::clog << "copy_second\t[" << &copy_second << "] : [" << &(*copy_second) << "] " << *copy_second <<std::endl;
	std::clog << "copy_last\t[" << &copy_last << "] : [" << &(*copy_last) << "] " << *copy_last <<std::endl;
	printList(tmp);
	// tmp_end--;
	std::clog << "before insert" << std::endl;
	vec.insert(pos, tmp_begin, tmp_end);
	std::clog << "after insert" << std::endl;
	printList(vec);
	(void)pos;
	// pos = last;
	vec.erase(copy_second, copy_last);
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
	// Initial index of second subarray
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
