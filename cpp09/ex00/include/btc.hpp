/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btc.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/10/13 13:41:34 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTC_H
# define BTC_H

# include <iostream>
# include <fstream>

# define FILEPATH_DATA		"data.csv"
# define INVALID_AMOUNT		-0.01f
# define TOO_LARGE_AMOUNT	21000000.0f
# ifndef DEBUG_MODE
#  define DEBUG_MODE	0
# endif

typedef std::pair<int, float>	t_pair;

#endif
