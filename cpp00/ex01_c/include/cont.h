/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/05/15 18:03:10 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <stddef.h>

typedef struct s_cont {
	size_t	id;
	char	*first_name;
	char	*last_name;
	char	*nickname;
	char	*phone_number;
	char	*darkest_secret;
}	t_cont;

int	cont_set(t_cont *cont);

#endif
