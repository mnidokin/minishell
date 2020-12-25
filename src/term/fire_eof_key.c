/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fire_eof_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 02:21:21 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/26 02:26:39 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

t_uc	fire_eof_key(char *key, char **line)
{
	if ((ft_strequ(key, "\x04")))
	{
		if (*line)
			return (SUCCESS);
		*line = ft_strdup("exit");
		g_term.cmd_len = 4;
		ft_bzero(key, 9);
		key[0] = '\r';
		fire_new_line_key("\r");
		return (SUCCESS);
	}
	return (FAIL);
}
