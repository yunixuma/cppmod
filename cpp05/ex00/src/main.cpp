/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/11 15:56:28 by ykosaka          ###   ########.fr       */
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
		catch (Bureaucrat & e)
		{
			/* handle exception */
			std::cerr << "An error caught" << std::endl;
		}
		std::clog << "\033[33m ---- ---- ---- ----\033[m" << std::endl;

	}

	return 0;
}
