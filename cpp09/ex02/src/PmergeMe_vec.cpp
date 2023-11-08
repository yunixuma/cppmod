/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe_vec.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/11/09 06:49:30 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	PmergeMe::sortMergeSub(t_vec& vec, size_t left, size_t right)
{
	if (left >= right)
		return;
	size_t	mid = left + (right - left + 1) / 2;
//	std::clog << "!" << __LINE__ << "\t"; printList(vec);
//	std::clog << "!" << __LINE__ << "\t(" << left << ", " << mid << ", " << right << ")" << std::endl; printList(vec);
	sortMergeSub(vec, left, mid - 1);
//	std::clog << "!" << __LINE__ << "\t(" << left << ", " << mid << ", " << right << ")" << std::endl; printList(vec);
	sortMergeSub(vec, mid, mid * 2 - left - 1);


	if (vec[left] < vec[mid])
		swapGroup(vec, left, mid);


}

void	PmergeMe::sortMerge(t_vec& vec, size_t left, size_t right)
{
	if (left >= right)
		return;
	size_t	mid = left + calcMid((right - left + 1) / 2);

//	std::clog << "#" << __LINE__ << "\t(" << left << ", " << mid << ", " << right << ")" << std::endl;
	sortMergeSub(vec, left, mid - 1);
//	std::clog << "#" << __LINE__ << "\t(" << left << ", " << mid << ", " << right << ")" << std::endl;
	sortMergeSub(vec, mid, mid * 2 - left - 1);


	// if ((left != 0 || right != vec.size()) && vec[left] < vec[mid])
	if ((left == 0 && right == vec.size() - 1 && vec[left] > vec[mid]) || ((left != 0 || right != vec.size()) && vec[left] < vec[mid]))
		swapGroup(vec, left, mid);




//	std::clog << "#" << __LINE__ << "\t"; printList(vec);
	if (mid * 2 - left < right)
		sortMerge(vec, mid * 2 - left, right);
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
//	std::clog << "$" << __LINE__ << "\ti: " << i << "\tsub_size" << sub_size << "\tsize" << size << std::endl;
//	std::clog << "$" << __LINE__ << "\t"; printGroups(groups);
	while (i < size) {
		sub_size = calcMid(size - i);
//		std::clog << "$" << __LINE__ << "\ti: " << i << "\tsub_size" << sub_size << std::endl;
		groups.push_back(std::make_pair(it, sub_size));
		i += sub_size;
		std::advance(it, sub_size);
//		std::clog << "$" << __LINE__ << "\t"; printGroups(groups);
	}
	return (groups);
}

void	PmergeMe::sortTriplet(t_vec& vec, t_vec_grp& groups) {
	size_t	size = groups[0].second;

	if (groups.size() < 3 || groups[2].second != size)
		return ;






//	std::clog << "^" << __LINE__ << "\tgrp0: " << *groups[0].first << "\tgrp1: " << *groups[1].first << "\tgrp2: " << *groups[2].first << std::endl;
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
//		size_t	i = 0; // __LINE__
		while (grp_it != grp_ite) {
//			std::clog << "%" << __LINE__ << "\tsize: " << size << "\ti: " << i++ << std::endl;
//			std::clog << "%" << __LINE__ << "\tn_sorted: " << this->n_sorted_ << "\tit->second: " << grp_it->second << "\t" << "it->first: " << *(grp_it->first) << std::endl;
//			std::clog << "%" << __LINE__ << "\t"; printGroups(groups);
			if (grp_it->second == size) {
				vec2 = sortInsertCut(vec, groups, grp_it);
				sortInsertBS(vec, vec2, groups, grp_it);
			}
			grp_it++;
			grp_ite = groups.end();
		}
		size >>= 1;
//		std::clog << "%" << __LINE__ << "\t"; printList(vec);
//		std::clog << "%" << __LINE__ << "\t"; printGroups(groups);
	}
	grp_it = groups.begin();
	std::advance(grp_it, this->n_sorted_);
	while (grp_it != grp_ite) {
//		// std::clog << "%" << __LINE__ << "\tn_sorted: " << this->n_sorted_ << "\tgrp_it: " << *(grp_it->first) << "\tdist: " << std::distance(grp_it, grp_ite) << std::endl;
		vec2 = sortInsertCut(vec, groups, grp_it);
//		std::clog << "%" << __LINE__ << "\tn_sorted: " << this->n_sorted_ << "\tgrp_it: " << *(grp_it->first) << "\tdist: " << std::distance(grp_it, grp_ite) << std::endl;
		grp_it++;
		sortInsertBS(vec, vec2, groups, grp_it);
		grp_it++;
	}
}

