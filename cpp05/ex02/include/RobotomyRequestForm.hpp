/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/28 23:12:57 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

# include <iostream>
# include <unistd.h>
# include <cstdlib>
# include <ctime>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
public:
// 	class GradeTooHighException : public std::exception
// 	{
// 	public:
// 		virtual const char*	what() const throw();
// 	};
// 	class GradeTooLowException : public std::exception
// 	{
// 	public:
// 		virtual const char*	what() const throw();
// 	};
// 	class AlreadySignedException : public std::exception
// 	{
// 	public:
// 		virtual const char*	what() const throw();
// 	};
// 	class NotSignedException : public std::exception
// 	{
// 	public:
// 		virtual const char*	what() const throw();
// 	};
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& src);
	RobotomyRequestForm&	operator=(const RobotomyRequestForm& rhs);
	~RobotomyRequestForm(void);
	void	beSigned(const Bureaucrat& bc);
	void	execute(Bureaucrat const & executor) const;
};

// std::ostream&	operator<<(std::ostream& stream, const RobotomyRequestForm& form);

#endif
