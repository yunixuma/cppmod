/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/21 15:36:22 by ykosaka          ###   ########.fr       */
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
public:
	PmergeMe(void);
	~PmergeMe(void);
	PmergeMe(const PmergeMe& src);
	PmergeMe&			operator=(const PmergeMe& rhs);
	std::list<int>		split2List(const std::string& str);
	std::vector<int>	list2Vector(const std::list<int>& lst);
	clock_t				sort(std::list<int>& lst);
	clock_t				sort(std::vector<int>& vec);
	template <typename T>
	void	printList(T& lst) {
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
		else
			std::cout << *it;
		std::cout << std::endl;
	}
};

#endif
