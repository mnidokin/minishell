/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_send_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 19:22:13 by mozzart           #+#    #+#             */
/*   Updated: 2020/12/14 17:54:14 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		ft_putc(int c)
{
	int		ttyfd;
	ssize_t	res;

	// ttyfd = STDOUT_FILENO;
	// if (!isatty(ttyfd))
	// 	if ((ttyfd = open("/dev/tty", (O_WRONLY | O_NDELAY))) < 0)
	// 		return (1);
	ttyfd = g_term.fd.out;
	res = write(ttyfd, &c, 1);
	if (ttyfd > 2)
		close(ttyfd);
	return (res == 0);
}

t_uc	ft_term_send_command(char *cmd)
{
	char *str;

	if (!(str = tgetstr(cmd, NULL)))
		return (1);
	if (tputs(str, 1, ft_putc))
		return (2);
	return (0);
}
