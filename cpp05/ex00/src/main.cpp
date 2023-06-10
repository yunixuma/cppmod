/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/11 01:52:46 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int	main()
{
	std::clog << "\033[35;43mSimple test\033[m" << std::endl;
	{
		Bureaucrat	bc("John", 150);
		try
		{
			/* do some stuff with bureaucrats */
			bc.decrementGrade();
		}
		catch (std::exception & e)
		{
			/* handle exception */
			std::cerr << "An error caught" << std::endl;
		}
		std::clog << "\033[33m ---- ---- ---- ----\033[m" << std::endl;

	}

	return 0;
}
