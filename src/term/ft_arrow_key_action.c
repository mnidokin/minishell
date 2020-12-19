/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrow_key_action.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:49:04 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/19 23:09:32 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void	ft_cursor_left(void)
{
	if (g_term.screen.cursor_pos[1] - 1 <= ft_strlen(ft_get_promt()))
		return ;
	ft_term_send_command("le");
	--g_term.screen.cursor_pos[1];
}

void	ft_cursor_right(void)
{
	size_t	line_len;

	line_len = ft_strlen(ft_get_promt()) + (size_t)g_term.cmd_len;
	if (g_term.screen.cursor_pos[1] - 1 >= line_len)
		return ;
	ft_term_send_command("nd");
	++g_term.screen.cursor_pos[1];
}

void	ft_history_up(char **line)
{
	t_history	*hist;
	char		*hist_data;

	if (!(hist = ft_history(NULL)))
		return ;
	if (hist->current->prev)
	{
		hist_data = (char*)(hist->current->prev->content);
		if (!(*line = ft_strdup(hist_data)))
			return ;
		hist->current = hist->current->prev;
	}
}

void	ft_history_down(char **line)
{
	t_history	*hist;
	char		*hist_data;

	if (!(hist = ft_history(NULL)))
		return ;
	if (hist->current->next && hist->current->next->content)
	{
		hist_data = (char*)(hist->current->next->content);
		// ft_strdel(line);
		if (!(*line = ft_strdup(hist_data)))
			return ;
		hist->current = hist->current->next;
	}
	else
		*line = ft_strnew(1);
}

void	ft_clear_line(char *line)
{
	while (g_term.cmd_len)
	{
		ft_cursor_left();
		ft_eraese_char(&(g_term.fd), line);
		// --g_term.cmd_len;
	}
	ft_strdel(&line);
}

void		ft_print_history_line(char *line)
{
	ft_dprintf(g_term.fd.out, "%s", line);
	g_term.cmd_len = ft_strlen(line);
	g_term.screen.cursor_pos[1] += g_term.cmd_len;
}

void	ft_arrow_key_action(t_uc dirrection, char **line)
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