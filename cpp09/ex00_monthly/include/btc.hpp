/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btc.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/16 17:01:26 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTC_H
# define BTC_H

# include <iostream>
# include <fstream>

# define FILEPATH_DATA		    "data.csv"
# define INVALID_AMOUNT		    -0.01f
# define LOWER_LIMIT_AMOUNT	    0.0f
# define HIGHER_LIMIT_AMOUNT	1000.0f
# ifndef DEBUG_MODE
#  define DEBUG_MODE	        0
# endif

typedef std::pair<int, float>	t_pair;

#endif
