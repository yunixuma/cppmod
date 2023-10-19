/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/20 04:45:51 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP_HPP
# include <list>
# include <vector>
# include <ctime>
// # include <stack>
# include <iostream>
# include <sstream>
# include <typeinfo>
# include <exception>
# include <climits>

class PmergeMe
{
private:
	// float	time_;
public:
	PmergeMe(void);
	~PmergeMe(void);
	PmergeMe(const PmergeMe& src);
	PmergeMe&			operator=(const PmergeMe& rhs);
	std::list<int>		split2List(const std::string& str);
	std::vector<int>	list2Vector(const std::list<int>& lst);
	clock_t				sort(std::list<int>& lst);
	clock_t				sort(std::vector<int>& vec);
};

#endif
