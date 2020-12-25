/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fire_del_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 02:23:50 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/26 02:26:05 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

t_uc	fire_del_keys(char *key, char **line)
{
	if ((ft_strequ(key, SLCT_BSP)) || ft_strequ(key, SLCT_DEL))
	{
		if ((ft_strequ(key, SLCT_BSP)))
			ft_cursor_left();
		ft_eraese_char(&(g_term.fd), *line);
		return (SUCCESS);
	}
	return (FAIL);
}
