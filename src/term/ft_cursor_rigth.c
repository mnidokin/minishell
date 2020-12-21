/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor_rigth.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzart <mozzart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 00:19:07 by mozzart           #+#    #+#             */
/*   Updated: 2020/12/21 00:19:15 by mozzart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void	ft_cursor_right(void)
{
	size_t	line_len;

	line_len = ft_strlen(ft_get_promt()) + (size_t)g_term.cmd_len;
	if (g_term.screen.cursor_pos[1] - 1 >= line_len)
		return ;
	ft_term_send_command("nd");
	++g_term.screen.cursor_pos[1];
}
