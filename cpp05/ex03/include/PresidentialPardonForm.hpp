/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/29 13:50:13 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTALPARDONFORM_HPP
# define PRESIDENTALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
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
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& src);
	PresidentialPardonForm&	operator=(const PresidentialPardonForm& rhs);
	~PresidentialPardonForm(void);
	void	beSigned(const Bureaucrat& bc);
	void	execute(Bureaucrat const & executor) const;
	AForm*	clone(void) const;
};

// std::ostream&	operator<<(std::ostream& stream, const PresidentialPardonForm& form);

#endif
