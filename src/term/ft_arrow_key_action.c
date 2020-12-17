/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrow_key_action.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:49:04 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/17 05:41:04 by tvanessa         ###   ########.fr       */
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

void	ft_history_up(void)
{

}

void	ft_history_down(void)
{

}

void	ft_arrow_key_action(t_uc dirrection)
{
	if (dirrection == SLCT_PREV)
		ft_history_up();
	if (dirrection == SLCT_NEXT)
		ft_history_down();
	if (dirrection == SLCT_RIGHT)
		ft_cursor_right();
	if (dirrection == SLCT_LEFT)
		ft_cursor_left();
}