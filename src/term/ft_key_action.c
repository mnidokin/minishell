/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:06:14 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/14 19:23:28 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

t_uc	ft_key_action(char *key, char *line)
{
	t_uc	dir;

	(void)line;
	if ((dir = is_arrow_key(key)))
	{
		ft_arrow_key_action(dir);
		return (1);
	}
	if ((ft_strequ(key, "\r")))
	{
		ft_term_send_command("cr");
		return (!ft_term_send_command("do"));
	}
	if ((ft_strequ(key, SLCT_BSP)) || ft_strequ(key, SLCT_DEL))
	{
		if ((ft_strequ(key, SLCT_BSP)))
			ft_term_send_command("le");
		ft_eraese_char(&(g_term.fd), line);
	}
	return (0);
}