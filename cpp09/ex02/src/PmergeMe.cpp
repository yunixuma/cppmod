/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/31 06:40:59 by Yoshihiro K      ###   ########.fr       */
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
	size_t							i = 0;
	while (it != ite)
		vec[i++] = *(it++);
	return (vec);
}

void	PmergeMe::sortSub(std::list<int>& lst, size_t left, size_t right)
{
	std::clog << "(" << left << ", " << right << ")" << std::endl;
	// if (left + 1 >= right || lst.size() <= right)
	if (left + 1 >= right)
		return; // Returns recursively
	// Same as (l+r)/2, but avoids
	// overflow for large l and h
	size_t	mid = left + (right - left + 1) / 2;
	std::clog << "(" << left << ", " << mid << ", " << right << ")" << std::endl;
	// Sort first and second halves
	sortSub(lst, left, mid - 1);
	sortSub(lst, mid, mid + (mid - left) - 1);
	std::list<int>::iterator	it1 = lst.begin(); advance(it1, left);
	std::list<int>::iterator	it2 = lst.begin(); std::advance(it2, mid + 1);
	if (*it1 < *it2) {
		for (size_t i = 0; i < mid - left + 1; i++)
			std::iter_swap(it1++, it2++);
	}

//	sortMerge(vec, left, mid, right);
}

void	PmergeMe::sort(std::list<int>& lst) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<PmergeMe> sort called" << std::endl;
	std::clog << &lst << "\t<" << typeid(lst).name() \
		<< ">\033[m" << std::endl;
	if (sortCheck(lst))
		return ;
	size_t	mid = (lst.size() - 1) / 2;
	std::list<int>::iterator	it1 = lst.begin();
	std::list<int>::iterator	it2 = lst.begin(); std::advance(it2, mid + 1);
	this->sub_lst_.push_back(std::make_pair(mid, *it1));
	this->sub_lst_.push_back(std::make_pair(mid, *it2));
	sortSub(lst, 0, mid - 1);
	sortSub(lst, mid, mid * 2 - 1);
	if (*it1 > *it2) {
		for (size_t i = 0; i < mid + 1; i++)
			std::iter_swap(it1++, it2++);
	}
	printSubList(this->sub_lst_);
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

void PmergeMe::sortMerge(std::vector<int>& vec, size_t l, size_t m, size_t r)
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

void	PmergeMe::sortSub(std::vector<int>& vec, size_t left, size_t right)
{
	if (left + 1 >= right)
		return; // Returns recursively
	// Same as (l+r)/2, but avoids
	// overflow for large l and h
	size_t mid = left + (right - left - 1) / 2;

	// Sort first and second halves
	sortSub(vec, left, mid);
	sortSub(vec, mid + 1, mid + 1 - left + mid);
	if (vec[left] < vec[mid + 1]) {
		std::vector<int>::iterator	it1 = vec.begin() + left;
		std::vector<int>::iterator	it2 = vec.begin() + mid + 1;
		for (size_t i = 0; i < mid - left + 1; i++) {
			std::iter_swap(it1++, it2++);
		}
	}
		
//	sortMerge(vec, left, mid, right);
}

void	PmergeMe::sort(std::vector<int>& vec) {
	std::clog << "\033[36;2;3m[" << this \
		<< "]<PmergeMe> sort called" << std::endl;
	std::clog << &vec << "\t<" << typeid(vec).name() \
		<< ">\033[m" << std::endl;
// https://www.geeksforgeeks.org/c-program-for-merge-sort/
	if (sortCheck(vec))
		return ;
	size_t	mid = (vec.size() - 1) / 2;
	this->sub_vec_.push_back(std::make_pair(mid, vec[0]));
	this->sub_vec_.push_back(std::make_pair(mid, vec[mid + 1]));
	sortSub(vec, 0, mid);
	sortSub(vec, mid + 1, mid * 2 + 1);
	if (vec[0] > vec[mid + 1]) {
		std::vector<int>::iterator	it1 = vec.begin();
		std::vector<int>::iterator	it2 = vec.begin() + mid + 1;
		for (size_t i = 0; i < mid + 1; i++)
			std::iter_swap(it1++, it2++);
	}
	printSubList(this->sub_vec_);

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
