/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eraese_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzart <mozzart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:56:49 by mozzart           #+#    #+#             */
/*   Updated: 2020/12/25 01:31:15 by mozzart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void		ft_str_clear_char(char *str, t_us pos)
{
	size_t len;

	len = ft_strlen(str + pos);
	ft_memmove(str + pos, str + pos + 1, len);
}

void		ft_eraese_char(t_ttyfd *fd, char *buf)
{
	size_t	i;
	t_us	cursor_col;

	if (!buf)
		return ;
	i = ft_strlen(buf);
	cursor_col = g_term.screen.cursor_pos[1] - ft_strlen(ft_get_promt());
	(void)fd;
	if (i)
	{
		ft_term_send_command("dm");
		ft_term_send_command("dc");
		ft_term_send_command("ed");
		ft_str_clear_char(buf, cursor_col - 1);
		--g_term.cmd_len;
		--i;
		buf[i] = 0;
	}
}
