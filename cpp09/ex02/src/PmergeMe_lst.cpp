/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe_lst.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/11/11 15:37:26 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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
}

void	PmergeMe::sortMerge(t_lst& lst, size_t left, size_t right)
{
	if (left >= right)
		return;
	size_t	mid = left + calcMid((right - left + 1) / 2);

	std::clog << LABEL_SM_ << __LINE__ << "\t(" << left << ", " << mid << ", " << right << ")" << std::endl;
	sortMergeSub(lst, left, mid - 1);
	std::clog << LABEL_SM_ << __LINE__ << "\t(" << left << ", " << mid << ", " << right << ")" << std::endl;
	sortMergeSub(lst, mid, mid * 2 - left - 1);
	t_lst_it	it1 = lst.begin(); std::advance(it1, left);
	t_lst_it	it2 = lst.begin(); std::advance(it2, mid);
	if ((left == 0 && right == lst.size() - 1 && *it1 > *it2) || ((left != 0 || right != lst.size()) && *it1 < *it2)) {
	// if ((left != 0 || right != lst.size()) && *it1 < *it2) {
		// t_lst_it	it1_copy = it1;
		// t_lst_it	it2_copy = it2;
		for (size_t i = left; i < mid; i++)
			std::iter_swap(it1++, it2++);
	}
	std::clog << LABEL_SM_ << __LINE__ << "\t"; printList(lst);
	if (mid * 2 - left < right)
		sortMerge(lst, mid * 2 - left, right);
}

void	PmergeMe::sortMergeSub(t_lst& lst, size_t left, size_t right)
{
	if (left >= right)
		return;
	size_t	mid = left + (right - left + 1) / 2;
	std::clog << LABEL_SMS << __LINE__ << "\t"; printList(lst);
	std::clog << LABEL_SMS << __LINE__ << "\t(" << left << ", " << mid << ", " << right << ") "; printList(lst);
	sortMergeSub(lst, left, mid - 1);
	std::clog << LABEL_SMS << __LINE__ << "\t(" << left << ", " << mid << ", " << right << ") "; printList(lst);
	sortMergeSub(lst, mid, mid * 2 - left - 1);
	t_lst_it	it1 = lst.begin(); std::advance(it1, left);
	t_lst_it	it2 = lst.begin(); std::advance(it2, mid);
	if (*it1 < *it2) {
		for (size_t i = left; i < mid; i++)
			std::iter_swap(it1++, it2++);
	}
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
	std::clog << LABEL_IG_ << __LINE__ << "\ti: " << i << "\tsub_size: " << sub_size << "\tsize: " << size << std::endl;
	std::clog << LABEL_IG_ << __LINE__ << "\t"; printGroups(groups);
	while (i < size) {
		sub_size = calcMid(size - i);
		std::clog << LABEL_IG_ << __LINE__ << "\ti: " << i << "\tsub_size: " << sub_size << std::endl;
		groups.push_back(std::make_pair(it, sub_size));
		i += sub_size;
		std::advance(it, sub_size);
		std::clog << LABEL_IG_ << __LINE__ << "\t"; printGroups(groups);
	}
	return (groups);
}

void	PmergeMe::sortTriplet(t_lst& lst, t_lst_grp& groups) {
	size_t	size = groups.begin()->second;

	if (groups.size() < 3)
		return ;
	t_lst_grp_it	it0 = groups.begin();
	t_lst_grp_it	it1 = it0; it1++;
	t_lst_grp_it	it2 = it1; it2++;
	if (it2->second != size)
		return ;
	std::clog << LABEL_ST_ << __LINE__ << "\tgrp0: " << *it0->first << "\tgrp1: " << *it1->first << "\tgrp2: " << *it2->first << std::endl;
	if (*it0->first > *it2->first)
		swapGroup(lst, 0, size * 2, size);
	if (*it0->first > *it1->first)
		swapGroup(lst, 0, size, size);
	if (*it1->first > *it2->first)
		swapGroup(lst, size, size * 2, size);
}

