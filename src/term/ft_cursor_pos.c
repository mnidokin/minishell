/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 21:51:15 by mozzart           #+#    #+#             */
/*   Updated: 2020/12/14 16:46:41 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void	ft_cursor_pos(t_ttyfd *fd, t_us *coords)
{
	char	buf[10];
	t_uc	i;

	write(fd->out, SLCT_GCCP, 4);
	read(fd->in, buf, 10);
	i = 2;
	coords[0] = ft_atoi(&buf[i]);
	while (buf[i] != ';' && i < 10)
		++i;
	coords[1] = ft_atoi(&buf[i + 1]);
	ft_bzero(buf, 10);
}
