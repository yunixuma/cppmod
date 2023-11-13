/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe_vec.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/11/14 02:07:26 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	PmergeMe::sort(t_vec& seq) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<PmergeMe> sort called" << std::endl;
	std::clog << &seq << "\t<" << typeid(seq).name() \
		<< ">\033[m" << std::endl;
	if (sortCheck(seq))
		return ;
	sortMerge(seq, 0, seq.size() - 1);
	t_vec_grp	groups = initGroup(seq);
	sortTriplet(seq, groups);

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
	sortInsert(seq, groups);
}

void	PmergeMe::sortMerge(t_vec& seq, size_t left, size_t right)
{
	if (left >= right)
		return;
	size_t	mid = left + calcMid((right - left + 1) / 2);

//	std::clog << LABEL_SM_ << __LINE__ << "\t(" << left << ", " << mid << ", " << right << ")" << std::endl;
	sortMergeSub(seq, left, mid - 1);
//	std::clog << LABEL_SM_ << __LINE__ << "\t(" << left << ", " << mid << ", " << right << ")" << std::endl;
	sortMergeSub(seq, mid, mid * 2 - left - 1);


	// if ((left != 0 || right != seq.size()) && seq[left] < seq[mid])
	if ((left == 0 && right == seq.size() - 1 && seq[left] > seq[mid]) || ((left != 0 || right != seq.size()) && seq[left] < seq[mid])) {


		swapGroup(seq, left, mid);
	}
//	std::clog << LABEL_SM_ << __LINE__ << "\t"; printList(seq);
	if (mid * 2 - left < right)
		sortMerge(seq, mid * 2 - left, right);
}

void	PmergeMe::sortMergeSub(t_vec& seq, size_t left, size_t right)
{
	if (left >= right)
		return;
	size_t	mid = left + (right - left + 1) / 2;
//	std::clog << LABEL_SMS << __LINE__ << "\t"; printList(seq);
//	std::clog << LABEL_SMS << __LINE__ << "\t(" << left << ", " << mid << ", " << right << ") "; printList(seq);
	sortMergeSub(seq, left, mid - 1);
//	std::clog << LABEL_SMS << __LINE__ << "\t(" << left << ", " << mid << ", " << right << ") "; printList(seq);
	sortMergeSub(seq, mid, mid * 2 - left - 1);
	// t_vec_it	it1 = seq.begin(); std::advance(it1, left);
	// t_vec_it	it2 = seq.begin(); std::advance(it2, mid);
	if (seq[left] < seq[mid])
		swapGroup(seq, left, mid);
}

t_vec_grp	PmergeMe::initGroup(t_vec& seq)
{
	t_vec_grp	groups;
	t_vec_it	it = seq.begin();
	size_t		size = seq.size();
	size_t		sub_size = calcMid(size / 2);

	groups.push_back(std::make_pair(it, sub_size));
	it += sub_size;
	groups.push_back(std::make_pair(it, sub_size));
	it += sub_size;
	size_t	i = sub_size * 2;
//	std::clog << LABEL_IG_ << __LINE__ << "\ti: " << i << "\tsub_size: " << sub_size << "\tsize: " << size << std::endl;
//	std::clog << LABEL_IG_ << __LINE__ << "\t"; printGroups(groups);
	while (i < size) {
		sub_size = calcMid(size - i);
//		std::clog << LABEL_IG_ << __LINE__ << "\ti: " << i << "\tsub_size: " << sub_size << std::endl;
		groups.push_back(std::make_pair(it, sub_size));
		i += sub_size;
		it += sub_size;
//		std::clog << LABEL_IG_ << __LINE__ << "\t"; printGroups(groups);
	}
	return (groups);
}

