/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/11/02 13:42:42 by ykosaka          ###   ########.fr       */
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
	if (this != &rhs) {
		this->sub_lst_ = rhs.sub_lst_;
		this->sub_vec_ = rhs.sub_vec_;
	}
	return (*this);
}

PmergeMe::~PmergeMe(void) {
	std::clog << "\033[31;2;3m[" << this \
		<< "]<PmergeMe> Destructor called\033[m" << std::endl;
}

std::list<int>	PmergeMe::split2List(const std::string& str) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<PmergeMe> split2List called" << std::endl;
	std::clog << str << "\t<" << typeid(str).name() \
		<< ">\033[m" << std::endl;
	std::list<int>		lst;
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

std::vector<int>	PmergeMe::list2Vector(const std::list<int>& lst) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<PmergeMe> split2List called" << std::endl;
	std::clog << &lst << "\t<" << typeid(lst).name() \
		<< ">\033[m" << std::endl;
	std::vector<int>	vec(lst.size());
	std::list<int>::const_iterator	it = lst.begin();
	std::list<int>::const_iterator	ite = lst.end();
	unsigned int					i = 0;
	while (it != ite)
		vec[i++] = *(it++);
	return (vec);
}

unsigned int	PmergeMe::calcMid(unsigned int half) const {
	unsigned int	mid = 1 << ORDER_OF_LIST;
	if (half > mid)
		mid = 1 << (sizeof(unsigned) * (BITS_BYTE >> 1));
	unsigned int	pivot = mid >> 1;
	while (pivot) {
		if (mid < half)
			mid += pivot;
		else
			mid -= pivot;
		pivot >>= 1;
	}
	return (mid + 1);
}

void	PmergeMe::sortMergeSub(std::list<int>& lst, unsigned int left, unsigned int right)
{
	// std::clog << "88 (" << left << ", " << right << ")" << std::endl;
	// if (left + 1 >= right || lst.size() <= right)
	if (left >= right)
		return; // Returns recursively
	// Same as (l+r)/2, but avoids
	// overflow for large l and h
	unsigned int	mid = left + (right - left + 1) / 2;
	printList(lst);
	std::clog << "111 (" << left << ", " << mid << ", " << right << ")" << std::endl;
	// Sort first and second halves
	sortMergeSub(lst, left, mid - 1);
	std::clog << "114 (" << left << ", " << mid << ", " << right << ")" << std::endl;
	sortMergeSub(lst, mid, mid + (mid - left) - 1);
	std::list<int>::iterator	it1 = lst.begin(); advance(it1, left);
	std::list<int>::iterator	it2 = lst.begin(); std::advance(it2, mid);
	if (*it1 < *it2) {
		for (unsigned int i = left; i < mid; i++)
			std::iter_swap(it1++, it2++);
	}

//	sortMerge(vec, left, mid, right);
}

void	PmergeMe::sortMerge(std::list<int>& lst, unsigned int left, unsigned int right)
{
	// std::clog << "88 (" << left << ", " << right << ")" << std::endl;
	// if (left + 1 >= right || lst.size() <= right)
	if (left >= right)
		return; // Returns recursively
	// Same as (l+r)/2, but avoids
	// overflow for large l and h
	unsigned int	mid = left + calcMid((right - left + 1) / 2);
	// unsigned int	mid = (lst.size() - 1) / 2;

	std::list<int>::iterator	it1 = lst.begin();
	std::list<int>::iterator	it2 = lst.begin(); std::advance(it2, mid);
	std::clog << "139 (" << left << ", " << mid << ", " << right << ")" << std::endl;
	sortMergeSub(lst, left, mid - 1);
	std::clog << "141 (" << left << ", " << mid << ", " << right << ")" << std::endl;
	sortMergeSub(lst, mid, mid + (mid - left) - 1);
	if (*it1 > *it2) {
		for (unsigned int i = left; i < mid; i++)
			std::iter_swap(it1++, it2++);
	}
	sortMerge(lst, mid * 2, right);
	this->sub_lst_.push_back(std::make_pair(mid, *it1));
	this->sub_lst_.push_back(std::make_pair(mid, *it2));
	std::advance(it2, mid);
	this->sub_lst_.push_back(std::make_pair(mid, *it2));
	printSubList(this->sub_lst_);

//	sortMerge(vec, left, mid, right);
}

