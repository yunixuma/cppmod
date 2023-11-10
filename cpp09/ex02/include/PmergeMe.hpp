/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/11/10 20:12:34 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <list>
# include <vector>
# include <ctime>
// # include <stack>
# include <iterator>
# include <iostream>
# include <sstream>
# include <typeinfo>
# include <exception>
# include <climits>

# define SIZE_PRINT		3200
# define BITS_BYTE		8
# define ORDER_OF_LIST	11

typedef std::list<int>		t_lst;
typedef std::vector<int>	t_vec;
typedef t_lst::iterator		t_lst_it;
typedef t_vec::iterator		t_vec_it;
typedef std::list<std::pair<t_lst_it, size_t> >		t_lst_grp;
typedef std::vector<std::pair<t_vec_it, size_t> >	t_vec_grp;
typedef t_lst_grp::iterator	t_lst_grp_it;
typedef t_vec_grp::iterator	t_vec_grp_it;

class PmergeMe
{
private:
	// float	time_;
	// std::list<std::pair<size_t, int> >		grp_lst_;
	// std::vector<std::pair<size_t, int> >	grp_vec_;
	size_t		n_sorted_;
	void		move(t_vec& vec, t_vec_it& pos, t_vec_it& second, t_vec_it& last);
	void		sort(t_lst& lst);
	void		sort(t_vec& vec);
	void		sortMerge(t_lst& lst, size_t left, size_t right);
	void		sortMergeSub(t_lst& lst, size_t left, size_t right);
	void		sortMerge(t_vec& vec, size_t left, size_t right);
	void 		sortMergeSub(t_vec& vec, size_t left, size_t right);
	t_lst_grp	initGroup(t_lst& lst);
	t_vec_grp	initGroup(t_vec& vec);
	void		sortTriplet(t_lst& lst, t_lst_grp& groups);
	void		sortTriplet(t_vec& vec, t_vec_grp& groups);
	void		sortInsert(t_lst& lst, t_lst_grp& groups);
	t_lst		sortInsertCut(t_lst& lst, t_lst_grp& grp, t_lst_grp_it& grp_it);
	void		sortInsertBS(t_lst& lst, t_lst& lst2, t_lst_grp& groups, t_lst_grp_it& grp_ite);
	t_lst_it	sortInsertBSGetPos(t_lst_grp_it& grp_it, int val_insert, size_t n_sought);
	void		sortInsert(t_vec& vec, t_vec_grp& groups);
	t_vec		sortInsertCut(t_vec& vec, t_vec_grp& grp, t_vec_grp_it& grp_it);
	void		sortInsertBS(t_vec& vec, t_vec& vec2, t_vec_grp& groups, t_vec_grp_it& grp_ite);
	t_vec_it	sortInsertBSGetPos(t_vec_grp_it& grp_it, int val_insert, size_t n_sought);
	void		swapGroup(t_lst& lst, size_t left, size_t mid);
	void		swapGroup(t_lst& lst, size_t left, size_t mid, size_t size);
	t_lst		cut(t_lst& lst, t_lst_it& it, size_t size);
	void		swapGroup(t_vec& vec, size_t left, size_t mid);
	void		swapGroup(t_vec& vec, size_t left, size_t mid, size_t size);
	t_vec		cut(t_vec& vec, t_vec_it& it, size_t size);
	size_t		calcMid(size_t half) const;
public:
	PmergeMe(void);
	~PmergeMe(void);
	PmergeMe(const PmergeMe& src);
	PmergeMe&	operator=(const PmergeMe& rhs);
	t_lst		args2List(size_t argc, char *argv[]);
	t_vec		list2Vector(const t_lst& lst);
	template <typename T>
	clock_t		measureTime(T& container) {
		std::clog << "\033[36;2;3m[" << this \
			<< "]<PmergeMe> mesureTime called" << std::endl;
		std::clog << &container << "\t<" << typeid(container).name() \
			<< ">\033[m" << std::endl;
		clock_t	start = clock();
		sort(container);
		clock_t	end = clock();
		if (!sortCheck(container))
			std::cout << "\033[31m" << typeid(container).name() << std::endl << "sorting was failed\033[m" << std::endl;
		return (difftime(end, start));
	};
	template <typename T>
	bool		sortCheck(T& container) {
		std::clog << "\033[36;2;3m[" << this \
			<< "]<PmergeMe> sortCheck called" << std::endl;
		std::clog << &container << "\t<" << typeid(container).name() \
			<< ">\033[m" << std::endl;
		if (container.size() < 2)
			return (true);
		typename T::iterator	it = container.begin();
		typename T::iterator	ite = container.end();
		int						tmp = *it;
		while (it != ite) {
			if (tmp > *it) {
				std::cout << "\033[31m" << *it \
					<< "[" << container.size() - std::distance(it, ite) \
					<< "/" << container.size() << "]\033[m" << std::endl;
				return (false);
			}
			tmp = *it;
			it++;
		}
		return (true);
	};
	template <typename T>
	void		printList(T& lst) {
		typename T::iterator	it = lst.begin();
		size_t					size = lst.size();
		size_t					i = 1;
		std::clog << size << "( ";
		if (size > SIZE_PRINT)
			size = SIZE_PRINT;
		while (i++ < size) {
			std::clog << *it << " ";
			it++;
		}
		if (size < lst.size())
			std::clog << "[...]";
		else if (size)
			std::clog << *it;
		std::clog << " )" << std::endl;
	};
	template <typename T>
	void		printGroups(T& groups) {
		typename T::iterator	it = groups.begin();
		size_t					size = groups.size();
		size_t					i = 1;
		std::clog << size << "{ ";
		if (size > SIZE_PRINT)
			size = SIZE_PRINT;
		while (i++ < size) {
			std::clog << (*it).second << "(" << *((*it).first) << ") ";
			// std::clog << (*it).second << "(" << *((*it).first) << "[" << &*((*it).first) << "]) ";
			it++;
		}
		if (size < groups.size())
			std::clog << "[...]";
		else if (size)
			std::clog << (*it).second << "(" << *((*it).first) << ")";
		std::clog << " }" << std::endl;
	};
};

#endif
