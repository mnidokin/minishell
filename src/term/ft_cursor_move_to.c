/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor_move_to.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 00:02:37 by mozzart           #+#    #+#             */
/*   Updated: 2020/12/14 16:46:30 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void	ft_cursor_move_to(t_ttyfd *fd, t_us row, t_us col)
{
	t_us	ccrd[2];
	char	*cmd;

	ft_cursor_pos(fd, &ccrd[0]);
	if (ccrd[0] == row && ccrd[1] == col)
		return ;
	cmd = tgoto("\E[%d;%dH", col, row);
	tputs(cmd, 1, ft_putc);
}