void	PmergeMe::sort(std::list<int>& lst) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<PmergeMe> sort called" << std::endl;
	std::clog << &lst << "\t<" << typeid(lst).name() \
		<< ">\033[m" << std::endl;
	if (sortCheck(lst))
		return ;
	sortMerge(lst, 0, lst.size() - 1);
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



/*
void	PmergeMe::move(std::vector<int>& vec, \
	t_vec_it& pos, t_vec_it& first, t_vec_it& last) {

}
*/
/*
void	PmergeMe::move(std::vector<int>& vec, \
	t_vec_it& pos, t_vec_it& first, t_vec_it& last) {
	std::vector<int>	tmp(first, ++last);
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

void PmergeMe::sortMerge(std::vector<int>& vec, unsigned int l, unsigned int m, unsigned int r)
{
	unsigned int	i, j, k;
	unsigned int	n1 = m - l + 1;
	unsigned int	n2 = r - m;

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

void	PmergeMe::sortMergeSub(std::vector<int>& vec, unsigned int left, unsigned int right)
{
	if (left >= right)
		return; // Returns recursively
	// Same as (l+r)/2, but avoids
	// overflow for large l and h
	unsigned int	mid = left + (right - left + 1) / 2;

	// Sort first and second halves
	std::clog << "290 (" << left << ", " << mid << ", " << right << ")" << std::endl;
	sortMergeSub(vec, left, mid - 1);
	std::clog << "292 (" << left << ", " << mid << ", " << right << ")" << std::endl;
	sortMergeSub(vec, mid, mid + (mid - left) - 1);
	if (vec[left] < vec[mid]) {
		std::vector<int>::iterator	it1 = vec.begin() + left;
		std::vector<int>::iterator	it2 = vec.begin() + mid;
		for (unsigned int i = left; i < mid; i++) {
			std::iter_swap(it1++, it2++);
		}
	}
	printSubList(this->sub_vec_);
}

void	PmergeMe::sortMerge(std::vector<int>& vec, unsigned int left, unsigned int right)
{
	if (left >= right)
		return; // Returns recursively
	// Same as (l+r)/2, but avoids
	// overflow for large l and h
	unsigned int	mid = left + calcMid((right - left + 1) / 2);

	// Sort first and second halves
	std::clog << "317 (" << left << ", " << mid << ", " << right << ")" << std::endl;
	sortMergeSub(vec, left, mid - 1);
	std::clog << "319 (" << left << ", " << mid << ", " << right << ")" << std::endl;
	sortMergeSub(vec, mid, mid + (mid - left) - 1);
	if (vec[left] < vec[mid]) {
		std::vector<int>::iterator	it1 = vec.begin() + left;
		std::vector<int>::iterator	it2 = vec.begin() + mid;
		for (unsigned int i = left; i < mid; i++) {
			std::iter_swap(it1++, it2++);
		}
	}
	sortMerge(vec, mid * 2, right);
	this->sub_vec_.push_back(std::make_pair(mid, vec[left]));
	this->sub_vec_.push_back(std::make_pair(mid, vec[mid]));
	if (mid * 2 < vec.size()) {
		sortMerge(vec, mid * 2, right);
		this->sub_vec_.push_back(std::make_pair(mid, vec[mid + mid - left]));
	}
	printSubList(this->sub_vec_);
}

void	PmergeMe::sort(std::vector<int>& vec) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<PmergeMe> sort called" << std::endl;
	std::clog << &vec << "\t<" << typeid(vec).name() \
		<< ">\033[m" << std::endl;
// https://www.geeksforgeeks.org/c-program-for-merge-sort/
	if (sortCheck(vec))
		return ;
	sortMerge(vec, 0, vec.size() - 1);

// https://cpprefjp.github.io/reference/vector/vector/insert.html
// https://cpprefjp.github.io/reference/vector/vector/erase.html
/*	t_vec_it	it1 = vec.begin();
	t_vec_it	it2 = vec.begin();
	t_vec_it	it3 = vec.end();
	std::vector<int>	vec2;
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

// When an exception thrown
// const char*	PmergeMe::SyntaxError::what(void) const throw() {
/*	std::clog << "\033[35;3m[" << this \
		<< "]<PmergeMe::SyntaxError> what() called\033[m" \
		<< std::endl;*/
// 	return ("Error: Syntax error");
// }
