/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eraese_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:56:49 by mozzart           #+#    #+#             */
/*   Updated: 2020/12/17 06:04:44 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

// static void	clear_prev_char(t_ttyfd *fd, char *heystack)
// {

// 	ft_term_send_command("le");
// 	ft_term_send_command("dm");
// 	ft_term_send_command("dc");
// 	ft_term_send_command("ed");
// }

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

	i = ft_strlen(buf);
	cursor_col = g_term.screen.cursor_pos[1] - ft_strlen(ft_get_promt());
	(void)fd;
	if (i)
	{
		ft_term_send_command("dm");
		ft_term_send_command("dc");
		ft_term_send_command("ed");
		// clear_prev_char(fd, buf);
		// ft_cursor_pos(fd, coords);
		ft_str_clear_char(buf, cursor_col - 1);
		--g_term.cmd_len;
	}
	--i;
	buf[i] = 0;
}
