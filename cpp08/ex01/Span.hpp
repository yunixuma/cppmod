/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/04 22:19:26 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <list>
# include <algorithm>
# include <exception>
# include <climits>

class Span
{
private:
	unsigned int	N_;
	std::list<int>	numbers_;
	void	addNumberSub(int num);
public:
	Span(int N);
	Span(const Span& src);
	Span&	operator=(const Span& rhs);
	~Span();
	void	addNumber(int num);
	void	addNumber(int num1, int num2);
	int		shortestSpan(void) const;
	int		longestSpan(void) const;
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
