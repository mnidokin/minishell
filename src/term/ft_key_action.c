/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzart <mozzart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:06:14 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/25 20:07:28 by mozzart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

static t_uc	fire_arrow_key(char *key, char **line)
{
	t_uc	dir;

	if (!(dir = is_arrow_key(key)))
		return (FAIL);
	ft_arrow_key_action(dir, line);
	return (SUCCESS);
}

static t_uc	fire_new_line_key(char *key)
{
	if (!(ft_strequ(key, "\r")))
		return (FAIL);
	ft_term_send_command("cr");
	ft_term_send_command("do");
	return (SUCCESS);
}

static t_uc	fire_eof_key(char *key, char **line)
{
	if ((ft_strequ(key, "\x04")))
	{
		if (*line)
			return (SUCCESS);
		*line = ft_strdup("exit");
		g_term.cmd_len = 4;
		ft_bzero(key, 9);
		key[0] = '\r';
		fire_new_line_key("\r");
		return (SUCCESS);
	}
	return (FAIL);
}

static t_uc	fire_abort_code_key(char *key, char **line)
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

static t_uc	fire_del_keys(char *key, char **line)
{
	if ((ft_strequ(key, SLCT_BSP)) || ft_strequ(key, SLCT_DEL))
	{
		if ((ft_strequ(key, SLCT_BSP)))
			ft_cursor_left();
		ft_eraese_char(&(g_term.fd), *line);
		return (SUCCESS);
	}
	return (FAIL);
}

t_uc		ft_key_action(char *key, char **line)
{
	if (fire_arrow_key(key, line) == SUCCESS)
		return (1);
	if ((fire_new_line_key(key)) == SUCCESS)
		return (1);
	if (fire_del_keys(key, line) == SUCCESS)
		return (1);
	if (fire_copy_keys(key, line) == SUCCESS)
		return (1);
	if (fire_cut_keys(key, line) == SUCCESS)
		return (1);
	if (fire_paste_keys(key, line) == SUCCESS)
		return (1);
	if ((fire_abort_code_key(key, line)) == SUCCESS)
		return (1);
	if ((fire_eof_key(key, line)) == SUCCESS)
		return (1);
	return (0);
}
