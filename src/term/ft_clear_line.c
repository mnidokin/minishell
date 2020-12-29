/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 00:23:00 by mozzart           #+#    #+#             */
/*   Updated: 2020/12/29 02:34:53 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void	ft_clear_line(char *line)
{
	t_us	coords[2];

	ft_cursor_pos(&(g_term.fd), &(coords[0]));
	ft_cursor_move_to(&(g_term.fd), coords[0], 0);
	ft_term_send_command("ce");
	ft_printf("%s", ft_get_promt()),
	ft_strclr(line);
}
