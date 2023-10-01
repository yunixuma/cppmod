/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/01 15:28:18 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <list>
# include <algorithm>
# include <exception>

class Span
{
private:
	unsigned int	N_;
	std::list<int>	numbers_;
public:
	Span(int N);
	Span(const Span& src);
	Span&	operator=(const Span& rhs);
	~Span();
	void	addNumber(int num);
	int		shortestSpan(void) const;
	int		longestSpan(void) const;
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
