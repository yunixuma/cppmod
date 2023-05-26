/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/15 18:09:21 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <phonebook.h>

int	 command(t_pb *pb, char *cmd) {
	if (!strncmp(cmd, "ADD", 4))
	{
		if (cont_set(&pb->cont[pb->n_reged % 8]))
		{
			pb->cont[pb->n_reged % 8].id = pb->n_reged;
			pb->n_reged++;
		}
	}
	else if (!strncmp(cmd, "SEARCH", 7))
		pb_display(pb);
	else if (!strncmp(cmd, "EXIT", 5))
		return (1);
	return (0);
}

int main(void)
{
	t_pb pb;
	char *cmd;

	while (true)
	{
		cmd = readline("Enter a command: ");
		if (cmd)
		{
			if (command(&pb, cmd))
				break;
			free(cmd);
		}
	}
	return (0);
}
