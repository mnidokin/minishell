/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzart <mozzart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 00:23:00 by mozzart           #+#    #+#             */
/*   Updated: 2020/12/21 00:23:18 by mozzart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void	ft_clear_line(char *line)
{
	while (g_term.cmd_len)
	{
		ft_cursor_left();
		ft_eraese_char(&(g_term.fd), line);
	}
	ft_strdel(&line);
}
