/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzart <mozzart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 00:18:45 by mozzart           #+#    #+#             */
/*   Updated: 2020/12/21 00:18:47 by mozzart          ###   ########.fr       */
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
