/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fire_del_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 02:23:50 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/26 05:46:20 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

/* 
** @TODO: Make whole word deletion insted by char
*/
static void	erase_word(t_uc	dirrection, char **line)
{
	t_us	cursor_col;
	char	*del_key;

	cursor_col = g_term.screen.cursor_pos[1];
	move_cursor(dirrection, line);
	del_key = dirrection & SLCT_RIGHT ? SLCT_BSP : SLCT_DEL;
	while (cursor_col != g_term.screen.cursor_pos[1])
	{
		fire_del_keys(del_key, line);
		cursor_col > g_term.screen.cursor_pos[1] ? --cursor_col : 0;
	}	
}

t_uc	fire_del_keys(char *key, char **line)
{
	if ((ft_strequ(key, SLCT_BSP)) || ft_strequ(key, SLCT_DEL))
	{
		if ((ft_strequ(key, SLCT_BSP)))
			ft_cursor_left();
		ft_erase_char(&(g_term.fd), *line);
		return (SUCCESS);
	}
	if (ft_strequ(key, SLCT_CTRL_U) || ft_strequ(key, SLCT_CTRL_K) ||
		ft_strequ(key, SLCT_ESC_UD))
	{
		ft_clear_line(*line);
		return (SUCCESS);
	}
	if (ft_strequ(key, SLCT_CTRL_W) || ft_strequ(key, SLCT_ESC_DB))
	{
		erase_word(SLCT_WORD_LEFT, line);
		return (SUCCESS);
	}
	if (ft_strequ(key, SLCT_ESC_DF))
	{
		erase_word(SLCT_WORD_RIGHT, line);
		return (SUCCESS);
	}
	return (FAIL);
}