void	PmergeMe::sortTriplet(t_vec& seq, t_vec_grp& groups) {
	size_t	size = groups[0].second;
	if (groups.size() < 3 || groups[2].second != size)
		return ;





//	std::clog << LABEL_ST_ << __LINE__ << "\t"; printList(seq);
//	std::clog << LABEL_ST_ << __LINE__ << "\t"; printGroups(groups);
//	std::clog << LABEL_ST_ << __LINE__ << "\tgrp0: " << *groups[0].first << "\tgrp1: " << *groups[1].first << "\tgrp2: " << *groups[2].first << std::endl;
	if (*groups[0].first > *groups[2].first)
		swapGroup(seq, 0, size * 2, size);
//	std::clog << LABEL_ST_ << __LINE__ << "\t"; printList(seq);
//	std::clog << LABEL_ST_ << __LINE__ << "\t"; printGroups(groups);
//	std::clog << LABEL_ST_ << __LINE__ << "\tgrp0: " << *groups[0].first << "\tgrp1: " << *groups[1].first << "\tgrp2: " << *groups[2].first << std::endl;
	if (*groups[0].first > *groups[1].first)
		swapGroup(seq, 0, size, size);
//	std::clog << LABEL_ST_ << __LINE__ << "\t"; printList(seq);
//	std::clog << LABEL_ST_ << __LINE__ << "\t"; printGroups(groups);
//	std::clog << LABEL_ST_ << __LINE__ << "\tgrp0: " << *groups[0].first << "\tgrp1: " << *groups[1].first << "\tgrp2: " << *groups[2].first << std::endl;
	if (*groups[1].first> *groups[2].first)
		swapGroup(seq, size, size * 2, size);
//	std::clog << LABEL_ST_ << __LINE__ << "\t"; printList(seq);
//	std::clog << LABEL_ST_ << __LINE__ << "\t"; printGroups(groups);
//	std::clog << LABEL_ST_ << __LINE__ << "\tgrp0: " << *groups[0].first << "\tgrp1: " << *groups[1].first << "\tgrp2: " << *groups[2].first << std::endl;
}

void	PmergeMe::sortInsert(t_vec& seq, t_vec_grp& groups) {
	t_vec_grp_it	grp_it;
	t_vec_grp_it	grp_ite;
	t_vec			seq2;
	size_t			size = groups.begin()->second;

	while (size > 1) {
		grp_it = groups.begin();
//		size_t	i = 0; // __LINE__
		while (grp_it != grp_ite) {
//			std::clog << LABEL_SI_ << __LINE__ << "\tsize: " << size << "\ti: " << i++ << std::endl;
//			std::clog << LABEL_SI_ << __LINE__ << "\tn_sorted: " << this->n_sorted_ << "\tit->second: " << grp_it->second << "\t" << "it->first: " << *(grp_it->first) << std::endl;
//			std::clog << LABEL_SI_ << __LINE__ << "\t"; printGroups(groups);
			if (grp_it->second == size) {
				seq2 = sortInsertCut(seq, groups, grp_it);
				sortInsertBS(seq, seq2, groups, grp_it);
			}
			grp_it++;
			grp_ite = groups.end();
		}
		size >>= 1;
//		std::clog << LABEL_SI_ << __LINE__ << "\t"; printList(seq);
//		std::clog << LABEL_SI_ << __LINE__ << "\t"; printGroups(groups);
	}
	grp_it = groups.begin() + this->n_sorted_;
	while (grp_it != grp_ite) {
	// while (grp_it != grp_ite && this->n_sorted_ <= groups.size()) {
//		std::clog << LABEL_SI_ << __LINE__ << "\tn_sorted: " << this->n_sorted_ << "\tdist: " << std::distance(grp_it, grp_ite) << std::endl;
//		// std::clog << LABEL_SI_ << __LINE__ << "\tgrp_it: " << *(grp_it->first) << std::endl;
		seq2 = sortInsertCut(seq, groups, grp_it);
//		std::clog << LABEL_SI_ << __LINE__ << "\tn_sorted: " << this->n_sorted_ << "\tgrp_it: " << *(grp_it->first) << "\tdist: " << std::distance(grp_it, grp_ite) << std::endl;
		sortInsertBS(seq, seq2, groups, grp_it);
		grp_it = groups.begin() + this->n_sorted_;
//		std::clog << LABEL_SI_ << __LINE__ << "\tn_sorted: " << this->n_sorted_ << "\tdist: " << std::distance(grp_it, grp_ite) << std::endl;
//		// std::clog << LABEL_SI_ << __LINE__ << "\tgrp_it: " << *(grp_it->first) << std::endl;
//		std::clog << LABEL_SI_ << __LINE__ << "\t"; printList(seq);
//		std::clog << LABEL_SI_ << __LINE__ << "\t"; printGroups(groups);
	}
}

