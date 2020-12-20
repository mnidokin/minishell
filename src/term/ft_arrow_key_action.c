/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrow_key_action.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzart <mozzart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:49:04 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/21 00:28:00 by mozzart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

static void	ft_print_history_line(char *line)
{
	if (line)
		ft_dprintf(g_term.fd.out, "%s", line);
	g_term.cmd_len = ft_strlen(line);
	g_term.screen.cursor_pos[1] += g_term.cmd_len;
}

void		ft_arrow_key_action(t_uc dirrection, char **line)
{
	char *old_line;

	if (dirrection & (SLCT_PREV | SLCT_NEXT))
	{
		old_line = *line;
		if (dirrection == SLCT_PREV)
			ft_history_up(line);
		if (dirrection == SLCT_NEXT)
			ft_history_down(line);
		if (*line != old_line)
		{
			ft_clear_line(old_line);
			ft_print_history_line(*line);
		}
	}
	if (dirrection == SLCT_RIGHT)
		ft_cursor_right();
	if (dirrection == SLCT_LEFT)
		ft_cursor_left();
}