void	PmergeMe::sortInsert(t_lst& lst, t_lst_grp& groups) {
	t_lst_grp_it	grp_it;
	t_lst_grp_it	grp_ite;
	t_lst			lst2;
	size_t			size = groups.begin()->second;

	while (size > 1) {
		grp_it = groups.begin();
		size_t	i = 0; // __LINE__
		while (grp_it != grp_ite) {
			std::clog << LABEL_SI_ << __LINE__ << "\tsize: " << size << "\ti: " << i++ << std::endl;
			std::clog << LABEL_SI_ << __LINE__ << "\tn_sorted: " << this->n_sorted_ << "\tit->second: " << grp_it->second << "\t" << "it->first: " << *(grp_it->first) << std::endl;
			std::clog << LABEL_SI_ << __LINE__ << "\t"; printGroups(groups);
			if (grp_it->second == size) {
				lst2 = sortInsertCut(lst, groups, grp_it);
				sortInsertBS(lst, lst2, groups, grp_it);
			}
			grp_it++;
			grp_ite = groups.end();
		}
		size >>= 1;
		std::clog << LABEL_SI_ << __LINE__ << "\t"; printList(lst);
		std::clog << LABEL_SI_ << __LINE__ << "\t"; printGroups(groups);
	}
	grp_it = groups.begin();
	std::advance(grp_it, this->n_sorted_);
	while (grp_it != grp_ite) {
	// while (grp_it != grp_ite && this->n_sorted_ <= groups.size()) {
		std::clog << LABEL_SI_ << __LINE__ << "\tn_sorted: " << this->n_sorted_ << "\tgrp_it: " << *(grp_it->first) << "\tdist: " << std::distance(grp_it, grp_ite) << std::endl;
		lst2 = sortInsertCut(lst, groups, grp_it);
		std::clog << LABEL_SI_ << __LINE__ << "\tn_sorted: " << this->n_sorted_ << "\tgrp_it: " << *(grp_it->first) << "\tdist: " << std::distance(grp_it, grp_ite) << std::endl;

		sortInsertBS(lst, lst2, groups, grp_it);
		grp_it++;
	}
}

t_lst	PmergeMe::sortInsertCut(t_lst& lst, t_lst_grp& groups, t_lst_grp_it& grp_it) {
	t_lst	lst2;
	size_t	size = grp_it->second / 2;
	size_t	dist;
	std::clog << LABEL_SIC << __LINE__ << "\t"; printGroups(groups);
	if (size == 0) {
		dist = std::distance(groups.begin(), grp_it);
		std::clog << LABEL_SIC << __LINE__ << "\tdist: " << dist << std::endl;
		lst2.push_back(*(grp_it->first));
		lst.erase(grp_it->first);
		grp_it = groups.erase(grp_it);
		grp_it = groups.begin(); std::advance(grp_it, dist - 1);
		std::clog << LABEL_SIC << __LINE__ << "\t"; printGroups(groups);
		std::clog << LABEL_SIC << __LINE__ << "\tgrp_it: " << *grp_it->first << std::endl;
		return (lst2);
	}
	t_lst_it	it = grp_it->first;
	grp_it->second = size;
	std::advance(it, size);
	std::clog << LABEL_SIC << __LINE__ << "\t"; printGroups(groups);
	std::clog << LABEL_SIC << __LINE__ << "\tgrp_it: " << *grp_it->first << "\tdist: " << std::distance(groups.begin(), grp_it) << std::endl;
	std::clog << LABEL_SIC << __LINE__ << "\tit: " << *it << "\tdist: " << std::distance(lst.begin(), it) << std::endl;
	lst2 = cut(lst, it, size);
	std::clog << LABEL_SIC << __LINE__ << "\tseq : "; printList(lst);
	std::clog << LABEL_SIC << __LINE__ << "\tseq2: "; printList(lst2);
	std::clog << LABEL_SIC << __LINE__ << "\t"; printGroups(groups);
	std::clog << LABEL_SIC << __LINE__ << "\tgrp_it: " << *grp_it->first << "\tdist: " << std::distance(groups.begin(), grp_it) << std::endl;
	return (lst2);
}

void	PmergeMe::sortInsertBS(t_lst& lst, t_lst& lst2, t_lst_grp& groups, t_lst_grp_it& grp_ite) {
	t_lst_it				pos;
	t_lst_grp_it			grp_it = groups.begin();
	t_lst::reverse_iterator	it2 = lst2.rbegin();
	t_lst::reverse_iterator	ite2 = lst2.rend();
	size_t					dist;

	std::clog << LABEL_BS_ << __LINE__ << "\t"; printGroups(groups);
	std::clog << LABEL_BS_ << __LINE__ << "\tseq : "; printList(lst);
	std::clog << LABEL_BS_ << __LINE__ << "\tseq2: "; printList(lst2);
	pos = sortInsertBSGetPos(grp_it, lst2.front(), std::distance(grp_it, grp_ite));
	// std::clog << LABEL_BS_ << __LINE__ << "\tpos: " << *pos << std::endl;
	// std::clog << LABEL_BS_ << __LINE__ << "\tgrp_ite: " << *grp_ite->first << std::endl;
	while (it2 != ite2) {
		std::clog << LABEL_BS_ << __LINE__ << "\tite2: " << *ite2 << "\tdist: " << std::distance(pos, lst.end()) << std::endl;
		if (pos == lst.end())
			lst.push_back(*it2);
		else
			pos = lst.insert(pos, *it2);
		std::clog << LABEL_BS_ << __LINE__ << "\tit2: " << *it2 << "\tpos: " << *pos << std::endl;
		it2++;
	}
	dist = std::distance(grp_it, grp_ite);
	// std::clog << LABEL_BS_ << __LINE__ << "\t"; printGroups(groups);
	std::clog << LABEL_BS_ << __LINE__ << "\tdist: " << std::distance(grp_it, grp_ite) << "\tgrp_it: " << *grp_it->first << "\tgrp_ite: " << *grp_ite->first << std::endl;
	grp_it = groups.insert(grp_it, std::make_pair(pos, lst2.size()));
	grp_ite = grp_it; std::advance(grp_ite, dist + 1);
	this->n_sorted_++;
	std::clog << LABEL_BS_ << __LINE__ << "\t"; printGroups(groups);
	std::clog << LABEL_BS_ << __LINE__ << "\tdist: " << std::distance(grp_it, grp_ite) << "\tgrp_it: " << *grp_it->first << "\tgrp_ite: " << *grp_ite->first << std::endl;
	// while (grp_it != grp_ite) {
	// 	std::clog << LABEL_BS_ << __LINE__ << "\t"; printGroups(groups);
	// 	std::clog << LABEL_BS_ << __LINE__ << "\tgrp_it: " << *grp_it->first << "\tgrp_ite: " << *grp_ite->first << "\tdist: " << std::distance(grp_it, grp_ite) << std::endl;

	// 	grp_ite--;
	// }
}