t_vec	PmergeMe::sortInsertCut(t_vec& seq, t_vec_grp& groups, t_vec_grp_it& grp_it) {
	t_vec	seq2;
	size_t	size = grp_it->second / 2;
	size_t	dist;
//	// std::clog << LABEL_SIC << __LINE__ << "\t"; printGroups(groups);
	if (size == 0) {
		dist = std::distance(groups.begin(), grp_it);
//		std::clog << LABEL_SIC << __LINE__ << "\tdist: " << dist << std::endl;
		seq2.push_back(*(grp_it->first));
		seq.erase(grp_it->first);
		grp_it = groups.erase(grp_it);
//		std::clog << LABEL_SIC << __LINE__ << "\tdist: " << std::distance(groups.begin(), grp_it) << std::endl;
		grp_it = groups.begin() + dist - 1;
//		// std::clog << LABEL_SIC << __LINE__ << "\t"; printGroups(groups);
//		std::clog << LABEL_SIC << __LINE__ << "\tdist: " << std::distance(groups.begin(), grp_it) << std::endl;
		return (seq2);
	}
	t_vec_it	it = grp_it->first;
	grp_it->second = size;
	it += size;
//	std::clog << LABEL_SIC << __LINE__ << "\t"; printGroups(groups);
//	std::clog << LABEL_SIC << __LINE__ << "\tgrp_it: " << *grp_it->first << "\tdist: " << std::distance(groups.begin(), grp_it) << std::endl;
//	std::clog << LABEL_SIC << __LINE__ << "\tit: " << *it << "\tdist: " << std::distance(seq.begin(), it) << std::endl;
	seq2 = cut(seq, it, size);
//	std::clog << LABEL_SIC << __LINE__ << "\tseq : "; printList(seq);
//	std::clog << LABEL_SIC << __LINE__ << "\tseq2: "; printList(seq2);
//	// std::clog << LABEL_SIC << __LINE__ << "\t"; printGroups(groups);
//	std::clog << LABEL_SIC << __LINE__ << "\tgrp_it: " << *grp_it->first << "\tdist: " << std::distance(groups.begin(), grp_it) << std::endl;
	return (seq2);
}

void	PmergeMe::sortInsertBS(t_vec& seq, t_vec& seq2, t_vec_grp& groups, t_vec_grp_it& grp_ite) {
	t_vec_it				pos;
	t_vec_grp_it			grp_it = groups.begin();
	t_vec::reverse_iterator	it2 = seq2.rbegin();
	t_vec::reverse_iterator	ite2 = seq2.rend();
	size_t					dist;

//	// std::clog << LABEL_BS_ << __LINE__ << "\t"; printGroups(groups);
//	std::clog << LABEL_BS_ << __LINE__ << "\tseq : "; printList(seq);
//	std::clog << LABEL_BS_ << __LINE__ << "\tseq2: "; printList(seq2);
	pos = sortInsertBSGetPos(grp_it, seq2.front(), std::distance(grp_it, grp_ite));
//	// std::clog << LABEL_BS_ << __LINE__ << "\tpos: " << *pos << std::endl;
//	// std::clog << LABEL_BS_ << __LINE__ << "\tgrp_ite: " << *grp_ite->first << std::endl;
	while (it2 != ite2) {
//		std::clog << LABEL_BS_ << __LINE__ << "\tdist pos: " << std::distance(seq.begin(), pos) << "\tit2: " << std::distance(it2, ite2) << std::endl;
		if (pos == seq.end())
			seq.push_back(*it2);
		else
			pos = seq.insert(pos, *it2);
//		std::clog << LABEL_BS_ << __LINE__ << "\tdist pos: " << std::distance(seq.begin(), pos) << "\tit2: " << std::distance(it2, ite2) << std::endl;
		it2++;
	}
	dist = std::distance(grp_it, grp_ite);
//	// std::clog << LABEL_BS_ << __LINE__ << "\t"; printGroups(groups);
//	std::clog << LABEL_BS_ << __LINE__ << "\tdist: " << std::distance(grp_it, grp_ite) << "\tgrp_it: " << *grp_it->first << "\tgrp_ite: " << *grp_ite->first << std::endl;
	grp_it = groups.insert(grp_it, std::make_pair(pos, seq2.size()));
	grp_ite = grp_it + dist + 1;
	this->n_sorted_++;
//	// std::clog << LABEL_BS_ << __LINE__ << "\t"; printGroups(groups);
//	// std::clog << LABEL_BS_ << __LINE__ << "\tdist: " << std::distance(grp_it, grp_ite) << "\tgrp_it: " << *grp_it->first << "\tgrp_ite: " << *grp_ite->first << std::endl;
	while (grp_it != grp_ite) {
//		// std::clog << LABEL_BS_ << __LINE__ << "\t"; printGroups(groups);
//		std::clog << LABEL_BS_ << __LINE__ << "\tdist: " << std::distance(grp_it, grp_ite) << "\tgrp_it: " << *grp_it->first << "\tgrp_ite: " << *grp_ite->first << std::endl;
		grp_ite->first += seq2.size();
		grp_ite--;
	}
	// std::advance(grp_ite, dist + 1);
}

