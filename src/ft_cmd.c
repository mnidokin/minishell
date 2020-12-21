/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzart <mozzart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:56:49 by mnidokin          #+#    #+#             */
/*   Updated: 2020/12/21 01:26:46 by mozzart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	enter_icanon(void)
{
	t_uc	err;

	if ((err = ft_term_init(&g_term.fd, &g_term.screen)))
	{
		if (err > 6)
			ft_term_deinit(&g_term.fd, &g_term.screen);
		exit(err);
	}
}

static t_uc	is_spec_key(char *c, char **cmd)
{
	if ((ft_is_spec_key((char*)c) && ft_key_action((char*)c, cmd))
		|| c[0] == '\e')
	{
		if (ft_strequ(c, "\r"))
		{
			if (g_term.cmd_len == 0)
				*cmd = NULL;
			return (2);
		}
		return (1);
	}
	return (0);
}

static void	ft_print_input_char(char *c)
{
	if (g_term.cmd_len > g_term.screen.cursor_pos[1] -
		ft_strlen(ft_get_promt()) - 1)
		ft_term_send_command("im");
	ft_dprintf(g_term.fd.out, "%s", c);
	if (g_term.cmd_len > g_term.screen.cursor_pos[1] -
		ft_strlen(ft_get_promt()) - 1)
		ft_term_send_command("ie");
	++g_term.screen.cursor_pos[1];
	++g_term.cmd_len;
}

static void	finish_read_input(char **cmd)
{
	char	*res;

	if (*cmd)
	{
		res = *cmd;
		*cmd = ft_strtrim(res);
		ft_strdel(&res);
		(ft_history(NULL))->add(*cmd);
		ft_history_save();
	}
	ft_term_deinit(&g_term.fd, &g_term.screen);
}

void		ft_cmd_read(char **cmd)
{
	char	c[9];
	char	err;

	g_term.cmd_len = 0;
	enter_icanon();
	while (1)
	{
		ft_bzero(c, 9);
		if (!(read(g_term.fd.in, c, 8)))
			break ;
		if ((err = is_spec_key((char*)c, cmd)) && err == 2)
			break ;
		else if (err == 1)
			continue;
		ft_str_addchr(cmd, c[0], g_term.cmd_len, g_term.screen.cursor_pos[1]
						- ft_strlen(ft_get_promt()) - 1);
		ft_print_input_char((char*)c);
	}
	finish_read_input(cmd);
	ft_bzero(c, 9);
}
