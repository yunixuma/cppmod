/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/06/10 18:00:50 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

int	main()
{
	std::clog << "\033[35;43mSimple test\033[m" << std::endl;
	{
		Bureaucrat	bc;

		try
		{
			/* do some stuff with bureaucrats */
		}
		catch (std::exception & e)
		{
			/* handle exception */
		}
		std::clog << "\033[33m ---- ---- ---- ----\033[m" << std::endl;

	}

	return 0;
}
