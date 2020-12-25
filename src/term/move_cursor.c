/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 01:53:57 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/26 02:15:51 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

static void	move_by_word(t_uc dirrection, char **line)
{
	size_t	line_len;
	t_us	coords[2];

	line_len = ft_strlen(ft_get_promt()) + 1;
	ft_cursor_pos(&(g_term.fd), &(coords[0]));
	if (dirrection & SLCT_RIGHT)
		line_len += g_term.cmd_len;
	if ((dirrection & SLCT_RIGHT && coords[1] < line_len) ||
		(dirrection & SLCT_LEFT && coords[1] > line_len))
		ft_cursor_move_to(&(g_term.fd), coords[0], line_len);
	g_term.screen.cursor_pos[1] = line_len;
}

static void	move_through_line(t_uc dirrection, char **line)
{
	char	*cursor_ptr;
	t_us	coords[2];
	size_t	line_len;
	size_t	cursor_pos;

	line_len = ft_strlen(ft_get_promt()) + 1;
	ft_cursor_pos(&(g_term.fd), &(coords[0]));
	cursor_ptr = (*line) + (coords[1] - line_len);
	if (!(cursor_ptr = ft_get_word(*line, dirrection, cursor_ptr)))
		return ;
	cursor_pos = cursor_ptr - *line + line_len;
	ft_cursor_move_to(&(g_term.fd), coords[0], cursor_pos);
	g_term.screen.cursor_pos[1] = cursor_pos;
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
		move_by_word(dirrection, line);
	else if (dirrection & SLCT_WORD)
		move_through_line(dirrection, line);
	else
		move();
}