t_lst_it	PmergeMe::sortInsertBSGetPos(t_lst_grp_it& grp_it, int val_insert, size_t n_sought) {
	size_t			delta = 0;
	t_lst_grp_it	grp_itb = grp_it;

	std::clog << LABEL_BSP << __LINE__ << "\tn_sought: " << n_sought << "\tdelta: " << delta << "\tgrp_it->first: " << *grp_it->first << std::endl;
	if (val_insert <= *grp_it->first)
		return (grp_it->first);
	std::advance(grp_it, n_sought);
	std::clog << LABEL_BSP << __LINE__ << "\tdist: " << std::distance(grp_itb, grp_it) << std::endl;
	if (val_insert > *grp_it->first) {
		t_lst_it	it = grp_it->first;
		std::advance(it, grp_it->second);
			return (it);
	}
	grp_it = grp_itb;

	delta = calcMid(n_sought);
	std::advance(grp_it, n_sought - delta);
	std::clog << LABEL_BSP << __LINE__ << "\tn_sought: " << n_sought << "\tdelta: " << delta << std::endl;
	if (val_insert < *grp_it->first)
		delta = calcMid(n_sought - delta - 1);
	else {
		// std::advance(grp_it, delta);
		// if (val_insert > *grp_it->first)
		// 	return (grp_it->first);
		delta /= 2;
	}
	while (delta > 0) {
		std::clog << LABEL_BSP << __LINE__ << "\tn_sought: " << n_sought << "\tdelta: " << delta << "\tdist: " << std::distance(grp_itb, grp_it) << "\tgrp_it->first: " << *grp_it->first << std::endl;
		if (*grp_it->first == val_insert)
			return (grp_it->first);
		if (*grp_it->first < val_insert)
			std::advance(grp_it, delta);
		else if (delta > static_cast<size_t>(std::distance(grp_itb, grp_it)))
			grp_it = grp_itb;
		else
			std::advance(grp_it, static_cast<int>(-delta));
		std::clog << LABEL_BSP << __LINE__ << "\tn_sought: " << n_sought << "\tdelta: " << delta << "\tdist: " << std::distance(grp_itb, grp_it) << "\tgrp_it->first: " << *grp_it->first << std::endl;
		delta /= 2;
	}
	if (*grp_it->first < val_insert)
		grp_it++;
	return (grp_it->first);
}

void	PmergeMe::swapGroup(t_lst& lst, size_t left, size_t mid) {
	std::clog << LABEL_SG_ << __LINE__ << "\tleft: " << left << "\tmid: " << mid << std::endl;
	std::clog << LABEL_SG_ << __LINE__ << "\t"; printList(lst);
	t_lst_it	it1 = lst.begin(); std::advance(it1, left);
	t_lst_it	it2 = lst.begin(); std::advance(it2, mid);
	for (size_t i = left; i < mid; i++)
		std::iter_swap(it1++, it2++);
}

void	PmergeMe::swapGroup(t_lst& lst, size_t left, size_t mid, size_t size) {
	std::clog << LABEL_SG_ << __LINE__ << "\tleft: " << left << "\tmid: " << mid  << "\tsize: " << size << std::endl;
	std::clog << LABEL_SG_ << __LINE__ << "\t "; printList(lst);
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
	std::clog << LABEL_C__ << __LINE__ << "\tseq : "; printList(lst);
	std::clog << LABEL_C__ << __LINE__ << "\tseq2: "; printList(lst2);
	lst.erase(it, it2);
	std::clog << LABEL_C__ << __LINE__ << "\tseq : "; printList(lst);
	std::clog << LABEL_C__ << __LINE__ << "\tseq2: "; printList(lst2);
	return (lst2);
}
