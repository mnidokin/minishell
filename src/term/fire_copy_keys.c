/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fire_copy_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 03:15:11 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/26 05:56:13 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

static void	copy_word(t_uc dirrection, char **line)
{
	char	*end;
	char	*start;
	t_us	coords[2];
	size_t	line_len;

	line_len = ft_strlen(ft_get_promt()) + 1;
	ft_cursor_pos(&(g_term.fd), &(coords[0]));
	start = (*line) + (coords[1] - line_len);
	if (!(end = ft_get_word(*line, dirrection, start)))
		return ;
	if (start < end)
	{
		if (((ft_clipboard())->set(start, end)) != SUCCESS)
			ft_dprintf(g_term.fd.err, "%s\n", "COPY: Fail to copy to clipboard");
	}
	else
	{
		if (((ft_clipboard())->set(end, start)) != SUCCESS)
			ft_dprintf(g_term.fd.err, "%s\n", "COPY: Fail to copy to clipboard");
	}
}

t_uc	fire_copy_keys(char *key, char **line)
{
	if (ft_strequ(key, SLCT_CTRL_Y))
	{
		if (((ft_clipboard())->set(*line, NULL)) != SUCCESS)
			ft_dprintf(g_term.fd.err, "%s\n", "COPY: Fail to copy to clipboard");
		return (SUCCESS);
	}
	if (ft_strequ(key, SLCT_CTRL_GROUND) || ft_strequ(key, SLCT_ESC_C))
	{
		copy_word(SLCT_WORD_LEFT, line);
		return (SUCCESS);
	}		
	if (ft_strequ(key, SLCT_ESC_UC))
	{
		copy_word(SLCT_WORD_RIGHT, line);
		return (SUCCESS);
	}		
	return (FAIL);
}
