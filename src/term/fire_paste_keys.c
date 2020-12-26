/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fire_paste_keys.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 04:19:22 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/26 05:02:33 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

static void	print_char(char *c)
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

static void	addchr(char **str, char c, int len, t_us pos)
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

t_uc		fire_paste_keys(char *key, char **line)
{
	char	*paste;
	char	c[2];

	if (!ft_strequ(key, SLCT_ESC_V))
		return (FAIL);
	paste = (ft_clipboard())->get();
	c[1] = 0;
	if (!paste)
		return (SUCCESS);
	while (*paste)
	{
		addchr(line, *paste, g_term.cmd_len, g_term.screen.cursor_pos[1]
						- ft_strlen(ft_get_promt()) - 1);
		c[0] = *paste;
		print_char((char*)(c));
		++paste;
	}
	return (SUCCESS);
}