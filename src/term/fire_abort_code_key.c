/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fire_abort_code_key.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 02:22:34 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/26 02:26:25 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

t_uc	fire_abort_code_key(char *key, char **line)
{
	if ((ft_strequ(key, "\x03")))
	{
		ft_term_send_command("cr");
		ft_term_send_command("do");
		if (*line)
			ft_strdel(line);
		if (g_term.cmd_len)
		{
			g_term.screen.cursor_pos[1] -= g_term.cmd_len;
			g_term.cmd_len = 0;
		}
		ft_bzero(key, 9);
		key[0] = '\r';
		return (SUCCESS);
	}
	return (FAIL);
}
