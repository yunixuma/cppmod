/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/16 17:23:34 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pb.h"

int	pb_display(t_pb *pb)
{
	size_t	n_remain;
	size_t	id;

	if (pb->n_reged > 8)
		n_remain = 8;
	else
		n_remain = pb->n_reged;
	while (n_remain)
	{
		id = pb->n_reged - n_remain;
		printf("%zu|%s|%s|%s\n", \
		id, pb->cont[id].first_name, \
		pb->cont[id].last_name, \
		pb->cont[id].nickname);
		n_remain--;
	}
	return (0);
}
