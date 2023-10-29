/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/29 11:00:54 by Yoshihiro K      ###   ########.fr       */
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

typedef std::list<int>::iterator	t_lst_it;
typedef std::vector<int>::iterator	t_vec_it;

class PmergeMe
{
private:
	// float	time_;
	void				move(std::vector<int>& vec, \
		t_vec_it& pos, t_vec_it& first, t_vec_it& last);
	void				sort(std::list<int>& lst);
	void				sort(std::vector<int>& vec);
	void				sortSub(std::vector<int>& vec, \
		size_t i, size_t j);
	void 				sortMerge(std::vector<int>& vec, \
		size_t l, size_t m, size_t r);
public:
	PmergeMe(void);
	~PmergeMe(void);
	PmergeMe(const PmergeMe& src);
	PmergeMe&			operator=(const PmergeMe& rhs);
	std::list<int>		split2List(const std::string& str);
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
	void				printList(T& lst) {
		typename T::iterator	it = lst.begin();
		size_t					size = lst.size();
		size_t					i = 1;
		std::clog << "size: " << size << std::endl;
		if (size > SIZE_PRINT)
			size = SIZE_PRINT;
		while (i++ < size) {
			std::cout << *it << " ";
			it++;
		}
		if (size < lst.size())
			std::cout << "[...]";
		else if (size)
			std::cout << *it;
		std::cout << std::endl;
	};
};

#endif
