/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrow_key_action.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:49:04 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/24 04:55:18 by tvanessa         ###   ########.fr       */
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

void		*increment(void **ptr)
{
	++(*ptr);
	return (*ptr);
}

void		*decrement(void **ptr)
{
	--(*ptr);
	return (*ptr);
}

char		*ft_get_word(char const *start, t_uc dirrectoin, char *current_pos)
{
	t_uc	loop_exit_flag;
	char	*whitespaces;

	loop_exit_flag = 1;
	whitespaces = " \t\n\r";
	if (!start || !current_pos)
		return (NULL);
	if ((start == current_pos && dirrectoin & SLCT_LEFT) ||
		(!*current_pos && dirrectoin & SLCT_RIGHT))
		return (NULL);
	if (dirrectoin & SLCT_RIGHT)
	{
		while (*current_pos && !ft_strchr(whitespaces, *current_pos))
			++current_pos;
		while (*current_pos && ft_strchr(whitespaces, *current_pos))
			++current_pos;
	}
	if (dirrectoin & SLCT_LEFT)
	{
		while (current_pos != start && ft_strchr(whitespaces, *(current_pos - 1)))
			--current_pos;
		while (current_pos != start && !ft_strchr(whitespaces, *(current_pos - 1)))
			--current_pos;
	}
	return (current_pos);
}

void		move_cursor(t_uc dirrection, char **line)
{
	void	(*move)(void);
	size_t	line_len;
	t_us	coords[2];
	char	*cursor_ptr;

	move = dirrection & SLCT_LEFT ? ft_cursor_left : ft_cursor_right;
	line_len = ft_strlen(ft_get_promt()) + 1;
	ft_cursor_pos(&(g_term.fd), &(coords[0]));
	if (dirrection & SLCT_LINE)
	{
		if (dirrection & SLCT_RIGHT)
			line_len += g_term.cmd_len;
		if ((dirrection & SLCT_RIGHT && coords[1] < line_len) || 
			(dirrection & SLCT_LEFT && coords[1] > line_len))
			ft_cursor_move_to(&(g_term.fd), coords[0], line_len);
		g_term.screen.cursor_pos[1] = line_len;
	}
	else if (dirrection & SLCT_WORD)
	{
		if (!(cursor_ptr = ft_get_word(*line, dirrection, ((*line) + (coords[1] - line_len)))))
			return ;
		ft_cursor_move_to(&(g_term.fd), coords[0], cursor_ptr - *line + line_len);
		g_term.screen.cursor_pos[1] = cursor_ptr - *line + line_len;
	}
	else
		move();
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
	if (dirrection & (SLCT_RIGHT | SLCT_LEFT) )
		move_cursor(dirrection, line);
		// ft_cursor_right();
	// if (dirrection == SLCT_LEFT)
	// 	ft_cursor_left();
}
