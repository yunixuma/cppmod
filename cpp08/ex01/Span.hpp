/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/09/29 22:44:04 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <list>
// # include <map>
# include <algorithm>
# include <exception>

class Span
{
private:
	unsigned int	N;
	std::list<int>	numbers_;
public:
	Span(const int N);
	Span(const Span& src);
	Span&	operator=(const Span& rhs);
	~Span();
	void	addNumber(int num);
	int		shortestSpan(void) const;
	int		longestSpan(void) const;
	class NoSpanException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
	class NoNumbersException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
};

#endif
