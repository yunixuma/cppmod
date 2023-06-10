/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/11 01:57:32 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>
# include <string>

class Bureaucrat
{
private:
	std::string	name_;
	int						grade_;
public:
	Bureaucrat(const std::string& name, int grade = 100);
	Bureaucrat(const Bureaucrat& src);
	Bureaucrat&	operator=(const Bureaucrat& rhs);
	~Bureaucrat(void);
	const std::string&	getName(void) const;
	int					getGrade(void) const;
	void				incrementGrade(void);
	void				decrementGrade(void);
	int					GradeTooHighException();
	int					GradeTooLowException();
};

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& bc);

#endif
