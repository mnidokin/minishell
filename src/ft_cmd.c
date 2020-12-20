/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzart <mozzart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:56:49 by mnidokin          #+#    #+#             */
/*   Updated: 2020/12/20 19:14:16 by mozzart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cmd_read(char **cmd)
{
	char	c[9];
	char	err;
	char	*res;

	g_term.cmd_len = 0;
	if ((err = ft_term_init(&g_term.fd, &g_term.screen)))
	{
		if (err > 6)
			ft_term_deinit(&g_term.fd, &g_term.screen);
		exit(err);
	}
	while (1)
	{
		ft_bzero(c, 9);
		if (!(read(g_term.fd.in, c, 8)))
			break ;
		if ((ft_is_spec_key((char*)c) && ft_key_action((char*)c, cmd)) || c[0] == '\e')
		{
			if (ft_strequ(c, "\r"))
			{
				if (g_term.cmd_len == 0)
					*cmd = NULL;
				break ;
			}
			continue;
		}
		ft_str_addchr(cmd, c[0], g_term.cmd_len, g_term.screen.cursor_pos[1] - ft_strlen(ft_get_promt()) - 1);
		if (g_term.cmd_len > g_term.screen.cursor_pos[1] - ft_strlen(ft_get_promt()) - 1)
			ft_term_send_command("im");
		ft_dprintf(g_term.fd.out, "%s", c);
		if (g_term.cmd_len > g_term.screen.cursor_pos[1] - ft_strlen(ft_get_promt()) - 1)
			ft_term_send_command("ie");
		++g_term.screen.cursor_pos[1];
		++g_term.cmd_len;
	}
	if (*cmd)
	{
		res = *cmd;
		*cmd = ft_strtrim(res);
		ft_strdel(&res);
		(ft_history(NULL))->add(*cmd);
		ft_history_save();
	}
	ft_bzero(c, 9);
	ft_term_deinit(&g_term.fd, &g_term.screen);
}

void	ft_str_addchr(char **str, char c, int len, t_us pos)
{
	char *tmp;

	if (*str && !(tmp = ft_strdup(*str)))
		exit(2);
	else if (!*str)
	{
		*str = ft_strnew(1);
		(*str)[0] = c;
		return ;
	}
	ft_strdel(&(*str));
	if (!(*str = ft_strnew(len + 1)))
		exit(2);
	ft_strncpy((*str), tmp, len);
	ft_strdel(&tmp);
	if (pos < len)
		ft_memmove(*str + pos + 1, *str + pos, len);
	(*str)[pos] = c;
}
