/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/15 18:08:23 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cont.h"

# include <readline/readline.h>
# include <readline/history.h>

int	cont_set(t_cont *cont)
{
	cont->first_name = readline("Enter first name: ");
	cont->last_name = readline("Enter last name: ");
	cont->nickname = readline("Enter nickname: ");
	cont->phone_number = readline("Enter phone number: ");
	cont->darkest_secret = readline("Enter darkest secret: ");
	return (1);
}
