/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eraese_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:56:49 by mozzart           #+#    #+#             */
/*   Updated: 2020/12/14 19:41:34 by tvanessa         ###   ########.fr       */
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

	len = ft_strlen(str + pos - 1);
	ft_memmove(str + pos - 1, str, len);
}

void		ft_eraese_char(t_ttyfd *fd, char *buf)
{
	size_t	i;
	t_us	coords[2];

	i = ft_strlen(buf);
	if (i)
	{
		ft_term_send_command("dm");
		ft_term_send_command("dc");
		ft_term_send_command("ed");
		// clear_prev_char(fd, buf);
		ft_cursor_pos(fd, coords);
		ft_str_clear_char(buf, coords[1] - ft_strlen("$>"));

	}
	--i;
	buf[i] = 0;
}