t_vec	PmergeMe::sortInsertCut(t_vec& vec, t_vec_grp& groups, t_vec_grp_it& grp_it) {
	t_vec	vec2;
	size_t	size = grp_it->second / 2;
	size_t	dist;
//	// std::clog << "+" << __LINE__ << "\t"; printGroups(groups);
	if (size == 0) {
		dist = std::distance(groups.begin(), grp_it);
//		std::clog << "+" << __LINE__ << "\tdist: " << dist << std::endl;
		vec2.push_back(*(grp_it->first));
		vec.erase(grp_it->first);
		grp_it = groups.erase(grp_it);
		grp_it = groups.begin(); std::advance(grp_it, dist - 1);
//		std::clog << "+" << __LINE__ << "\t"; printGroups(groups);
//		std::clog << "+" << __LINE__ << "\tgrp_it: " << *grp_it->first << std::endl;
		return (vec2);
	}
	t_vec_it	it = grp_it->first;
	grp_it->second = size;
	std::advance(it, size);
//	std::clog << "+" << __LINE__ << "\t"; printGroups(groups);
//	std::clog << "+" << __LINE__ << "\tgrp_it: " << *grp_it->first << std::endl;
	vec2 = cut(vec, it, size);
//	std::clog << "+" << __LINE__ << "\t"; printGroups(groups);
//	std::clog << "+" << __LINE__ << "\tgrp_it: " << *grp_it->first << std::endl;
	return (vec2);
}

void	PmergeMe::swapGroup(t_vec& vec, size_t left, size_t mid) {
//	std::clog << "/" << __LINE__ << "\tleft: " << left << "\tmid: " << mid << std::endl;
//	std::clog << "/" << __LINE__ << "\t "; printList(vec);
	t_vec_it	it1 = vec.begin() + left;
	t_vec_it	it2 = vec.begin() + mid;
	for (size_t i = left; i < mid; i++)
		std::iter_swap(it1++, it2++);
}

void	PmergeMe::swapGroup(t_vec& vec, size_t left, size_t mid, size_t size) {
//	std::clog << "/" << __LINE__ << "\tleft: " << left << "\tmid: " << mid  << "\tsize: " << size << std::endl;
//	std::clog << "/" << __LINE__ << "\t "; printList(vec);
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
//	std::clog << "\\" << __LINE__ << "\tseq : "; printList(vec);
//	std::clog << "\\" << __LINE__ << "\tseq2: "; printList(vec2);
	vec.erase(it, it2);
//	std::clog << "\\" << __LINE__ << "\tseq : "; printList(vec);
//	std::clog << "\\" << __LINE__ << "\tseq2: "; printList(vec2);
	return (vec2);
}