t_vec_it	PmergeMe::sortInsertBSGetPos(t_vec_grp_it& grp_it, int val_insert, size_t n_sought) {
	size_t			delta = 0;
	t_vec_grp_it	grp_itb = grp_it;

//	std::clog << LABEL_BSP << __LINE__ << "\tn_sought: " << n_sought << "\tdelta: " << delta << "\tgrp_it->first: " << *grp_it->first << std::endl;
	if (val_insert <= *grp_it->first)
		return (grp_it->first);
	grp_it += n_sought;
//	std::clog << LABEL_BSP << __LINE__ << "\tdist: " << std::distance(grp_itb, grp_it) << "\tn_sorted_: " << this->n_sorted_ << std::endl;
//	std::clog << LABEL_BSP << __LINE__ << "\tval_insert: " << val_insert << "\tgrp_it: " << *grp_it->first << std::endl;
	// if (static_cast<size_t>(std::distance(grp_itb, grp_it)) > n_sought || val_insert > *grp_it->first) {
	if (val_insert > *grp_it->first) {
		t_vec_it	it = grp_it->first + grp_it->second;
		return (it);
	}
	grp_it = grp_itb;

	delta = calcMid(n_sought);
	grp_it += n_sought - delta;
//	std::clog << LABEL_BSP << __LINE__ << "\tn_sought: " << n_sought << "\tdelta: " << delta << std::endl;
	if (val_insert < *grp_it->first)
		delta = calcMid(n_sought - delta - 1);
	else {
		// std::advance(grp_it, delta);
		// if (val_insert > *grp_it->first)
		// 	return (grp_it->first);
		delta /= 2;
	}
	while (delta > 0) {
//		std::clog << LABEL_BSP << __LINE__ << "\tn_sought: " << n_sought << "\tdelta: " << delta << "\tdist: " << std::distance(grp_itb, grp_it) << "\tgrp_it->first: " << *grp_it->first << std::endl;
		if (*grp_it->first == val_insert)
			return (grp_it->first);
		if (*grp_it->first < val_insert)
			grp_it += delta;
		else if (delta > static_cast<size_t>(std::distance(grp_itb, grp_it)))
			grp_it = grp_itb;
		else
			grp_it -= delta;
//		std::clog << LABEL_BSP << __LINE__ << "\tn_sought: " << n_sought << "\tdelta: " << delta << "\tdist: " << std::distance(grp_itb, grp_it) << "\tgrp_it->first: " << *grp_it->first << std::endl;
		delta /= 2;
	}
	if (*grp_it->first < val_insert)
		grp_it++;
	return (grp_it->first);
}

void	PmergeMe::swapGroup(t_vec& seq, size_t left, size_t mid) {
//	std::clog << LABEL_SG_ << __LINE__ << "\tleft: " << left << "\tmid: " << mid << std::endl;
//	std::clog << LABEL_SG_ << __LINE__ << "\t"; printList(seq);
	t_vec_it	it1 = seq.begin() + left;
	t_vec_it	it2 = seq.begin() + mid;
	for (size_t i = left; i < mid; i++)
		std::iter_swap(it1++, it2++);
}

void	PmergeMe::swapGroup(t_vec& seq, size_t left, size_t mid, size_t size) {
//	std::clog << LABEL_SG_ << __LINE__ << "\tleft: " << left << "\tmid: " << mid  << "\tsize: " << size << std::endl;
//	std::clog << LABEL_SG_ << __LINE__ << "\t "; printList(seq);
	t_vec_it	it1 = seq.begin() + left;
	t_vec_it	it2 = seq.begin() + mid;
	for (size_t i = 0; i < size; i++)
		std::iter_swap(it1++, it2++);
}

t_vec	PmergeMe::cut(t_vec& seq, t_vec_it& it, size_t size) {
	t_vec_it	it2 = it;
	t_vec		seq2;
	size_t		i = 0;

	while (i++ < size) {
		seq2.push_back(*it2);
		it2++;
	}
//	std::clog << LABEL_C__ << __LINE__ << "\tseq : "; printList(seq);
//	std::clog << LABEL_C__ << __LINE__ << "\tseq2: "; printList(seq2);
	seq.erase(it, it2);
//	std::clog << LABEL_C__ << __LINE__ << "\tseq : "; printList(seq);
//	std::clog << LABEL_C__ << __LINE__ << "\tseq2: "; printList(seq2);
	return (seq2);
}
