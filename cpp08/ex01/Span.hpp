/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/09 02:04:06 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <set>
# include <iterator>
# include <algorithm>
# include <exception>
# include <climits>

class Span
{
private:
	unsigned int		N_;
	std::multiset<int>	numbers_;
	unsigned int		shortest_span_val_;
	void				addNumberSub(int num);
public:
	Span(unsigned int N);
	Span(const Span& src);
	Span&	operator=(const Span& rhs);
	~Span();
	void	addNumber(int num);
	// template <typename T>
	// void	addNumber(const T& container);
	template <typename T>
	void	addNumber(const T& begin, const T& end) {
		if (this->numbers_.size() + std::distance(begin, end) > this->N_)
			throw Span::StoreFullException();
		for (T it = begin; it != end; it++)
			this->addNumber(*it);
	};
	unsigned int		shortestSpan(void) const;
	unsigned int		longestSpan(void) const;
	void	debug(void) const;
	class NoStoredException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
	class NoSpanException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
	class StoreFullException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
};

#endif