void	PmergeMe::sortInsertBS(t_vec& vec, t_vec& vec2, t_vec_grp& groups, t_vec_grp_it& grp_ite) {
	t_vec_it				pos;
	t_vec_grp_it			grp_it = groups.begin();
	t_vec::reverse_iterator	it2 = vec2.rbegin();
	t_vec::reverse_iterator	ite2 = vec2.rend();
	size_t					dist;

//	std::clog << "@" << __LINE__ << "\t"; printGroups(groups);
//	std::clog << "@" << __LINE__ << "\tseq : "; printList(vec);
//	std::clog << "@" << __LINE__ << "\tseq2: "; printList(vec2);
	pos = sortInsertBSGetPos(grp_it, vec2.front(), std::distance(groups.begin(), grp_ite));
	std::clog << "@" << __LINE__ << "\tpos: " << *pos << std::endl;
	// std::clog << "@" << __LINE__ << "\tgrp_ite: " << *grp_ite->first << std::endl;
	while (it2 != ite2) {
		std::clog << "@" << __LINE__ << "\tite2: " << *ite2 << "\tdist: " << std::distance(pos, vec.end()) << std::endl;
		if (pos == vec.end())
			vec.push_back(*it2);
		else
			pos = vec.insert(pos, *it2);
		std::clog << "@" << __LINE__ << "\tit2: " << *it2 << "\tpos: " << *pos << std::endl;
		it2++;
	}
	dist = std::distance(grp_it, grp_ite);
//	std::clog << "@" << __LINE__ << "\t"; printGroups(groups);
//	std::clog << "@" << __LINE__ << "\tgrp_it: " << *grp_it->first << "\tgrp_ite: " << *grp_ite->first << "\tdist: " << dist << std::endl;
	grp_it = groups.insert(grp_it, std::make_pair(pos, vec2.size()));
	grp_ite = grp_it; std::advance(grp_ite, dist + 1);
	this->n_sorted_++;
//	std::clog << "@" << __LINE__ << "\t"; printGroups(groups);
//	// std::clog << "@" << __LINE__ << "\tdist: " << std::distance(grp_it, grp_ite) << "\tgrp_it: " << *grp_it->first << "\tgrp_ite: " << *grp_ite->first << std::endl;
	while (grp_it != grp_ite) {
//		// std::clog << "@" << __LINE__ << "\t"; printGroups(groups);
//		// std::clog << "@" << __LINE__ << "\tdist: " << std::distance(grp_it, grp_ite) << "\tgrp_it: " << *grp_it->first << "\tgrp_ite: " << *grp_ite->first << std::endl;
		std::advance(grp_ite->first, vec2.size());
		grp_ite--;
	}
}

t_vec_it	PmergeMe::sortInsertBSGetPos(t_vec_grp_it& grp_it, int val_insert, size_t n_sought) {
	size_t			delta = 0;
	t_vec_grp_it	grp_itb = grp_it;

//	std::clog << "&" << __LINE__ << "\tn_sought: " << n_sought << "\tdelta: " << delta << "\tgrp_it->first: " << *grp_it->first << std::endl;
	if (val_insert <= *grp_it->first)
		return (grp_it->first);
	std::advance(grp_it, n_sought);
	std::clog << "&" << __LINE__ << "\tdist: " << std::distance(grp_itb, grp_it) << std::endl;
	if (val_insert >= *grp_it->first) {
		grp_it++;
		return (grp_it->first);
	}
	grp_it = grp_itb;

	delta = calcMid(n_sought);
	std::advance(grp_it, n_sought - delta);
//	std::clog << "&" << __LINE__ << "\tn_sought: " << n_sought << "\tdelta: " << delta << std::endl;
	if (val_insert < *grp_it->first)
		delta = calcMid(n_sought - delta - 1);
	else {
		// std::advance(grp_it, delta);
		// if (val_insert > *grp_it->first)
		// 	return (grp_it->first);
		delta /= 2;
	}
	while (delta > 0) {
//		std::clog << "&" << __LINE__ << "\tn_sought: " << n_sought << "\tdelta: " << delta << "\tdist: " << std::distance(grp_itb, grp_it) << "\tgrp_it->first: " << *grp_it->first << std::endl;
		if (*grp_it->first == val_insert)
			return (grp_it->first);
		if (*grp_it->first < val_insert)
			std::advance(grp_it, delta);
		else if (delta > static_cast<size_t>(std::distance(grp_itb, grp_it)))
			grp_it = grp_itb;
		else
			std::advance(grp_it, static_cast<int>(-delta));
//		std::clog << "&" << __LINE__ << "\tn_sought: " << n_sought << "\tdelta: " << delta << "\tdist: " << std::distance(grp_itb, grp_it) << "\tgrp_it->first: " << *grp_it->first << std::endl;
		delta /= 2;
	}
	if (*grp_it->first < val_insert)
		grp_it++;
	return (grp_it->first);
}

void	PmergeMe::sort(t_vec& vec) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<PmergeMe> sort called" << std::endl;
	std::clog << &vec << "\t<" << typeid(vec).name() \
		<< ">\033[m" << std::endl;
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
}
