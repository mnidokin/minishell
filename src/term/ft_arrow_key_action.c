/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrow_key_action.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:49:04 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/30 04:29:29 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

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

static void	ft_print_history_line(char *line)
{
	ft_term_deinit(&(g_term.fd), &(g_term.screen));
	if (line)
		ft_dprintf(g_term.fd.out, "%s", line);
	enter_icanon();
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
	if (dirrection & (SLCT_RIGHT | SLCT_LEFT))
		move_cursor(dirrection, line);
}
