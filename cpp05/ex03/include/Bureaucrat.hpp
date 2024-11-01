/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/25 04:32:38 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>
# include <string>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
public:
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
private:
	const std::string	name_;
	int					grade_;
public:
	Bureaucrat(const std::string& name = "Pharaoh", int grade = 100);
	Bureaucrat(const Bureaucrat& src);
	Bureaucrat&	operator=(const Bureaucrat& rhs);
	~Bureaucrat(void);
	const std::string&	getName(void) const;
	int					getGrade(void) const;
	void				incrementGrade(void);
	void				decrementGrade(void);
	int					signForm(AForm& form);
	int					executeForm(AForm const & form);
};

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& bc);

#endif
