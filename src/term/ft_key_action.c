/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzart <mozzart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:06:14 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/20 22:03:07 by mozzart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

t_uc	ft_key_action(char *key, char **line)
{
	t_uc	dir;

	(void)line;
	if ((dir = is_arrow_key(key)))
	{
		ft_arrow_key_action(dir, line);
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
			ft_cursor_left();
		ft_eraese_char(&(g_term.fd), *line);
		return (1);
	}
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
		return (1);
	}
	if ((ft_strequ(key, "\x04")))
	{
		if (*line)
			ft_strdel(line);
		*line = ft_strdup("exit");
		g_term.cmd_len = 4;
		ft_bzero(key, 9);
		key[0] = '\r';
		return (1);
	}
	return (0);
}