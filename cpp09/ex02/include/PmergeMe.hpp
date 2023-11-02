/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/11/02 21:38:00 by ykosaka          ###   ########.fr       */
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

# define SIZE_PRINT		16
# define BITS_BYTE		8
# define ORDER_OF_LIST	11

typedef std::list<int>::iterator	t_lst_it;
typedef std::vector<int>::iterator	t_vec_it;

class PmergeMe
{
private:
	// float	time_;
	std::list<std::pair<unsigned int, int> >		sub_lst_;
	std::vector<std::pair<unsigned int, int> >	sub_vec_;
	void				move(std::vector<int>& vec, \
		t_vec_it& pos, t_vec_it& first, t_vec_it& last);
	void				sort(std::list<int>& lst);
	void				sort(std::vector<int>& vec);
	void				sortMerge(std::list<int>& vec, \
		unsigned int left, unsigned int right);
	void				sortMergeSub(std::list<int>& vec, \
		unsigned int left, unsigned int right);
	void				sortMerge(std::vector<int>& vec, \
		unsigned int left, unsigned int right);
	void 				sortMergeSub(std::vector<int>& vec, \
		unsigned int left, unsigned int right);
	unsigned int		calcMid(unsigned int half) const;
public:
	PmergeMe(void);
	~PmergeMe(void);
	PmergeMe(const PmergeMe& src);
	PmergeMe&			operator=(const PmergeMe& rhs);
	std::list<int>		args2List(size_t argc, char *argv[]);
	std::vector<int>	list2Vector(const std::list<int>& lst);
	template <typename T>
	clock_t				measureTime(T& container) {
		std::clog << "\033[36;2;3m[" << this \
			<< "]<PmergeMe> mesureTime called" << std::endl;
		std::clog << &container << "\t<" << typeid(container).name() \
			<< ">\033[m" << std::endl;
		clock_t	start = clock();
		sort(container);
		clock_t	end = clock();
		return (difftime(end, start));
	};
	template <typename T>
	bool				sortCheck(T& container) {
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
			if (tmp > *it)
				return (false);
			tmp = *it;
			it++;
		}
		return (true);
	};
	template <typename T>
	void				printList(T& lst) {
		typename T::iterator	it = lst.begin();
		unsigned int			size = lst.size();
		unsigned int			i = 1;
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
	void				printSubList(T& sub_lst) {
		typename T::iterator	it = sub_lst.begin();
		unsigned int			size = sub_lst.size();
		unsigned int			i = 1;
		std::clog << size << "{ ";
		if (size > SIZE_PRINT)
			size = SIZE_PRINT;
		while (i++ < size) {
			std::clog << (*it).first << "(" << (*it).second << ") ";
			it++;
		}
		if (size < sub_lst.size())
			std::clog << "[...]";
		else if (size)
			std::clog << (*it).first << "(" << (*it).second << ")";
		std::clog << " }" << std::endl;
	};
};

#endif
